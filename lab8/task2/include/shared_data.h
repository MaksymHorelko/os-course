#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <pthread.h>

typedef struct
{
    int data;                     // Глобальна змінна для передачі даних
    int has_data;                 // Флаг наявності даних
    pthread_mutex_t lock;         // М'ютекс для синхронізації
    pthread_cond_t producer_cond; // Умовна змінна для виробника
    pthread_cond_t consumer_cond; // Умовна змінна для споживача
} SharedData;

void shared_data_init(SharedData *shared_data);

void shared_data_destroy(SharedData *shared_data);

#endif
