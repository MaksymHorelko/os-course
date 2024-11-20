#ifndef BUFFER_H
#define BUFFER_H

typedef struct
{
    int *data; // Масив для збереження елементів
    int size;  // Максимальний розмір буфера
    int start; // Початковий індекс
    int end;   // Кінцевий індекс
    int count; // Кількість елементів у буфері
} Buffer;

void buffer_init(Buffer *buffer, int size);

void buffer_destroy(Buffer *buffer);

void buffer_put(Buffer *buffer, int item);

int buffer_get(Buffer *buffer);

#endif
