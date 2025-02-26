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
