#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "child.h"

#define DEFAULT_FILE_NAME "output_file"

void generate_random_numbers(const char *filename, int count)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++)
    {
        double random_value = (double)rand() / RAND_MAX;
        fprintf(file, "%f\n", random_value);
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <child_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int child_num = atoi(argv[1]);
    const char *base_file_name = getenv("FILE_NAME");
    if (!base_file_name)
    {
        base_file_name = DEFAULT_FILE_NAME;
    }

    char filename[256];
    sprintf(filename, "%s_%d.txt", base_file_name, child_num);

    printf("Child process %d: generating random numbers into file %s\n", child_num, filename);
    generate_random_numbers(filename, child_num);

    return 0;
}
