#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "process_counter.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <duration_in_seconds>\n", argv[0]);
        return 1;
    }

    int duration = atoi(argv[1]);
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Нащадок
        count_for_duration(duration);
    } else {
        // Батьківський процес
        count_for_duration(duration);
        wait(NULL); // Очікуємо завершення нащадка
    }

    return 0;
}
