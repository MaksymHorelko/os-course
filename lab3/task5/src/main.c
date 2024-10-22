#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <sys/wait.h>
#include "main.h"

#define DEFAULT_FILE_NAME "output_file"
#define DEFAULT_NUM_PROCS 1

void run_child_process(int child_num)
{
    char child_num_str[10];
    sprintf(child_num_str, "%d", child_num);

    execl("./bin/child", "./bin/child", child_num_str, NULL);

    perror("Error executing child process");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    char *file_name = NULL;
    int num_procs = DEFAULT_NUM_PROCS;

    struct option long_opts[] = {
        {"file", required_argument, 0, 'f'},
        {"number", required_argument, 0, 'n'},
        {0, 0, 0, 0}};

    int opt;
    while ((opt = getopt_long(argc, argv, "f:n:", long_opts, NULL)) != -1)
    {
        switch (opt)
        {
        case 'f':
            file_name = optarg;
            break;
        case 'n':
            num_procs = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s [-f|--file FILE_NAME] [-n|--number NUM_PROCS]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (file_name)
    {
        setenv("FILE_NAME", file_name, 1);
        printf("Environment variable FILE_NAME set to %s\n", file_name);
    }
    else
    {
        printf("Environment variable FILE_NAME not set\n");
    }

    for (int i = 0; i < num_procs; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            run_child_process(i + 1);
        }
        else if (pid < 0)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_procs; i++)
    {
        wait(NULL);
    }

    return 0;
}
