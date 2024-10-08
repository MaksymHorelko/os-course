#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10

// Створення нового списку
ArrayList *create_arraylist()
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    list->data = (int *)malloc(list->capacity * sizeof(int));
    return list;
}

// Додавання елемента в кінець списку
void add(ArrayList *list, int item)
{
    if (list->size == list->capacity)
    {
        // Збільшити розмір списку, якщо недостатньо місця
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = item;
}

// Вставка елемента в середину списку
void insert(ArrayList *list, size_t index, int item)
{
    if (index > list->size)
    {
        printf("Index out of bounds!\n");
        return;
    }
    if (list->size == list->capacity)
    {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    for (size_t i = list->size; i > index; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = item;
    list->size++;
}

// Отримання кількості елементів у списку
size_t size(const ArrayList *list)
{
    return list->size;
}

// Видалення елемента по індексу
void remove_at(ArrayList *list, size_t index)
{
    if (index >= list->size)
    {
        printf("Index out of bounds!\n");
        return;
    }
    for (size_t i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

// Зміна значення існуючого елемента
void set(ArrayList *list, size_t index, int item)
{
    if (index >= list->size)
    {
        printf("Index out of bounds!\n");
        return;
    }
    list->data[index] = item;
}

// Отримання значення елемента
int get(const ArrayList *list, size_t index)
{
    if (index >= list->size)
    {
        printf("Index out of bounds!\n");
        return -1;
    }
    return list->data[index];
}

// Звільнення пам'яті
void free_arraylist(ArrayList *list)
{
    free(list->data);
    free(list);
}
