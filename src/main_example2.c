#include "syscalls.h"

int main(void)
{
	const char hello[] = "Hello from shellcode!\n";

	my_write(1, hello, sizeof(hello));

	return 42;
}
