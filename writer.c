#include "shell.h"

/**
 * writer - display on screen
 * @message: pointer to desired text
 */

void writer(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

