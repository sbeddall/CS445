#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"


//token construct
typedef struct tokenitem {
  int category;   /* the integer code returned by yylex */
  char *text;     /* the actual string (lexeme) matched */
  int lineno;     /* the line number on which the token occurs */
  char *filename; /* the source file in which the token occurs */
  int ival;       /* if you had an integer constant, store its value here */
  char *sval;      /* if you had a string constant, malloc space and store */
} token ;        /* the string (less quotes and after escapes) here */

//linked list item
typedef struct tokenlist {
  struct tokenitem* t;
  struct tokenlist* next;
} token_item ;

typedef struct genericList {
  void* content;
  struct genericList* next;
} list ;

//generic linked list stuff
void genericAdd(list* head, void* argument);
int genericInsert(list* head, void* argument, int where);
void genericPrint(list* head);
void cocatenateList(list* first, list* second);
list* newListItem();


//linked list functions
void addToList(token_item* head, token* new);
void addYYTokenToList(token_item* head);
void printList(token_item* head);
void printYYList(token_item* head);
token* YYDup();
void freeToken(token* tok);

//string functions
int compareStrings(char* first, char* second);
char* makeNewString(char* op);

//YYToken Populators
void evalToYYToken(int category, char* yytext);
void addCategoryToYYToken(int category);
void addStringToYYToken(char* yytext);
void populateYYGlobals();
void ISval(int category, char* yytext);


//error printer
void printError(char* errorText, struct node* head);
void printErrorVerbose(char* errorText, struct node* head);
char* getFileName();

//debug output
void debugOutput(struct node* head);
void debugOutputVerbose(struct node* head);
void printNodeDetails(struct node* head);
void printNodeDetailsVerbose(struct node* head);



#endif
