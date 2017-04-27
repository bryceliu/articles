#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.tab.h"
extern char *YYCURSOR;

int yylex()
{
    if (*YYCURSOR == '\0') return 0;

    char num[100];
    char *start = YYCURSOR;

    /*!re2c
    re2c:define:YYCTYPE = int;
    re2c:yyfill:enable = 0;

    [0-9]+ { strncpy(num, start, YYCURSOR - start); num[YYCURSOR - start] = '\0'; yylval = atoi(num); return NUM; }
    '+' { yylval = '+'; return PLUS; }
    '-' { yylval = '-'; return MINUS; }
    '*' { yylval = '*'; return MUL; }
    '/' { yylval = '/'; return DIV; }
     */
}
