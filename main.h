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
char *erromsg(int, char *, char *);
char **splitLine(char *, char *);
void execCmd(int, char *, char **);
void printtxt(char *);
void show_shell(unsigned int);
char **splitLine(char *, char *);


#endif