#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int s_strlen(char *string);
void The_shell_again(void);
void exe_c(const char *command);
void Read_current_command(char *command, int size);

#endif /* MAIN_H */
