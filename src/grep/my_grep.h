#ifndef MY_GREP
#define MY_GREP
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#define BUFF 100000
typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int f;
  int h;
  int s;
  int o;
  char str[BUFF];
  char str_regexec[BUFF];
} Flags;
void parser(int argc, char *argv[], Flags *flags);
int output(char *argv[], Flags *flags, int argc);
void cflag(char *argv[], int count, Flags *flags);
void f_flag(char *argv[], Flags *flags);
#endif