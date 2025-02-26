# Lab 05: Mutex, Semaphore and Monitors

## Objectives
To get familier with:
- Semaphore
- Monitor

---

## Theory
Semaphore and monitor both are solutions for the produccer consumer problem and are better alternatives of the busy waiting solution.

### Semaphore
Producer consumer problem can be solved by using *2 semaphores* manually.

- Semaphore 1: Uses two variables.
    - empty --> To track empty slots in buffer.
    - full --> To track filled slots in buffer.

- Additionally *a mutex or semaphore* is used to *ensure mutual exclusion* while accessing the shared buffer.

**Producer:** *Waits on empty* and the *signals full* after adding an item to the buffer, while using the mutex to ensure safe access.

**Consumer:** *Waits on full* and *signals empty* after consuming an item, using the mutex to ensure safe access.

### Monitor
A monitor is an abstraction that encapsulates shared data and provides synchronization through condition variables and mutual exclusion.

- Has two variables: not_empty and not_full
- Producer *waits on not_full* if the buffer is full, *adds an item* and *signals not_empty*.
- Consumer *waits on not_empty* if the buffer is empty, *consumes and item* and *signals not_full*.

### Semaphore Vs Monitor
| Aspect | Semaphore | Monitor |
|--------|-----------|---------|
| Synchronization | Manual handling using sem_wait() and sem_post() | Automatic through condition variables and mutual exclusion. |
| Complexity | More error prone, as it requires manual control of locks | Simpler abstraction and easier to maintain. |
| Flexibility | More flexible, can be used for many synchronization problems | Less-flexible, specialized for a specific problem |
| Implementation | Requires explicit management of semaphores and mutexes. | Encapsulated in a monitor, easier to use in High Level Language. |

---

## Implementation
### 1. Semaphore
```c
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
```

**Output:**
```output
Produced item 1 at index 0
Consumed item 1 from index 0
Produced item 2 at index 1
Consumed item 2 from index 1
Produced item 3 at index 2
Produced item 4 at index 3
Consumed item 3 from index 2
Produced item 5 at index 4
Produced item 6 at index 0
Consumed item 4 from index 3
Produced item 7 at index 1
Produced item 8 at index 2
Consumed item 5 from index 4
Produced item 9 at index 3
Produced item 10 at index 4
Consumed item 6 from index 0
Produced item 11 at index 0
Consumed item 7 from index 1
Produced item 12 at index 1
Consumed item 8 from index 2
Produced item 13 at index 2
Consumed item 9 from index 3
Produced item 14 at index 3
Consumed item 10 from index 4
Produced item 15 at index 4
Consumed item 11 from index 0
Produced item 16 at index 0
Consumed item 12 from index 1
Produced item 17 at index 1
Consumed item 13 from index 2
Produced item 18 at index 2
Consumed item 14 from index 3
Produced item 19 at index 3
Consumed item 15 from index 4
Produced item 20 at index 4
Consumed item 16 from index 0
Produced item 21 at index 0
Consumed item 17 from index 1
Produced item 22 at index 1
Consumed item 18 from index 2
Produced item 23 at index 2
Consumed item 19 from index 3
Produced item 24 at index 3
Consumed item 20 from index 4
Produced item 25 at index 4
Consumed item 21 from index 0
Produced item 26 at index 0
Consumed item 22 from index 1
Produced item 27 at index 1
^C
```

### 2. Monitor
```cpp
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

const int BUFFER_SIZE = 5;

class Monitor
{
private:
    queue<int> buffer;
    int count;
    mutex mutx;
    condition_variable not_full;
    condition_variable not_empty;

public:
    Monitor() : count(0) {}

    // Inserts an item into the buffer
    void insertItem(int item)
    {
        unique_lock<mutex> lock(mutx);
        not_full.wait(lock, [this]
                      { return count < BUFFER_SIZE; });

        buffer.push(item);
        count++;

        lock.unlock();
        not_empty.notify_one(); // Signal that buffer is not empty
    }

    // Removes an item from the buffer
    int removeItem()
    {
        unique_lock<mutex> lock(mutx);
        not_empty.wait(lock, [this]
                       { return count > 0; });

        int item = buffer.front();
        buffer.pop();
        count--;

        lock.unlock();
        not_full.notify_one(); // Signal that buffer is not full

        return item;
    }
};

// Producer function
void producer(Monitor &monitor)
{
    for (int i = 0; i < 100; ++i)
    {
        monitor.insertItem(i);
        cout << "Producer produced item: " << i << endl;

        // Simulate some work being done
        this_thread::sleep_for(chrono::milliseconds(rand() % 100));
    }
}

// Consumer function
void consumer(Monitor &monitor)
{
    for (int i = 0; i < 100; ++i)
    {
        int item = monitor.removeItem();
        cout << "Consumer received: " << item << endl;

        // Simulate some work being done
        this_thread::sleep_for(chrono::milliseconds(rand() % 100));
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    Monitor monitor;

    thread producerThread(producer, ref(monitor));
    thread consumerThread(consumer, ref(monitor));

    producerThread.join();
    consumerThread.join();

    return 0;
}
```

**Output:**
```output
Producer produced item: 0
Consumer received: 0
Producer produced item: 1
Consumer received: 1
Producer produced item: 2
Consumer received: 2
Producer produced item: 3
Consumer received: 3
Producer produced item: 4
Consumer received: 4
Producer produced item: 5
Consumer received: 5
Producer produced item: 6
Producer produced item: 7
Producer produced item: 8
Producer produced item: 9
Consumer received: 6
Consumer received: 7
Producer produced item: 10
Consumer received: 8
Producer produced item: 11
Consumer received: 9
Producer produced item: 12
Consumer received: 10
Producer produced item: 13
Consumer received: 11
Consumer received: 12
Producer produced item: 14
Producer produced item: 15
Consumer received: 13
Consumer received: 14
Producer produced item: 16
Consumer received: 15
Consumer received: 16
Producer produced item: 17
Consumer received: 17
Producer produced item: 18
Producer produced item: 19
Consumer received: 18
Consumer received: 19
Producer produced item: 20
Producer produced item: 21
Producer produced item: 22
Consumer received: 20
Producer produced item: 23
Consumer received: 21
Consumer received: 22
Producer produced item: 24
Consumer received: 23
Producer produced item: 25
Consumer received: 24
Producer produced item: 26
Consumer received: 25
Consumer received: 26
Producer produced item: 27
Consumer received: 27
^C
```

---

## Conclusion
Semaphore and monitor both are solutions for the producer consumer problem and are better alternatives of the busy waiting solution both with their different approaches which we have learnt in this lab. The main diff among them is that the semaphore is a *low level approach* which manages all the process manually while the monitor is *high level approach* with inbuilt capabilities.

---
