%{
    #include <stdio.h>
    int yylex();
    void yyerror(char const *error);
%}

%define api.value.type {int}
%define parse.lac full
%define parse.error verbose
%token NUM
%left PLUS MINUS
%left MUL DIV
%token LF

%%

input:
      %empty
    | input line

line:
      LF
    | expr LF { fprintf(stdout, "result: %d\n", $1); }
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
    fprintf(stderr, "parse error: %s\n", error);
}
