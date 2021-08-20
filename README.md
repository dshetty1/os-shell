# os-shell
Basic Operating System Shell

### Description:

Replicates an operating system shell that waits for a command to be entered from a prespecified list. If the command is a built-in command, a process will execute it. If not, then a combination of fork(), execve(), and wait() will create a new child process, execute the command, and terminate the child process. If the user types the word “exit” then the program ends. Otherwise, another iteration will be executed. 


### Input and Output:

List of prespecified commands:

- printid -  prints the id of the current process
- exit - ends the program and exits
- greet - prints “Hello\n”
- ls -  lists the files in the current directory
- pwd - prints the path of the current working directory
- ps - prints the status of the current processes
- date - prints the current date and time
- lscpu - prints information about the current processes of the machine
