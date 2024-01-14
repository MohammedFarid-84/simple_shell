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

void show_shell(unsigned int pr)
{
	if (pr != 0)
		printtxt("$ ");
	else
		printtxt("($) ");
}

/**
 * main - run our simple shell.
 * @no: nothing.
 * @argv: parogramm name in first element.
 * @argvn: environment variables.
 * Return: zero always.
 */

int main(int no, char **argv)
{
	/* uid_t uids = getuid(); */
	char *errno_srt = malloc(20);
	int i = 0;

	sprintf(errno_srt, "%d", no);
	free(errno_srt);

	while (1)
	{
		/* show_shell(uids); */
		i++;
		execCmd(i, argv[0]);
	}
	return (0);
}
