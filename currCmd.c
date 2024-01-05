#include "main.h"

/**
 * Read_current_command - reads a line of input from the user
 * @command: buffer to store the command
 * @size: size of the buffer
 */

void Read_current_command(char *command, int size)
{
	fgets(command, size, stdin);
	// Remove newline, if present
	command[strcspn(command, "\n")] = '\0';
}
