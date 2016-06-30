#include <stdio.h>
#include "lex.h"

char *names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };
char **namep = names;

char *newname(){
  if(namep >= &names[sizeof(names) / sizeof(*names)]){
    fprintf(stderr, "%d: Expression too complex \n", yylineno);
    exit(1);
  }
  return(*namep++);
}

char *freename(s) {
  if(namep > names) {
    *--namep = s;
  } else {
    fprintf(stderr, "%d: (Internal Error) stack underflow \n", yylineno);
  }
}
