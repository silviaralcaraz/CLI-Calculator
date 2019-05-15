#ifndef P3COMP_LEX_YY_H
#define P3COMP_LEX_YY_H

#include "stdio.h"
#include "stdlib.h"

extern FILE *yyin;
extern char* yytext;
extern int yylex (void);
int yylex_destroy();

#endif //P3COMP_LEX_YY_H
