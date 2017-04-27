%{
    #include <stdio.h>
    int yylex();
    void yyerror(char const *error);
%}

%define api.value.type {int}
%token NUM
%left PLUS MINUS
%left MUL DIV

%%

input:
      %empty
    | input line

line:
      '\n'
    | expr '\n' { fprintf(stderr, "%d\n", $1); }
    ;

expr:
    NUM { $$ = $1; }
    | expr PLUS expr { $$ = $1 + $3; }
    | expr MINUS expr { $$ = $1 - $3; }
    | expr MUL expr { $$ = $1 * $3; }
    | expr DIV expr { $$ = $1 / $3; }
    ;

%%

void yyerror(char const *error)
{
    fprintf(stderr, "Error: %s\n", error);
}
