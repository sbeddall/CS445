DEBUG = DEBUG=0

all:
	make ec

ec: yyparse.tab.o lex.yy.o main.o structures.o tree.o symbolTable.o dataPacks.o TAC.o codeGen.o semanticAnalysis.o
	gcc -ggdb -o ec lex.yy.o main.o structures.o tree.o yyparse.tab.o symbolTable.o dataPacks.o TAC.o codeGen.o semanticAnalysis.o

debug: 
	@make ec DEBUG=DEBUG=1

lex.yy.o : lex.yy.c
	gcc -ggdb -c  lex.yy.c

lex.yy.c : yylex.c
	lex yylex.c

yyparse.tab.o : yyparse.tab.c
	gcc -ggdb -c yyparse.tab.c

yyparse.tab.c : yyparse.y
	bison  -d -t -v  yyparse.y

main.o : main.c
	gcc -ggdb -c -D$(DEBUG) main.c

structures.o : structures.c
	gcc -ggdb -c -D$(DEBUG) structures.c

tree.o : tree.c
	gcc -ggdb -c -D$(DEBUG) tree.c

symboltable.o : symbolTable.c
	gcc -ggdb -c -D$(DEBUG) symbolTable.c

dataPacks.o : dataPacks.c
	gcc -ggdb -c -D$(DEBUG) dataPacks.c

TAC.o : TAC.c
	gcc -ggdb -c -D$(DEBUG) TAC.c

semanticAnalysis.o : semanticAnalysis.c
	gcc -ggdb -c -D$(DEBUG) semanticAnalysis.c

codeGen.o : codeGen.c
	gcc -ggdb -c -D$(DEBUG) codeGen.c

clean: 	
	@- rm yyparse.tab.c
	@- rm yyparse.tab.h
	@- rm lex.yy.o 
	@- rm *.*~ 
	@- rm main.o
	@- rm lex.yy.c	
	@- rm compiler
	@- rm ec
	@- rm *~x
	@- rm *.o
	@- rm *~
	@- rm *.output
	@- rm *.dot
	@- rm *.tar
	@- rm *.ic
	@- rm \#*

tar: 
	tar cf hw6.tar yyparse.y *.c *.h test*