# Lab 04: Process Synchronization

## Objectives
To get familier with:
- Shared variable
- Producer consumer problem
- Busy waiting solution of producer consumer problem

---

## Theory
### Shared Variable
- Can be accessed and modified by multiple processes.
- Facilitates communication and synchronization between concurrent processes.
- Used in IPC (Inter Process Communication).
- Leads to race condition.

### Producer Consumer Problem
Producer adds items in memory and consumer consumes it. The item should be produced iff have space and consumed iff there is item.

![Producer Consumer Problem Pseudocode](/assets/images/pseudo-code-producer-consumer-problem.png)

### Busy Waiting Solution
- Occurs when a process checks for a condition to met.
- Solves producer consumer problem.
- Inefficient use of CPU, as it wastes resources on constant polling.

![Busy Waiting Solution Pseudocode](/assets/images/pseudo-code-busy-waiting-solution.png)

![Busy Waiting Solution](/assets/images/busy-waiting-solution.png)

---

## Implementation

### 1. Shared Variable
```c
#include <stdio.h>
#include <unistd.h>

// Shared variable
int g = 5;

int main(int argc, char const *argv[])
{
    int pid;

    // Creating parent and child process
    pid = fork();

    // Executed by parent process
    if (pid > 0) {
        int x = g;
        x++;
        sleep(1);
        g= x;
        printf("\n Parent g = %d", g);
    }

    // Executed by child process
    else {
        int y = g;
        y--;
        sleep(1);
        g = y;
        printf("\n Child g = %d", g);
    }

    // Executed by both parent and child process 
    printf("\n Last g = %d", g);
    
    return 0;
}
```

**Output:**
```output
Parent g = 6
Last g = 6
Child g = 4
Last g = 4
```
**Note:** The output will vary each time you run the program.

### Producer Consumer Problem
```c
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
```

**Output**:
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
Produced item 12 at index 1
Consumed item 12 from index 1
Produced item 13 at index 2
Produced item 14 at index 3
Consumed item 13 from index 2
Produced item 15 at index 4
Produced item 16 at index 0
Consumed item 14 from index 3
Produced item 17 at index 1
Produced item 18 at index 2
Consumed item 15 from index 4
Produced item 19 at index 3
Produced item 20 at index 4
Consumed item 16 from index 0
Produced item 21 at index 0
Produced item 22 at index 1
Consumed item 22 from index 1
Produced item 23 at index 2
Produced item 24 at index 3
Consumed item 23 from index 2
Produced item 25 at index 4
Produced item 26 at index 0
Consumed item 24 from index 3
Produced item 27 at index 1
Produced item 28 at index 2
Consumed item 25 from index 4
Produced item 29 at index 3
Produced item 30 at index 4
Consumed item 26 from index 0
Produced item 31 at index 0
Produced item 32 at index 1
Consumed item 32 from index 1
Produced item 33 at index 2
Produced item 34 at index 3
Consumed item 33 from index 2
Produced item 35 at index 4
^C
```

**Reason:**  
![Producer Consumer Problem Output](/assets/outputs/producer-consumer-problem.png)

### Busy Waiting Solution
```c
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
Consumed item 23 from index 2
Produced item 28 at index 2
Consumed item 24 from index 3
Produced item 29 at index 3
^C
```

![Busy Waiting Solution](/assets/outputs/busy-waiting-solution.png)

---

## Conclusion
Shared variable can be used for IPC but leads to race condition. Busy waiting is one of the solution fo producer consumer problem which arrises due to the sequence of item production and consumption. But busy waiting solution wastes resources in constant polling.

---
