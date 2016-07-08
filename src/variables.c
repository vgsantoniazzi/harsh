#include "lex.h"
#include <stdio.h>

char *names[] = {"_temporary_0", "_temporary_1", "_temporary_2", "_temporary_3", "_temporary_4", "_temporary_5", "_temporary_6", "_temporary_7"};
char **namep = names;

char *newname() {
  if (namep >= &names[sizeof(names) / sizeof(*names)]) {
    fprintf(stderr, "%d: Expression too complex \n", yylineno);
    exit(1);
  }
  return (*namep++);
}

char *freename(s) {
  if (namep > names) {
    *--namep = s;
  } else {
    fprintf(stderr, "%d: (Internal Error) stack underflow \n", yylineno);
  }
}
