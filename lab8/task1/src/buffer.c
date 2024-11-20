#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

void buffer_init(Buffer *buffer, int size)
{
    buffer->size = size;
    buffer->data = malloc(size * sizeof(int));
    buffer->start = 0;
    buffer->end = 0;
    buffer->count = 0;
}

void buffer_destroy(Buffer *buffer)
{
    free(buffer->data);
}

void buffer_put(Buffer *buffer, int item)
{
    if (buffer->count < buffer->size)
    {
        buffer->data[buffer->end] = item;
        buffer->end = (buffer->end + 1) % buffer->size;
        buffer->count++;
    }
    else
    {
        fprintf(stderr, "Buffer overflow\n");
    }
}

int buffer_get(Buffer *buffer)
{
    if (buffer->count > 0)
    {
        int item = buffer->data[buffer->start];
        buffer->start = (buffer->start + 1) % buffer->size;
        buffer->count--;
        return item;
    }
    else
    {
        fprintf(stderr, "Buffer underflow\n");
        return -1;
    }
}
