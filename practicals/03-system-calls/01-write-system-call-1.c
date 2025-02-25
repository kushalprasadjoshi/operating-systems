#include <unistd.h>

int main()
{
    // Writes Hello on screen
    write(1, "Hello", 5);

    // Writes He on screen
    write(1, "Hello", 2);

    // Writes garbage on screen
    write(1, "Hello", 20);

    return 0;
}