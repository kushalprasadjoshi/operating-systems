#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

# define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

// Flags to indicate whether a slot is empty or full
int empty_slots = BUFFER_SIZE;
int full_slots = 0;

void *producer(void *arg) {
    int item = 1;
    while(1) {
        // Wait until there is an empty slot
        while (empty_slots == 0);

        buffer[in] = item;
        printf("Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item ++;

        // Update empty and full slot counts
        empty_slots--;
        full_slots++;

        sleep(1); // Simulate some work
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while(1) {
        // Wait until there is a full slot
        while (full_slots == 0);

        int item = buffer[out];
        printf("Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        // Update empty and full slot counts
        empty_slots++;
        full_slots--;
        
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
