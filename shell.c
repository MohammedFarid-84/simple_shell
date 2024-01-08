#include "main.h"

/**
 * printtxt- print text to standard output.
 * @txt: the text to print.
 * Return: void.
 */

void printtxt(char *txt)
{
	write(1, txt, strlen(txt));
}

/**
 * show_shell - print cursor sign for point to the
 * shell wain type command from user.
 * @pr: integer point to user permesson.
 * Return: void.
 */

void show_shell(int pr)
{
	if (pr == 0)
		printtxt("$ ");
	else
		printtxt("($) ");
}

/**
 * main - run our simple shell.
 *
 * Return: zero always.
 */

int main(void)
{

	while (1)
	{
		show_shell(0);
		execfile();
	}
	return (0);
}
