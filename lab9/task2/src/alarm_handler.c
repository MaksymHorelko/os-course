#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "alarm_handler.h"

static const char *alarm_message = NULL;

void alarm_signal_handler(int sig)
{
    if (alarm_message != NULL)
    {
        printf("\nAlarm! Message: %s\n", alarm_message);
    }
    exit(EXIT_SUCCESS);
}

void run_alarm(int seconds, const char *message)
{
    alarm_message = message;

    signal(SIGALRM, alarm_signal_handler);

    alarm(seconds);

    printf("Child process is waiting for the alarm...\n");
    
    pause();
}
