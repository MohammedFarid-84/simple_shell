#include "main.h"

/**
 * s_strlen - function prints length of string
 * @string: string
 *
 * Return: length of the string
 */

int s_strlen(char *string)
{
	int count = 0;

	while (string[count] != '\0')
	{
		count++;
	}

	return (count);
}
