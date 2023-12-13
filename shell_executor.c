#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int main(void)
{
    char input[MAX_INPUT_LENGTH];

    while (1)
    {
        // Display prompt
        printf("#cisfun$ ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1)
        {
            // Fork failed
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process

            // Execute the command using execve
            if (execlp(input, input, (char *)NULL) == -1)
            {
                // Handle execution error
                perror("Command not found");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process

            // Wait for the child process to complete
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
            {
                // Child process exited normally
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0)
                {
                    fprintf(stderr, "Command returned non-zero exit status: %d\n", exit_status);
                }
            }
            else
            {
                // Child process did not exit normally
                fprintf(stderr, "Command did not exit normally\n");
            }
        }
    }

    return 0;
}
