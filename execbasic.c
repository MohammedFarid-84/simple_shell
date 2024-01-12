#include "main.h"

/**
 * erromsg - compact an error message text.
 * @no: count of commands run.
 * @sh: shell name.
 * @cmd: command name.
 * Return: a commpact string.
 */
char *erromsg(int no, char *sh, char *cmd)
{
	char *msg = malloc(strlen(sh) + strlen(cmd) * sizeof(int) + 3);

	sprintf(msg, "%s: %d: %s", sh, no, cmd);
	return (msg);
}
/**
 * splitLine - split Line text as array.
 * @line: a text line.
 * @dilim: the dilimeter to cut words.
 * Return: an array of words.
 */
char **splitLine(char *line, char *dilim)
{
	static char *aray[100];
	char *chunk = NULL;
	int i = 0;

	line[strcspn(line, "\n")] = 0;
	chunk = strtok(line, dilim);
	while (chunk != NULL)
	{
		aray[i] = chunk;
		i++;
		chunk = strtok(NULL, dilim);
	}
	aray[i] = NULL;
	return (aray);
}

/**
 * execCmd - execute a command in new process.
 * @no: command count.
 * @shN: programm name.
 * @envo: environment.
 * Return: void.
 */

void execCmd(int no, char *shN, char **envo)
{
	char *cmd = NULL;
	size_t len;
	pid_t childp;
	char *erMsg;

	if (getline(&cmd, &len, stdin) == -1)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	cmd[strcspn(cmd, "\n")] = 0;
	childp = fork();

	if (childp == -1)
	{
		free(cmd);
		perror("Can't create new process");
		return;
	}
	else if (childp == 0)
	{
		erMsg = erromsg(no, shN, cmd);
		if (execle(cmd, cmd, (char *)NULL, envo) == -1)
		{
			perror(erMsg);
			free(cmd);
			free(erMsg);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(cmd);
		wait(NULL);
	}
}
