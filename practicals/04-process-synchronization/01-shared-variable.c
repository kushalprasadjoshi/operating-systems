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
