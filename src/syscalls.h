#pragma once

#include <sys/types.h>

// Syscall numbers
#include <asm/unistd.h>

#include <linux/openat2.h>

ssize_t my_write(int fd, const void *buf, size_t size);
ssize_t my_read(int fd, const void *buf, size_t size);
ssize_t my_open(const void *path, int flags, mode_t mode);
ssize_t my_openat(int dirfd, const void *pathname, int flags, mode_t mode);
ssize_t my_openat2(int dirfd, const char *pathname, struct open_how *how, size_t size);
ssize_t my_kill(pid_t fd, int sig);
