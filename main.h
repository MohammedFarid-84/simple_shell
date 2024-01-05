#ifndef MAIN_H
#define MAIN_H

/* nesserey libraries */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* prototype functions */
int s_strlen(char *string);
void The_shell_again(void);
void exe_c(const char *command);
void Read_current_command(char *command, int size);


#endif
