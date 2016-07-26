#include "lex.h"
#include <stdarg.h>
#include <stdio.h>

void factor(char *tempvar);
void term(char *tempvar);
void expression(char *tempvar);

extern char *newname(void);
extern char freename(char *name);

statements() {
  char *tempvar;

  while (!match_with(EOI)) {
    expression(tempvar = newname());
    freename(tempvar);

    exit(0);
    if (match_with(SEMI)) {
      advance();
    } else {
      fprintf(stderr, "%d: Interting missing semicolon");
    }
  }
}

void expression(char *tempvar) {
  char *tempvar2;

  term(tempvar);

  while (match_with(PLUS)) {
    advance();
    term(tempvar2 = newname());
    printf("    %s += %s \n", tempvar, tempvar2);
    freename(tempvar2);
  }
}

void term(char *tempvar) {
  char *tempvar2;

  factor(tempvar);

  while (match_with(TIMES)) {
    advance();
    factor(tempvar2 = newname());
    printf("    %s *= %s \n", tempvar, tempvar2);
    freename(tempvar2);
  }
}

void factor(char *tempvar) {
  if (match_with(NUM_OR_ID)) {
    printf("    %s = %0.*s\n", tempvar, yyleng, yytext);
    advance();
  } else if (match_with(LP)) {
    advance();
    expression(tempvar);

    if (match_with(RP)) {
      advance();
    } else {
      fprintf(stderr, "%d: Mismatch parenthesis \n", yylineno);
    }
  } else {
    fprintf(stderr, "%d: Number or identifier expected");
  }
}
