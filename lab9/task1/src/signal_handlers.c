#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "signal_handlers.h"

void signal_handler(int sig)
{
    switch (sig)
    {
    case SIGINT:
        printf("Caught signal SIGINT (Ctrl+C)\n");
        break;
    case SIGTERM:
        printf("Caught signal SIGTERM\n");
        break;
    case SIGUSR1:
        printf("Caught signal SIGUSR1. Exiting...\n");
        exit(0);
        break;
    default:
        break;
    }
}

void setup_signal_handlers()
{
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    sa.sa_handler = SIG_DFL;
    sigaction(SIGPROF, &sa, NULL);

    sa.sa_handler = SIG_IGN;
    sigaction(SIGHUP, &sa, NULL);
}
