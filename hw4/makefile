ec: yyparse.tab.o lex.yy.o main.o structures.o tree.o symbolTable.o dataPacks.o
	gcc -ggdb -o ec lex.yy.o main.o structures.o tree.o yyparse.tab.o symbolTable.o dataPacks.o 

lex.yy.o : lex.yy.c
	gcc -ggdb -c  lex.yy.c

lex.yy.c : yylex.c
	lex yylex.c

yyparse.tab.o : yyparse.tab.c
	gcc -ggdb -c yyparse.tab.c

yyparse.tab.c : yyparse.y
	bison  -d -t -v  yyparse.y

main.o : main.c
	gcc -ggdb -c main.c

structures.o : structures.c
	gcc -ggdb  -c structures.c

tree.o : tree.c
	gcc -ggdb -c tree.c

symboltable.o : symbolTable.c
	gcc -ggdb -c symbolTable.c

dataPacks.o : dataPacks.c
	gcc -ggdb -c dataPacks.c

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
	- rm *.tar

tar: 
	tar cf hw4.tar makefile main.c yylex.c structures.c structures.h yyparse.y tree.c tree.h test test3 enums.h dataPacks.c dataPacks.h symbolTable.h symbolTable.c 	