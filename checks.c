#include "monty.h"
#include <ctype.h>

/**
 * the_comment - checks if string received is # or not
 * @str: string to check
 * @count: line number
 * Return: -1 if the string is not # or 1 if yes
 */
int the_comment(char *str, int count)
{
	if (str == NULL || str[0] == '#')
	{
	count++;
	return (1);
	}
	return (-1);
}


/**
 * isnumber - checks if a string is a number
 * @s: provided string
 *
 * Return: 1 if string is a number, else, 0.
 */
int is_num(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}



/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2 __attribute__((unused)))
{
	int i;
	
	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

