#include <stdio.h>
#include <stdlib.h>
#include "process_info.h"

int main(int argc, char *argv[])
{
    int info = 0;

    if (argc > 1)
    {
        info = atoi(argv[1]);
    }
    
    else
    {
        printf("Usage: %s <info_flag>\n", argv[0]);
        printf("Info flag options:\n");
        printf("  1 - PID\n  2 - PPID\n  4 - UID\n  8 - GID\n");
        printf("  Combine flags to display multiple values (e.g., 3 for PID and PPID).\n");
        return 1;
    }

    print_process_info(info);
    return 0;
}
