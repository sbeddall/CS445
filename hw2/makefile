compiler: lex.yy.o main.o
	gcc -o compiler lex.yy.o main.o

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

lex.yy.c : yylex.c
	lex yylex.c

main.o : main.c
	gcc -c main.c

clean: 
	- rm lex.yy.o 
	- rm *.*~ 
	- rm main.o
	- rm lex.yy.c	
	- rm compiler
	- rm *~