#include "main.h"

/**
 * splitLine - split text line with a dilimeter.
 * @line: the line we need split it.
 * @dilimr: the dilimeter.
 * Return: array with line chunks.
 */
char **splitLine(char *line, char *dilimr)
{
	char **aray = NULL;
	char *chunk = NULL;
	char **newaray = NULL;
	int i = 0;

	if (strlen(line) > 0 && strlen(dilimr) > 0)
	{
		chunk = strtok(line, dilimr);
		while (chunk != NULL)
		{
			aray = malloc(strlen(chunk) + sizeof(char *));
			aray[i] = chunk;
			chunk = strtok(NULL, dilimr);
			i++;
		}
		aray[i] = NULL;
		strcpy(*newaray, *aray);
		free(aray);
		return (newaray);
	}
	return (NULL);
}

/**
 * fndf - search for file in bin folder.
 * @fil: file name we want search for.
 * Return: the full path of file when it found.
 */

char *fndf(char *fil)
{
	char *full = NULL;
	char *paths = getenv("PATH");
	int i = 0;
	char **fullpatharay = NULL;
	struct stat st;

	if (strlen(fil) == 0) /* NO INPOUT */
		return (NULL);

	if (strchr(fil, '/') != NULL) /* pass file name with path */
		return (fil);

	fullpatharay = splitLine(paths, ":");
	while (fullpatharay[i] != NULL)
	{
		strcpy(full, fullpatharay[i]);
		strcat(full, "/");
		strcat(full, fil);
		if (stat(full, &st) == 0)
			break;
		i++;
	}
	if (stat(full, &st) != 0) /* Not found file in all paths */
		exit(EXIT_FAILURE);

	return (full);
}

/**
 * execfile - excute a program.
 * Return: 0 if no error and error number if error.
 */

int execfile(void)
{
	char *command = NULL;
	char **cmdchunk = NULL;
	size_t siz = 0;
	char *cmd = NULL;
	pid_t childp;

	if (getline(&command, &siz, stdin) == -1) /* NO INPUTS */
		exit(EXIT_FAILURE);

	cmdchunk = splitLine(command, " \n");
	cmd = fndf(cmdchunk[0]);
	if (cmd != NULL)
	{
		childp = fork();
		if (childp == -1)
		{
			perror("Error: cann't run prosses");
			exit(EXIT_FAILURE);
		}
		else if (childp == 0)
		{
			execve(cmd, cmdchunk, NULL);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	free(command);
	return (0);
}
