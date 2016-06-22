#include <stdio.h>
#include "lex.h"

statements() {
  expression();

  if( match_with( SEMI ) ){
    advance();
  } else {
    fprintf( stderr, "%d: Inserting missing semicolon \n", yylineno );
  }

  if( !match_with( EOI ) ){
    statements();
  }
}

expression(){
  term();
  expr_prime();
}

expr_prime() {
  if( match_with( PLUS ) ){
    advance();
    term();
    expr_prime();
  }
}

term() {
  factor();
  term_prime();
}

term_prime() {
  if( match_with( TIMES ) ){
    advance();
    factor();
    term_prime();
  }
}

factor(){
  if( match_with( NUM_OR_ID ) ){
    advance();
  } else if ( match_with( LP ) ){
    advance();
    expression();

    if(match_with(RP)) {
      advance();
    } else {
      fprintf(stderr, "%d: Mismatch_with parenthesis \n", yylineno);
    }
  } else {
    fprintf(stderr, "%d number or identifier unexpected", yylineno);
  }
}
