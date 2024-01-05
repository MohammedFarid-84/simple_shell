#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	char *arg[100];
	int i = 0;
	char *word;
	pid_t child;


	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&cmd, &len, stdin) != -1)
		{
			i = 0;
			word = strtok(cmd, " \n");
			while (word != NULL)
			{
				arg[i] = word;
				word = strtok(NULL, " \n");
				i++;
			}
			arg[i] = NULL;
			child = fork();
			if (child == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (child == 0)
			{
				execve(arg[0], arg, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}
	}
	free(cmd);
	return (0);
}
