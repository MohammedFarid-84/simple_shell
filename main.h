#ifndef MAIN_H
#define MAIN_H

/* NESSESRY LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


/* PROTOTYPE FUNCTIONS */
int execfile(void);
char *fndf(char *);
void printtxt(char *);
void show_shell(int);
char **splitLine(char *, char *);



#endif
