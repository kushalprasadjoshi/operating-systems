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

