#include "main.h"

void exe_c(const char *command)
{
	    pid_t current_pid = fork();

	        if (current_pid == 0)
			    {
			char *const argv[] = {command, NULL};
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
