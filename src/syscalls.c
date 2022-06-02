#include "syscalls.h"
#include "syscall.h"


ssize_t my_write(int fd, const void *buf, size_t size)
{
	return syscall(__NR_write, fd, buf, size);
}

ssize_t my_read(int fd, const void *buf, size_t size)
{
	return syscall(__NR_read, fd, buf, size);
}

ssize_t my_open(const void *path, int flags, mode_t mode)
{
	return syscall(__NR_open, path, flags, mode);
}

ssize_t my_openat(int dirfd, const void *pathname, int flags, mode_t mode)
{
	return syscall(__NR_openat, dirfd, pathname, flags, mode);
}

ssize_t my_openat2(int dirfd, const char *pathname, struct open_how *how, size_t size)
{
	return syscall(__NR_openat2, dirfd, pathname, how, size);
}

ssize_t my_kill(pid_t fd, int sig)
{
	return syscall(__NR_kill, fd, sig);
}
