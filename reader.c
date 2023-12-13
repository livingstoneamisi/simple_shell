#include "shell.h"
/**
 * reader - read user input
 * @cmd:pointer to user command
 * @s:length of command
 */

void reader(char *cmd, size_t s)
{
	if (fgets(cmd, s, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printer("\n");
			exit(SUCCESS);
		}
		else
		{
			printer("Error: input read");
			exit(FAIL);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}

/**
 * printer - custom printf
 * @message: pointer to desired message
 */

void printer(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
