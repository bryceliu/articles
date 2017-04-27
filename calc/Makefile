main: main.c calc.lex.c calc.tab.c
	gcc -o main -g main.c calc.lex.c calc.tab.c
calc.lex.c: calc.l calc.tab.h
	re2c -o calc.lex.c calc.l
calc.tab.h: calc.y
	bison -d calc.y
calc.tab.c: calc.y
	bison -d calc.y
