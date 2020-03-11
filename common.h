#ifndef COMMON_H
#define COMMON_H
#define _GNU_SOURCE 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void error_handlings(char **argv, int args);
void encryption(char **argv);
void decryption(char *filename);
#endif

