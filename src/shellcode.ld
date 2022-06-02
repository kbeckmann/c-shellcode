/* Entry Point */
ENTRY(_start)

__BINARY_LENGTH__ = 1024K;

MEMORY
{
  BINARY (xrw) : ORIGIN = 0x00000000, LENGTH = __BINARY_LENGTH__
}

SECTIONS
{
  .text :
  {
    _stext = .;
    . = ALIGN(4);

    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;
  } >BINARY

  .rodata :
  {
    _srodata = .;
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
    _erodata = .;
  } >BINARY

  .preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >BINARY

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >BINARY

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >BINARY

  /* Initialized data section */
  .data :
  {
    _sdata = .;
    . = ALIGN(4);
    *(.data)
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } >BINARY

  /* Uninitialized data section */
  .bss :
  {
    _sbss = .;
    . = ALIGN(4);
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } >BINARY


  /DISCARD/ : {
    *(.note*)
    *(.eh_frame)
  }

}
