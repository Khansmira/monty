#include "monty.h"

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
