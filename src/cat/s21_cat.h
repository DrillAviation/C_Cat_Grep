#ifndef S21_CAT
#define S21_CAT
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} Flag;
void parser(int argc, char *argv[], Flag *flags);
void v_flag(int *ch, Flag *flags);
#endif