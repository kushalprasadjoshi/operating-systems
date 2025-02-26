# Lab 07: Scheduling Algorithms 2

## Objectives
To get familier with:
- Priority Scheduling
- Round Robin

---

## Theory
### Priority Scheduling
Priority Scheduling is a method of scheduling processes based on priority. Each process is assigned a priority, and the CPU is allocated to the process with the highest priority. If two processes have the same priority, they are scheduled according to their arrival order. This method can be preemptive or non-preemptive.

### Round Robin
Round Robin is a preemptive scheduling algorithm where each process is assigned a fixed time slice or quantum. The CPU cycles through the processes in the ready queue, allocating the CPU to each process for a time equal to the quantum. If a process does not finish within its time slice, it is placed at the end of the queue, and the CPU moves to the next process. This method ensures fairness and is suitable for time-sharing systems.

---

## Implementation
### Priority Scheduling
```c
#include <stdio.h>

struct Process
{
    int id;
    int priority;
    int burst_time;
};

void priorityScheduling(struct Process processes[], int n)
{
    // Sort the processes based on priority
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[i].priority > processes[j + 1].priority)
            {
                // Swap the processes
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Dispaly the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", processes[i].id);
    }
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details of each process
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter the priority of process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter the burst time of process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Perform priority scheduling
    priorityScheduling(processes, n);
    
    return 0;
}
```

**Output:**
```output
Enter the number of processes: 5
Enter the priority of process P1: 6
Enter the burst time of process P1: 3
Enter the priority of process P2: 4
Enter the burst time of process P2: 1
Enter the priority of process P3: 8
Enter the burst time of process P3: 7
Enter the priority of process P4: 9
Enter the burst time of process P4: 4
Enter the priority of process P5: 6
Enter the burst time of process P5: 3
Order of execution: P4 P2 P1 P3 P5 
```

### Round Robin
```c
#include <stdio.h>

struct Process
{
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, int time_quantam) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                // Execute the process for the first quantam or remaining time whichever is smaller
                int execution_time = processes[i].remaining_time < time_quantam ? processes[i].remaining_time : time_quantam;
                processes[i].remaining_time -= execution_time;
                current_time += execution_time;

                // Display the execution of the process
                printf("Exectuing Process P%d for %d units of time\n", processes[i].id, execution_time);

                if (processes[i].remaining_time == 0)
                {
                    // Process has completed execution
                    remaining_processes--;
                    printf("Process P%d has completed execution\n", processes[i].id);
                }
            }
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int n, time_quantam;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details of each process
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter the burst time of process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Input time quantam
    printf("Enter the time quantam: ");
    scanf("%d", &time_quantam);

    // Perform round robin scheduling
    roundRobinScheduling(processes, n, time_quantam);
    
    return 0;
}
```

**Output:**
```output
Enter the number of processes: 5
Enter the burst time of process P1: 5
Enter the burst time of process P2: 6
Enter the burst time of process P3: 7
Enter the burst time of process P4: 3
Enter the burst time of process P5: 2
Enter the time quantam: 2
Exectuing Process P1 for 2 units of time
Exectuing Process P2 for 2 units of time
Exectuing Process P3 for 2 units of time
Exectuing Process P4 for 2 units of time
Exectuing Process P5 for 2 units of time
Process P5 has completed execution
Exectuing Process P1 for 2 units of time
Exectuing Process P2 for 2 units of time
Exectuing Process P3 for 2 units of time
Exectuing Process P4 for 1 units of time
Process P4 has completed execution
Exectuing Process P1 for 1 units of time
Process P1 has completed execution
Exectuing Process P2 for 2 units of time
Process P2 has completed execution
Exectuing Process P3 for 2 units of time
Exectuing Process P3 for 1 units of time
Process P3 has completed execution
```

---

## Conclusion
In this lab, we explored two different CPU scheduling algorithms: Priority Scheduling and Round Robin. Through the implementation and testing of these algorithms, we observed how Priority Scheduling allocates CPU based on process priority, potentially leading to starvation of lower priority processes. On the other hand, Round Robin scheduling ensures fairness by allocating a fixed time slice to each process, making it suitable for time-sharing systems. Understanding these algorithms helps in selecting the appropriate scheduling method based on the specific requirements of a system.

---
