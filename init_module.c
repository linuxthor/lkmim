#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

// xxd -i x.ko > x_ko.h
#include "x_ko.h"

int main(int ac, char **av)
{
    char *mem;

    mem = malloc(x_ko_len);
    memcpy(mem, x_ko, x_ko_len);

    // no glibc wrapper for this.. 
    syscall(SYS_init_module, mem, x_ko_len, "");

    free(mem);
    return 0;
}
