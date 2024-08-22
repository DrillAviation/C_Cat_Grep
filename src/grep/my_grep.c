#include "my_grep.h"

int main(int argc, char *argv[]) {
  Flags flags = {0};
  parser(argc, argv, &flags);
  if (output(argv, &flags, argc) >= 1) {
    return 0;
  }
}

void parser(int argc, char *argv[], Flags *flags) {
  char *shorts = "e:ivclnhsf";
  int ex;
  while ((ex = getopt(argc, argv, shorts)) != -1) {
    switch (ex) {
      case 'e':
        flags->e = 1;
        strcat(flags->str_regexec, optarg);
        strcat(flags->str_regexec, "|");
        break;
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'f':
        flags->f = 1;
        f_flag(argv, flags);
        optind++;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'o':
        flags->o = 1;
        break;
    }
  }
  if (!flags->e && !flags->f) {
    if (optind < argc) strcat(flags->str_regexec, argv[optind]);
    optind++;
  }
  if (flags->e || flags->f) {
    flags->str_regexec[strlen(flags->str_regexec) - 1] = '\0';
    // printf("%s", flags->str_regexec);
  }
}

int output(char *argv[], Flags *flags, int argc) {
  FILE *fp;
  regex_t reg;
  regmatch_t start;
  int flag_i = REG_EXTENDED;
  int match = 0, err = 0, count1 = 0;
  if (flags->i == 1) flag_i = REG_EXTENDED | REG_ICASE;
  regcomp(&reg, flags->str_regexec, flag_i);
  for (int i = optind; i < argc; i++) {
    fp = fopen(argv[i], "r");
    int count = 0;
    if (fp != NULL) {
      while (fgets(flags->str, BUFF, fp) != NULL) {
        count1++;
        match = regexec(&reg, flags->str, 1, &start, 0);
        if (flags->v) match = !match;
        if (!match) count++;
        if (!match && !flags->c && !flags->l) {
          if (argc - optind <= 1 || flags->h == 1) {
            if (!flags->n)
              printf("%s", flags->str);
            else if (flags->n == 1) {
              printf("%d:%s", count1, flags->str);
            }
          } else if (argc - optind > 1) {
            if (!flags->n)
              printf("%s:%s", argv[i], flags->str);
            else if (flags->n == 1)
              printf("%s:%d:%s", argv[i], count1, flags->str);
          }
        }
      }
      fclose(fp);
    } else if (flags->s != 1) {
      fprintf(stderr, ("grep: %s: No such file or directory\n"), argv[i]);
      err++;
      return err;
    }
    if (flags->c == 1) printf("%d\n", count);
    if (flags->l == 1 && count > 0) printf("%s\n", argv[optind]);
    count1 = 0;
  }
  regfree(&reg);
  return err;
}

void f_flag(char *argv[], Flags *flags) {
  FILE *fl;
  char buffer[BUFF];
  if (flags->f == 1) {
    for (int i = optind; i < optind + 1; i++) {
      fl = fopen(argv[i], "r");
      if (fl != NULL) {
        fgets(buffer, BUFF, fl);
        strcat(flags->str_regexec, buffer);
        strcat(flags->str_regexec, "|");
      }
      fclose(fl);
    }
  }
}