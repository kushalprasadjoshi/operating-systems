# Lab 06: Scheduling Algorithms

## Objectives
To get familier with:
- FCFS (First Come, First Serve)
- SJF (Shortes Job First)

---

## Theory
Scheduling algorithms are a set of rules and methods used to determing the order in which process are executed by the CPU in a computer system.

**Purpose:** Ensures that resources, espically the CPU, are allocated fairly and efficiently among all processes.

**Goals:** Aims to maximize CPU usage, provide fairness among processes, minimize waiting time and avoid issues like process starvation.

### FCFS (First Come, First Serve)
This is a simplest type of scheduling algorithm. Processes are executed in order they arrive, much like waiting in line at a grocessory store.

**Pros:** Easy to implement and understand.

**Cons:** Can lead to phenomenon called the *convey effect* (shorter process get stuck waiting for longer one to finish). It leads to increase average waiting time.

### SJF (Shortest Job First)
Process and executed in order of their *brust time*, with the shortest jobs going first. It's like prioritizing the quickest task on your to-do list to get them out of the way.

**Pros:** Minimizes the average waiting time.

**Cons:** Can lead to *starvation* (can't use resources because other process are constantly being prioritized over it) of longer process if shorter one keeps arriving.

---

## Implementation
### 1. FCFS (First Come, First Serve)
```c
#include <stdio.h>

// Function to calculate the waiting time and turnaround time for a process
void findWaitingTime(int process[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time fro each process
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i -1] + bt[i - 1];
    }
}

    
// Function to calculate turnaround time for process
void findTurnAroundTime(int process[], int n, int bt[], int wt[], int tat[]) {
    // Turnaround time is the sum of waiting time and brust time
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Function calls to calculate waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    // Display results
    printf("Process\tBrust Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

// Driver code
int main(int argc, char const *argv[])
{
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], brust_time[n];

    // Input brust time for each process
    printf("Enter time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Brust time for process %d: ", i + 1);
        scanf("%d", &brust_time[i]);
        processes[i] = i + 1; // Process IDs start from 1
    }

    // Function call to calculate average waitijng time and turnaround time
    findAverageTime(processes, n, brust_time);
    
    return 0;
}
```

**Output:**
```output
Enter the number of processes: 5
Enter time for each process:
Brust time for process 1: 4
Brust time for process 2: 5
Brust time for process 3: 3
Brust time for process 4: 2
Brust time for process 5: 7
Process Brust Time      Waiting Time    Turnaround Time
1       4               0               4
2       5               4               9
3       3               9               12
4       2               12              14
5       7               14              21

Average Waiting Time: 7.80

Average Turnaround Time: 12.00
```

### 2. SJF (Shortest Job First)
```c
#include <stdio.h>

struct Process
{
    int id;
    int brust_time;
};

void sjfScheduling(struct Process processes[], int n) {
    // Sort processes based on brust time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].brust_time > processes[j + 1].brust_time)
            {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
            
        }
        
    }
    
    int completion_time = 0;

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d", processes[i].id);
        completion_time += processes[i].brust_time;
        printf("(Completion Time: %d) ", completion_time);
    }
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    int n;
    
    // Input number of processes
    printf("Enter the number fo processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details of each process
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter brust time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].brust_time);
    }

    // Perform SJF scheduling
    sjfScheduling(processes, n);
    
    return 0;
}
```

**Output:**
```output
Enter the number fo processes: 5
Enter brust time for Process P1: 2
Enter brust time for Process P2: 5
Enter brust time for Process P3: 4
Enter brust time for Process P4: 6
Enter brust time for Process P5: 8
Order of execution: P1(Completion Time: 2) P3(Completion Time: 6) P2(Completion Time: 11) P4(Completion Time: 17) P5(Completion Time: 25)
```

---

## Conclusion
Scheduling algorithms are a set of rules and methods used to determine the order in which process are executed by CPU. In FCFS, processes are executed in order they arrive. In SJF processes are executed in order of their brust time.

---
