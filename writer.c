#include "shell.h"

/**
 * writer - display on screen
 */

void writer(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

