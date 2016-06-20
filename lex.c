#include "lex.h"
#include <stdio.h>
#include <ctype.h>

char *yytext = "";
int yyleng = 0;
int yylineno = 0;

main(){
  printf("return of gets %d", lex());
}

lex() {
  static char input_buffer[128];
  char *current;

  current = yytext + yyleng;

  while( 1 ) {
    while( !*current ){
      current = input_buffer;

      if( !gets ( input_buffer ) ) {
        *current = '\0';
        return EOI;
      }

      yylineno++;

      while( isspace( *current ) ){
        *current++;
      }
    }
    for ( ; *current ; current++) {
      yytext = *current;
      yyleng = 1;

      switch( *current ){
      case EOF: return EOI;
      case ';': return SEMI;
      case '+': return PLUS;
      case '*': return TIMES;
      case '(': return LP;
      case ')': return RP;
      case '\n':
      case '\t':
      case ' ': break;

      default:
        if ( !isalnum( *current ) ){
          fprintf(stderr, "Ingnoring illegal input <%c> \n", *current);
        } else {
          while( isalnum( *current ) ){
            current++;
          }
          yyleng = current - yytext;
          return NUM_OR_ID;
        }
        break;
      }
    }
  }
}
