ec: yyparse.tab.o lex.yy.o main.o structures.o tree.o 
	gcc -o ec lex.yy.o main.o structures.o tree.o yyparse.tab.o

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

lex.yy.c : yylex.c
	lex yylex.c

yyparse.tab.o : yyparse.tab.c
	gcc -w -c yyparse.tab.c

yyparse.tab.c : yyparse.y
	bison -d -t -v  yyparse.y

main.o : main.c
	gcc -c main.c

structures.o : structures.c
	gcc -c structures.c

tree.o : tree.c
	gcc -c tree.c



clean: 	
	- rm yyparse.tab.c
	- rm yyparse.tab.h
	- rm lex.yy.o 
	- rm *.*~ 
	- rm main.o
	- rm lex.yy.c	
	- rm compiler
	- rm ec
	- rm *~x
	- rm *.o
	- rm *~
	- rm *.output
	- rm *.dot

tar: 
	tar cf hw3.tar makefile main.c yylex.c structures.c structures.h yyparse.y tree.c tree.h test	