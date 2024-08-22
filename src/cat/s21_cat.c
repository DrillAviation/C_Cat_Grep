#include "s21_cat.h"

int main(int argc, char *argv[]) {
  Flag flags = {0};
  int eof = 0;
  int ch, flag = 0;
  parser(argc, argv, &flags);
  FILE *fp;
  for (int i = optind; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, ("s21_cat.c: %s: No such file or directory:\n"), argv[i]);
    } else {
      char prev = '\n';
      int count = 1;
      for (ch = getc(fp); ch != EOF; ch = getc(fp)) {
        if (flags.s == 1 && eof < 1) {
          if (prev == '\n' && ch == '\n') {
            if (flag == 1) {
              continue;
            }
            flag = 1;
          } else {
            flag = 0;
          }
        }
        if (flags.n == 1 && flags.b != 1) {
          if (prev == '\n') {
            printf("%6d\t", count);
            count++;
          }
        }
        if (flags.b == 1) {
          if ((prev == '\n') && (ch != '\n')) {
            printf("%6d\t", count);
            count++;
          }
        }
        if ((flags.e == 1) && (ch == '\n')) printf("$");
        if ((flags.t == 1) && (ch == '\t')) {
          printf("^");
          ch = ch + 64;
        }
        v_flag(&ch, &flags);
        printf("%c", ch);
        prev = ch;
        eof = 0;
      }
    }
    eof++;
  }
}

void parser(int argc, char *argv[], Flag *flags) {
  int ex;
  int ind;
  char *shorts = "bnseEtTv";
  struct option longer[] = {{"number-nonblank", 0, 0, 'b'},
                            {"number", 0, 0, 'n'},
                            {"squeeze-blank", 0, 0, 's'},
                            {0, 0, 0, 0}};
  while ((ex = getopt_long(argc, argv, shorts, longer, &ind)) != -1) {
    switch (ex) {
      case 'n':
        flags->n = 1;
        break;
      case 'b':
        flags->b = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'e':
        flags->e = 1;
        flags->v = 1;
        break;
      case 'E':
        flags->e = 1;
        break;
      case 't':
        flags->t = 1;
        flags->v = 1;
        break;
      case 'T':
        flags->t = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
    }
  }
}

void v_flag(int *ch, Flag *flags) {
  if (flags->v == 1) {
    if ((*ch <= 8 && *ch >= 0) || (*ch >= 11 && *ch <= 31)) {
      printf("^");
      *ch = *ch + 64;
    } else if (*ch == 127) {
      printf("^");
      *ch = *ch - 64;
    } else if (*ch >= 128 && *ch <= 159) {
      printf("M-^");
      *ch = *ch - 64;
    } else if (*ch >= 160 && *ch <= 255) {
      printf("M-");
      *ch = *ch - 128;
    }
  }
}