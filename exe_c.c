#include "main.h"

/**
 * exe_c - for excute a program.
 * @command: a string point to program name.
 */

void exe_c(const char *command)
{
	const char argv[] = {command, NULL};
	pid_t current_pid = fork();

	if (current_pid == 0)
	{
		execve(command, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (current_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
