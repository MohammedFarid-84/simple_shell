#include "main.h"

/**
 * rtrnpath - shearch and complite a command path
 * with default path in environment.
 * @cmd: the command name.
 * Return: return a full name of command line.
 */

char *rtrnpath(char *cmd)
{
	char *ps = getenv("PATH");
	char **pss;
	char *newcmd = malloc(sizeof(char *) * strlen(cmd) + 2);
	int i = 0;
	struct stat st;

	if (strchr(cmd, '/') != 0)
	{
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		else
		{
			free(newcmd);
			return (NULL);
		}
	}

	pss = splitLine(ps, ":");

	while (pss[i] != NULL)
	{
		sprintf(newcmd, "%s/%s", pss[i], cmd);
		if (stat(newcmd, &st) == 0)
			return (newcmd);

		i++;
	}
	free(newcmd);
	return (NULL);
}
