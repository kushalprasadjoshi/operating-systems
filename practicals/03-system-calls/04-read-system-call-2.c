/*
In previous program we were having trouble with the string size.
So, we use count variable as below to solve that problem.
*/

#include<unistd.h>

int main() {
    int buffer[50];
    int count;

    // Stores the number of characters read from keyboard
    count = read(0, buffer, 50);

    // Write output of read characters on screen
    write(1, buffer, count);

    return 0;
}