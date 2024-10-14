#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "environ.h"

extern char **environ;

void print_environment() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

void print_help() {
    printf("Usage: environ [OPTIONS]\n");
    printf("Options:\n");
    printf("  -h, --help           Show this help message\n");
    printf("  -i, --info <var>     Show the value of the specified environment variable\n");
    printf("  -s, --set <var=val>  Set the value of the specified environment variable\n");
    printf("  -a, --assign <var>   Assign a value to the specified environment variable\n");
    printf("  -v, --value <val>    Value to assign when using --assign\n");
    printf("  -d, --del <var>      Delete the specified environment variable\n");
    printf("  -c, --clear          Clear all environment variables\n");
}

void print_variable_info(const char* var) {
    const char* value = getenv(var);
    if (value) {
        printf("%s=%s\n", var, value);
    } else {
        printf("Variable %s not found in environment.\n", var);
    }
}

void set_variable(const char* var, const char* value) {
    if (setenv(var, value, 1) == 0) {
        printf("Set %s=%s\n", var, value);
    } else {
        perror("setenv");
    }
}

void assign_variable(const char* var, const char* value) {
    if (var) {
        if (!value) {
            value = "";
        }
        set_variable(var, value);
    } else {
        fprintf(stderr, "Error: No variable specified for assignment.\n");
    }
}

void delete_variable(const char* var) {
    if (unsetenv(var) == 0) {
        printf("Deleted variable: %s\n", var);
    } else {
        perror("unsetenv");
    }
}

void clear_environment() {
    environ = NULL;
    printf("Environment cleared.\n");
}
