#include "arraylist.h"
#include <stdio.h>

int main()
{
    ArrayList *list = create_arraylist();

    add(list, 10);
    add(list, 20);
    add(list, 30);

    size_t s = size(list);
    printf("List size: %lu\n", s);

    printf("ArrayList: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", get(list, i));
    }
    printf("\n");

    printf("Element at index 1: %d\n", get(list, 1));

    set(list, 2, 25);
    printf("Element at index 2 after set: %d\n", get(list, 2));

    remove_at(list, 1);
    printf("Element at index 1 after removal: %d\n", get(list, 1));

    s = size(list);
    printf("List size: %lu\n", s);

    printf("ArrayList: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", get(list, i));
    }
    printf("\n");

    free_arraylist(list);
    return 0;
}
