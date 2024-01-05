#include "main.h"

/**a
 * main - run mine shell.
 * @no: count of argumnets.
 * @arg: the arguments that user inserted.
 * Return: 0 always.
 */

int main(int no, char **arg)
{

	if (no < 2)
	{
		perror("Error: no file or command");
		return (EXIT_FAILUAR);
	}

	while (1)
	{
		The_shell_again();
		Read_current_command(arg[1], sizeof(arg[1]));
		exe_c(arg[1]);
	}

	return 0;
}
