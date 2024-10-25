#include <stdio.h>
#include <unistd.h>
#include "process_info.h"

void print_process_info(int info)
{
    if (info & 1)
    {
        printf("Process ID (PID): %d\n", getpid());
    }

    if (info & 2)
    {
        printf("Parent Process ID (PPID): %d\n", getppid());
    }

    if (info & 4)
    {
        printf("User ID (UID): %d\n", getuid());
    }
    
    if (info & 8)
    {
        printf("Group ID (GID): %d\n", getgid());
    }
}
