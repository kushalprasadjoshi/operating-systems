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
