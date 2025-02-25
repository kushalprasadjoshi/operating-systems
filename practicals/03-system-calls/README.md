# Lab 03: System Calls

## Objectives
- To get familier with write system call.
- To get familier with read system call.
- To get familier with open system call.

---

## Theory
A system call is a mechanism used by system program to request services from the OS. In simpler words, it is a way for a program to interact with the underlying system, such as accessing hardware resources or performing priviliged operations.

**Features:** Interface, protection, kernel mode, context switching, error handling, synchronization

**Working:** Users need special resources --> the program makes a system call requests --> OS sees the system call --> OS performs the operation --> OS gives control back to program

**Pros:** Access to hardware resource, memory management, process management, security, standarrdization

**Cons:** Performance overhead, security risks, error handling complexity, compactibility challenges, resource consumption.

---

## Implemenataion

### 1. Write System Call
```c
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
```

**Output:**
```output
HelloHeHellop␦@Mingw ru
```

**In this program we are having trouble with the string size. So, we use the count variable as below.**

#### 2.
```c
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
```

**Output:**
```output
Hello
The write system call wrote 5 characters
```

### 3. Read System Call
```c
#include<unistd.h>

int main() {
    char buffer[50];

    // Read input of 8 characters from keyboard
    read(0, buffer, 8);

    // Write output of 8 characters on screen
    write(1, buffer, 8);

    return 0;
}
```

**Output:**
```output
123456789
12345678
```

**In this progarm we are having trouble with th string size. So, we use count variable as below.**

#### 4.
```c
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
```

**Output:**
```output
123456789
123456789
```

### 5. Open System Call
```c
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
```

**Output:**
Output will be shown in example.txt

---

## Conclusion
In conclusion, system calls are a important part of how computer programs interact with the OS. They provide a way for applications to request services from OS such as accessing files, managing memory or communicating over networks. System call acts as a bridge between user level program ans low level operations handled by OS kernel.

---
