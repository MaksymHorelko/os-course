#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "signal_handlers.h"

int main()
{
    setup_signal_handlers();

    printf("PID: %d\n", getpid());
    printf("Waiting for signals... (use kill to send signals)\n");

    while (1)
    {
        pause();
    }

    return 0;
}
