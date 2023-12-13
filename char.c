#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copie a string
 * @dest: char
 *  @src: char
 * @n: int
 * Return: char
 */

char *_strncpy(char *dest, char *src, int n)
{
int x;

x = 0;
	while (x < n && *(src + x))
	{
	*(dest + x) = *(src + x);
	x++;
	}
	while (x < n)
	{
	*(dest + x) = '\0';
	x++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s: char
 * Return: int
 */

int _strlen(char *s)
{
	int x;

		for (x = 0; s[x] != '\0'; x++)
		{
			continue;
		}
return (x);
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */

int _atoi(char *s)
{
int x, j, n, i;

	x = n = 0;
	i = 1;
	while ((s[x] < '0' || s[x] > '9') && (s[x] != '\0'))
	{
		if (s[x] == '-')
			i *= -1;
		x++;
	}
	j = x;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */

void _puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
_putchar('\n');
return;
}
