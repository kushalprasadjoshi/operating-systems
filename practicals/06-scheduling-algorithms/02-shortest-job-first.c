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
