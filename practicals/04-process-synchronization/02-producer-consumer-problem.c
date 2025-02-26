#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

# define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
    int item = 1;
    while (1)
    {
        // Produce item and add to buffer without synchronization
        buffer[in] = item;
        printf("Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item ++;
        
        sleep(1); // Simulate some work
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (1)
    {
        // Consume item from buffer without synchronization
        int item = buffer[out];
        printf("Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        sleep(2); // Simulate some work
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    return 0;
}
