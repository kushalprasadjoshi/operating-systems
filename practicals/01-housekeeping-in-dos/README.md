# Lab 01: Housekeeping in DOS

## Objectives
- To get familier with command prompt.
- To create/delete file/folders.
- To get details of existing files, folders in our C drive and modify them according to our needs within the command prompt.

---

## Theory
A CUI-based OS is an OS that uses a Character User Interface as its primary way of interactiong with the system. In CUI, user type commands into a terminal window to perform tasks and receive output in the same window. MS DOS is a CUI based OS as the user and computer interact with each other using text commands.

Some examples of CUI OS includes: UNIX, LINUX, MS DOS, etc.

---

## Implementation
To open command prompt press `Win + R` on keyboard. Type `cmd` and press enter.

Now execute the following commands.

1. 
```cmd
REM dispaly the overall contents
dir

REM Current dir is dentoed by .
REM Previous dir is dentoted by ..
```

2. 
```cmd
REM To change directory
cd dir_name 
```

3. 
```cmd
REM To make a folder
mkdir folder_name
```

4. 
```cmd
REM To make a new file
notepad > file_name.txt
REM or
echo > file_name.txt
```

5. 
```cmd
REM To write something in file
echo my new file >> file_name.txt
```

6. 
```cmd
REM To display/read the content of file
type file_name.txt 
```

7. 
```cmd
REM Deleting the file
del file_name
```

8. 
```cmd
REM To delete the folder (empty)
rmdir folder_name
```

9. 
```cmd
REM To delete the folder (not empty)
rmdir /s /q folder_name 
```

---

## Conclusion
In this lab, we become familier with basic housekeeping commands in MS DOS.

---
