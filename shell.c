#include "main.h"

int main(void)
{
	char command[50];

	while (1)
	{
	The_shell_again();
	Read_current_command(command, sizeof(command));
	exe_c(command);
	}

	return 0;
}
