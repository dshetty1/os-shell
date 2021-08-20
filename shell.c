//Name: Dhruv Shetty

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// Function declaration
void printid();
void greet();

int main(int argc, char * argv[])
{
    // Infinite while loop (until exit is called)
    while(1){
        // Takes user input
        char input[100];
        printf("User> ");
        fgets(input, 10, stdin);
        printf("Parent Process %d\n", getpid());

        /*
        If the string entered by the user is a built-in command, then
            Check the string and based on it, do the corresponding tasks as stated below.
        If the built-in command is “exit”,
            End the whole process using exit(0);
        */
        if(strcmp(input, "greet\n") == 0){
            greet();
        }
        else if(strcmp(input, "printid\n") == 0){
            printid();
        }
        else if(strcmp(input, "exit\n") == 0){
            exit(0);
        }
        else {

        /*
        Not a predefined, built-in command
        Runs a linux command
        */
            // Fork a new process
            pid_t pid = fork();

            if(pid == 0){
                // Print process ID of the child process and the string entered by the user. Also removes the implicit newline at the end of the char[]
                input[strlen(input) - 1] = 0;
                printf("Child process %d will execute the command %s\n", getpid(), input);

                // Attaches "/bin/" to the beginning of the input
                char bin[100] = "/bin/";
                strcpy(input, strcat(bin, input));

                // Loading and running the process
                execve(input, argv, NULL);

                // If execve fails, prints "Command Failed!" and exits to the main loop
                printf("Command Failed!\n");
                exit(0);
            }
        }
        // Parent process waits for child process to finish running
        wait(NULL);
    }

    return 0; 
}

// Function to return ID of the current process
void printid() {
    printf("The ID of the current process is %d\n", getpid());
    return;
}

// Function to print "Hello"
void greet() {
    printf("Hello\n");
    return;
}
