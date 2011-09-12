#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>

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


//linked list functions
void addToList(token_item* head, token* new);
void addYYTokenToList(token_item* head);
void printList(token_item* head);
void printYYList(token_item* head);
token* YYDup();


//YYToken Populators
void evalToYYToken(int category, char* yytext);

void addCategoryToYYToken(int category);
void addStringToYYToken(char* yytext);
void populateYYGlobals();
void ISval(int category, char* yytext){
//ival
//sval

#endif
