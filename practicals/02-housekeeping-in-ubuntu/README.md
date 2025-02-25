# Lab 02: Housekeeping in Ubuntu

## Objective
- The main objective of this lab session is to learn about different terminal commands.

---

## Theory
Housekeeping in Ubuntu refers to a set of maintainance practices aimed at ensuring the smooth functioning of the OS. Ubuntu's CLI is also a powerful tool for performing routine housekeeping tasks. Unlike GUIs, the CLI allows for faster execution for commands, and deeper control of the system.

---

## Implementation

1. 
```bash
ls # List of the contents of a directory
```

2. 
```bash
cd folder_name # Change the directory
```

3. 
```bash
ls - a # List of the contents of a directory including hidden files
```

4. 
```bash
clear # Clears the terminal screen
```

5. 
```bash
mkdir folder_name # Make directory command
```

6. 
```bash
touch hello.txt # Creates a file named hello.txt
```

7. 
```bash
cat hello.txt # Display the content inside hello.txt in terminal
```

8. 
```bash
nano file.txt # Nano is a simple text edioter for Unix/Linux systems. So, it creates a file and open as well.
# ^X is used to exit the file edioter
```

9. 
```bash
rm file.txt # Remove the file
```

10. 
```bash
rmdir kushal # Remove dir kushal if exists and empty
```

11. 
```bash
rmdir - r directory # Removes directory which is not empty
```

12. 
```bash
zip # Zips the directory only not the files inside it
zip test.zip text # test.zip will be create but has no files
```

13. 
```bash
unzip test.zip # Unzip the zipped files
```

14. 
```bash
zip -r test.zip test # test.zip will be created with all the files inside test directory.
```

15. 
```bash
pwd # Shows present working directory
```

---

## Conclusion
In this lab we explored the fundamenta Linux/Unix commands such as ls, touch, nano, clear, rmdir, etc. which are essential for effective file and directory management. These commands serves as building blocks for navigating and maintaining Unix based systems like Ubuntu.

---
