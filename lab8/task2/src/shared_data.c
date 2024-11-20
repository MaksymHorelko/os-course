#include "shared_data.h"
#include <stdlib.h>

void shared_data_init(SharedData *shared_data)
{
    shared_data->data = 0;
    shared_data->has_data = 0;
    pthread_mutex_init(&shared_data->lock, NULL);
    pthread_cond_init(&shared_data->producer_cond, NULL);
    pthread_cond_init(&shared_data->consumer_cond, NULL);
}

void shared_data_destroy(SharedData *shared_data)
{
    pthread_mutex_destroy(&shared_data->lock);
    pthread_cond_destroy(&shared_data->producer_cond);
    pthread_cond_destroy(&shared_data->consumer_cond);
}
