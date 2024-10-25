#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

pid_t create_child_process();

void terminate_child_processes(pid_t *child_pids, int num_children);

void display_process_info(pid_t *child_pids, int num_children);

#endif
