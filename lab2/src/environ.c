#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "environ.h"

int main(int argc, char *argv[]) {
    int opt;
    int option_index = 0;

    char *var = NULL;
    char *value = NULL;

    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"info", required_argument, 0, 'i'},
        {"set", required_argument, 0, 's'},
        {"assign", required_argument, 0, 'a'},
        {"value", required_argument, 0, 'v'},
        {"del", required_argument, 0, 'd'},
        {"clear", no_argument, 0, 'c'},
        {0, 0, 0, 0}
    };

    if (argc == 1) {
        print_environment();
        return 0;
    }

    while ((opt = getopt_long(argc, argv, "hi:s:a:v:d:c", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                break;
            case 'i':
                print_variable_info(optarg);
                break;
            case 's': {
                char *equal_sign = strchr(optarg, '=');
                if (equal_sign) {
                    *equal_sign = '\0';
                    var = optarg;
                    value = equal_sign + 1;
                    set_variable(var, value);
                } else {
                    fprintf(stderr, "Error: Incorrect format for --set. Use <var=val>.\n");
                }
                break;
            }
            case 'a':
                var = optarg;
                break;
            case 'v':
                value = optarg;
                break;
            case 'd':
                delete_variable(optarg);
                break;
            case 'c':
                clear_environment();
                break;
            default:
                print_help();
                return 1;
        }
    }

    if (var) {
        assign_variable(var, value);
    }

    return 0;
}
