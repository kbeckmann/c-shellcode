BUILD_DIR := build
TARGET := out
TARGET_ELF_PATH := $(BUILD_DIR)/$(TARGET).elf
TARGET_BIN_PATH := $(BUILD_DIR)/$(TARGET).bin

# CFLAGS += -O0
CFLAGS += -Os

CFLAGS += -ggdb -flto -fdata-sections -ffunction-sections -fno-stack-protector -fno-common -nostartfiles -fomit-frame-pointer -fPIE -static

ASFLAGS :=

LDFLAGS += -flto -fdata-sections -ffunction-sections -fno-common -nostartfiles -fPIE -static
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref
LDFLAGS += -T shellcode.ld


C_SOURCES = \
	main_example3.c \
	syscalls.c \

ASM_SOURCES = \
	startup.S \
	syscall.S

OBJS += $(ASM_SOURCES:%=$(BUILD_DIR)/%.o)
OBJS += $(C_SOURCES:%=$(BUILD_DIR)/%.o)


all: $(TARGET_BIN_PATH)

clean:
	rm -rf $(BUILD_DIR)

# assembly
$(BUILD_DIR)/%.S.o: %.S
	mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -c -o $@ $<


# c source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET_ELF_PATH) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)


$(TARGET_BIN_PATH) : $(TARGET_ELF_PATH)
	objcopy -O binary -S \
		-j .text -j .rodata -j .preinit_array \
		-j .init_array -j .fini_array -j .data \
		$(TARGET_ELF_PATH) $(TARGET_BIN_PATH)
