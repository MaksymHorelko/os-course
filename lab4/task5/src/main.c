#include <stdio.h>
#include "mysystem.h"

int main()
{
    int result = my_system("ls -l");
    printf("Command exited with status: %d\n", result);
    return 0;
}
