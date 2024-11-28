#include <stdio.h>
#include <signal.h>
#include "sync.h"

void sigusr1_handler(int sig)
{
}

void setup_signal_handlers()
{
    struct sigaction sa;
    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
}