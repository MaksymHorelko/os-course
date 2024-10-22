#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>
#include <signal.h>

#define DEFAULT_BUFFER_SIZE 127
#define CLEAR_COMMAND "clear"

void print_help() {
    printf("Usage: ./simple_shell [OPTIONS]\n");
    printf("Options:\n");
    printf("  -h, --help           Show this help message\n");
    printf("  -b, --buffer SIZE    Set buffer size for command input (default: 127)\n");
}

void handle_exit() {
    printf("\nWait 3 seconds...\n");
    sleep(3);
    system(CLEAR_COMMAND);
    exit(0);
}

int main(int argc, char *argv[]) {
    char *user_name;
    struct passwd *pw;
    int buffer_size = DEFAULT_BUFFER_SIZE;
    char *buffer;
    char *command;

    pw = getpwuid(getuid());
    if (pw) {
        user_name = pw->pw_name;
    } else {
        fprintf(stderr, "Error getting user information: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--buffer") == 0) {
            if (i + 1 < argc) {
                buffer_size = atoi(argv[++i]);
            } else {
                fprintf(stderr, "Error: Missing buffer size argument.\n");
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    buffer = (char *)malloc(buffer_size * sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Welcome to the simple shell processor!\n");
    printf("User: %s\n", user_name);

    signal(SIGINT, handle_exit);
    signal(SIGTERM, handle_exit);

    while (1) {
        printf("[%s]$ ", user_name);
        fflush(stdout);

        if (fgets(buffer, buffer_size, stdin) == NULL) {
            if (feof(stdin)) {
                handle_exit();
            } else {
                fprintf(stderr, "Error reading input: %s\n", strerror(errno));
                continue;
            }
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "stop") == 0) {
            handle_exit();
        }

        int result = system(buffer);
        if (result == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
        }
    }

    free(buffer);
    return EXIT_SUCCESS;
}
