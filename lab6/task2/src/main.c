#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "cancellable_thread.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <delay_seconds>\n", argv[0]);
        return 1;
    }

    int delay_seconds = atoi(argv[1]);
    if (delay_seconds <= 0) {
        fprintf(stderr, "Delay must be a positive integer.\n");
        return 1;
    }

    pthread_t thread;
    void *status;

    if (pthread_create(&thread, NULL, cancellable_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    sleep(delay_seconds);

    if (pthread_cancel(thread) != 0) {
        perror("Failed to cancel thread");
        return 1;
    }

    if (pthread_join(thread, &status) != 0) {
        perror("Failed to join thread");
        return 1;
    }

    if (status == PTHREAD_CANCELED) {
        printf("Thread was canceled.\n");
    } else {
        printf("Thread finished execution normally.\n");
    }

    return 0;
}
