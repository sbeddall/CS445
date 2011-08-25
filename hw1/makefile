compiler : main.o yylex.o
	gcc -o compiler yylex.o main.o

test : test.o yylex.o
	gcc -o test yylex.o test.o

main.o : main.c
	gcc -c main.c

test.o : test.c
	gcc -c test.c

yylex.o : yylex.c
	gcc -c yylex.c

clean : 
	- rm *.o 
	- rm *.*~
	- rm compiler
	- rm test