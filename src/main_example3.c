#include <stdint.h>

#include "syscalls.h"

static const char hello[] = "Hello from shellcode!\n";

static void write_hex(int fd, uint32_t byte)
{
	uint8_t buf[2];
	uint8_t nibble = (byte >> 4) & 0x0f;

	buf[0] = (nibble > 9) ? 0x37 + nibble : 0x30 + nibble;

	nibble = byte & 0x0f;
	buf[1] = (nibble > 9) ? 0x37 + nibble : 0x30 + nibble;

	my_write(fd, buf, sizeof(buf));
}


void hexdump_fd(int fd, const void* data, size_t size)
{
	size_t i;
	size_t j = 0;
	const uint8_t *data_bytes = (const uint8_t *) data;

	for (i = 0; i < size; ++i) {
		if (j % 16 == 0) {
			uint64_t addr = ((uint64_t) data) + i;
			my_write(fd, "\n0x", 1);

			for (int k = 7; k >= 0; k--) {
				write_hex(fd, (addr >> (8*k)) & 0xff);
			}
		
			my_write(fd, ": ", 2);
		}

		write_hex(fd, data_bytes[i]);
		my_write(fd, " ", 1);
		j++;
	}
}


int main(void)
{
	int stack_var = 42;
	char stack_hello[] = "Hello from the stack!\n";

	my_write(1, hello, sizeof(hello));

	my_write(1, stack_hello, sizeof(stack_hello));

	hexdump_fd(1, &stack_var, 64);

	return stack_var;
}
