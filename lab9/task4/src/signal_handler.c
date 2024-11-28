#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

const char *signal_to_string(int sig)
{
    if (sig == SIGRTMIN)
    {
        return "Real-time signal 0";
    }
    else if (sig == SIGTERM)
    {
        return "Termination signal";
    }
    else
    {
        return "Unknown signal";
    }
}

void realtime_signal_handler(int sig, siginfo_t *info, void *context)
{
    printf("Child process: Received signal %d (%s) with value %d\n",
           sig,
           signal_to_string(sig),
           info->si_value.sival_int);
}

void termination_handler(int sig)
{
    printf("Child process: Received termination signal (%s). Exiting.\n", signal_to_string(sig));
    exit(0);
}

void child_process_logic()
{
    struct sigaction sa_realtime = {0};
    sa_realtime.sa_sigaction = realtime_signal_handler;
    sa_realtime.sa_flags = SA_SIGINFO;

    struct sigaction sa_terminate = {0};
    sa_terminate.sa_handler = termination_handler;

    sigaction(SIGRTMIN, &sa_realtime, NULL);
    sigaction(SIGTERM, &sa_terminate, NULL);

    printf("Child process: Ready to receive signals.\n");

    while (1)
    {
        pause();
    }
}
