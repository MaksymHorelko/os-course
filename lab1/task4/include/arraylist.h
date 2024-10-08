#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

typedef struct
{
    int *data;
    size_t capacity;
    size_t size;
} ArrayList;

// Функції для роботи з ArrayList
ArrayList *create_arraylist();
void add(ArrayList *list, int item);
void insert(ArrayList *list, size_t index, int item);
size_t size(const ArrayList *list);
void remove_at(ArrayList *list, size_t index);
void set(ArrayList *list, size_t index, int item);
int get(const ArrayList *list, size_t index);
void free_arraylist(ArrayList *list);

#endif
