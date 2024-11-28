#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

void realtime_signal_handler(int sig, siginfo_t *info, void *context);
void termination_handler(int sig);
void child_process_logic();

#endif
