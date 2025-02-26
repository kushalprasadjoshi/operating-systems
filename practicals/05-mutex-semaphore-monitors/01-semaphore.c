#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

# define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty_slots, full_slots;

void *producer(void *arg) {
    int item = 1;
    while(1) {
        // Wait until there is an empty slot
        sem_wait(&empty_slots);

        // Produce item and add to buffer
        buffer[in] = item;
        printf("Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item ++;

        // Signal that a slot is now full
        sem_post(&full_slots);

        sleep(1); // Simulate some work
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while(1) {
        // Wait for a full slot
        sem_wait(&full_slots);

        // Consume item from buffer
        int item = buffer[out];
        printf("Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        // Signal that buffer is empty
        sem_post(&empty_slots);
        
        sleep(2); // Simulate some work
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up semaphores
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    
    return 0;
}
