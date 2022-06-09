#include "shell.h"
#include <stdio.h>
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
 *_puts - print a string
 *@str: pointer char
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 *_strncpy - copy a string
 *@dest: destination
 *@src: source
 *@n: length in int
 *Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + 1))
	{
		*(dest + 1) = *(src + 1);
		i++;
	}
	while (i < n)
	{
		*(dest + 1) = '\0';
		i++;
	}
	return (dest);
}
/**
 *_strlen - string length
 *@s: the string
 *Return: number of the length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}
/**
 *_atoi - convert string to digit
 *@s: string
 *Return: the digit
 *
 */
int _atoi(char *s)
{
	int i, j, n, x;

	i = 0;
	n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
