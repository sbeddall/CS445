ec: lex.yy.o main.o structures.o
	gcc -o ec lex.yy.o main.o structures.o 

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

lex.yy.c : yylex.c
	lex yylex.c

main.o : main.c
	gcc -c main.c

structures.o : structures.c
	gcc -c structures.c

clean: 
	- rm lex.yy.o 
	- rm *.*~ 
	- rm main.o
	- rm lex.yy.c	
	- rm compiler
	- rm *~x
	- rm *.o

tar:
	tar cf hw2.tar makefile main.c yylex.c structures.c structures.h