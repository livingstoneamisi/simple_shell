#include "shell.h"
/**
 * main -entry point
 * Return: 0 - success
 */
int main(void)
{
	char cmd[100];

	while (1)
	{
		prompt();
		reader(cmd, sizeof(cmd));

		if (strlen(cmd) == 0)
			continue;

		run(cmd);
	}
	return (0);
}
