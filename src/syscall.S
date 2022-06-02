/*

This is a simplified version of glibc/sysdeps/unix/sysv/linux/x86_64/syscall.S
which doesn't jump to an error handler if rax contains an error code.

*/

.global syscall
syscall:
    movq %rdi, %rax     /* Syscall number -> rax.  */
    movq %rsi, %rdi     /* shift arg1 - arg5.  */
    movq %rdx, %rsi
    movq %rcx, %rdx
    movq %r8, %r10
    movq %r9, %r8
    movq 8(%rsp),%r9    /* arg6 is on the stack.  */
    syscall             /* Do the system call.  */
    ret                 /* Return to caller.  */
