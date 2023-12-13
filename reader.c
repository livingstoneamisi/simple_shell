#include "shell.h"
/**
 * reader - read user input
 * @cmd:pointer to user command
 * @s:length of commanf
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
