/*
In previous program we were having trouble with the string size.
So, we use count variable as below to solve that problem.
*/

#include<unistd.h>
#include<stdio.h>

int main() {
    int count;

    count = write(1, "Hello", 5);
    printf("\nThe write system call wrote %d characters", count);

    return 0;
}