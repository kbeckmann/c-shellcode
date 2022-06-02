/*

$ as -c startup.s -o startup.o

*/

.global _start
.section .text

_start:

  push %r12
  push %r10
  push %r9
  push %r8
  push %rbp

  call main

  pop %rbp
  pop %r8
  pop %r9
  pop %r10
  pop %r12
  ret
