#include <stdio.h>     // Required for perror function
#include <sys/types.h> // Required for mode_t(file attributes), ssize_t(signed long)
#include <fcntl.h> // Required for open function and flag constraints
#include <sys/stat.h> // Required for mode_t type and permission constants
#include <unistd.h> // Required for close function

int main()
{
    const char *filename = "example.txt";
    int flags = O_WRONLY | O_CREAT; // Open for writing and create if it doesn't
    mode_t mode = S_IRUSR | S_IWUSR; // User has read and write permissions

    int fd = open(filename, flags, mode);

    if(fd == -1) {
        perror("open");
        return 1;
    }

    // File is open and can be written to or read from using the file descriptor (fd)
    write(fd, "Hello World", 11);

    // Close the file when done
    close(fd);

    return 0;
}
