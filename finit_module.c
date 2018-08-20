#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>

// xxd -i x.ko > x_ko.h
#include "x_ko.h"

int main(int ac, char **av)
{
    int  x, y;
    char name[256];

    // no glibc wrapper for this.. 
    x = syscall(SYS_memfd_create, "x", NULL);
    write(x, x_ko, x_ko_len);

    unlink("/tmp/x.ko");
    sprintf(name, "/proc/%d/fd/%d", getpid(), x);
    symlink(name, "/tmp/x.ko");
    y = open("/tmp/x.ko", O_RDONLY);
    // nor this.. 
    syscall(SYS_finit_module, y, "", NULL);

    close(y);
    return 0;
}
