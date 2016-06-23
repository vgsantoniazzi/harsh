#include "lex.h"
#include <stdio.h>

void factor(void);
void term(void);
void expression(void);

statements() {
  while (!match_with(EOI)) {
    expression();

    if (match_with(SEMI)) {
      advance();
    } else {
      fprintf(stderr, "%d: Interting missing semicolon");
    }
  }
}

void expression() {
  if (!legal_lookahead(NUM_OR_ID, LP, 0)) {
    return;
  }

  term();

  while (match_with(PLUS)) {
    advance();
    term();
  }
}

void term() {
  if (!legal_lookahead(NUM_OR_ID, LP, 0))
    return;

  factor();

  while (match_with(TIMES)) {
    advance();
    term();
  }
}

void factor() {
  if (!legal_lookahead(NUM_OR_ID, LP, 0))
    return;

  if (match_with(NUM_OR_ID)) {
    advance();
  } else if (match_with(LP)) {
    advance();
    expression();

    if (match_with(RP)) {
      advance();
    } else {
      fprintf(stderr, "%d: Mismatch parenthesis \n", yylineno);
    }
  } else {
    fprintf(stderr, "%d: Number or identifier expected");
  }
}

#include <stdarg.h>

#define MAXFIRST 16

int first_arg;

legal_lookahead(first_arg) {
  va_list args;
  int tok;
  int lookaheads[MAXFIRST], *p = lookaheads, *current;
  int error_printed = 0;
  int rval = 0;

  va_start(args, first_arg);

  if(!first_arg){
    if(match_with(EOI)){
      rval = 1;
    }
  } else {
    *p++ = first_arg;

    while(tok = va_arg(args, int) && p < &lookaheads[MAXFIRST]) {
      *++p = tok;
    }

    while(!match_with(SEMI)) {
      for(current = lookaheads; current < p; ++current) {
        if(match_with(*current)){
          rval = 1;
          goto exit;
        }
      }
      if(!error_printed) {
        fprintf(stderr, "Line syntax error\n", yylineno);
        error_printed = 1;
      }

      advance();
    }
  }
  exit:
    va_end(args);
    return rval;
}
