#include <stdio.h>
#include "calc.tab.h"
char *YYCURSOR;

int main(int argc, const char *argv[])
{
    char BUFFER[100];
    while (1) {
        fgets(BUFFER, 100, stdin);
        YYCURSOR = BUFFER;
        yyparse();
    }
    return 0;
}
