#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

// Add arguments here if you want
typedef int(*shellcode_t)();

int main(int argc, char const *argv[])
{
    int size;
    struct stat s;
    const char * file_name = argv[1];
    int fd = open (argv[1], O_RDONLY);

    // Get the size of the file
    int status = fstat (fd, & s);
    size = s.st_size;

    shellcode_t shellcode = (shellcode_t) mmap (0, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd, 0);
    if (shellcode == MAP_FAILED) {
        fprintf(stderr, "mmap failed\n");
        return -1;
    }

    fprintf(stderr, "Executing shellcode @%p, size=%ld\n\n", shellcode, size);

    int ret = shellcode();

    fprintf(stderr, "\nShellcode returned %ld\n\n", ret);

    return 0;
}
