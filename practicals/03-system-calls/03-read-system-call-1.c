#include<unistd.h>

int main() {
    char buffer[50];

    // Read input of 8 characters from keyboard
    read(0, buffer, 8);

    // Write output of 8 characters on screen
    write(1, buffer, 8);

    return 0;
}