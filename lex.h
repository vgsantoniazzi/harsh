#define EOI 0       // End of input
#define SEMI 1      // ;
#define PLUS 2      // +
#define TIMES 3     // *
#define LP 4        // (
#define RP 5        // )
#define NUM_OR_ID 6 // Decimal number or identifier

extern char *yytext;
extern int yyleng;
extern int yylineno;
