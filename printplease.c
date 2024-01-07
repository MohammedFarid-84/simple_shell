#include "main.h"

/**
 * printplease - function prints a string
 * @random: string to be printed
 */

void printplease(const char *random)
{
	write(1, random, strlen(random));
}
