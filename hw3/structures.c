#include "structures.h"
#include <string.h>

extern token* YYTOKEN;
extern int LINENO;
extern char* FILENAME;

//linked list implementation stuff
void addToList(token_item* head, token* new){
  printf("Adding to List: %d\n", new->category);

  token_item* iterator = head;
  while(iterator->next != 0){
    iterator = iterator->next;
  }
  
  token_item* new_one = (token_item*)malloc(sizeof(token_item));

  iterator->next = new_one;
  
  new_one->t = new;
}

void addYYTokenToList(token_item* head){
  token_item* iterator = head;
  while(iterator->next != 0){
    iterator = iterator->next;
  }
  
  token_item* new_one = (token_item*)malloc(sizeof(token_item));
  iterator->next = new_one;
  new_one->t = YYDup();
  new_one->next = 0;
}

void printList(token_item* head){
  token_item* iterator = head;
  
  printf("Entering PrintList\n");

  while(iterator->next != 0){
    printf("%d ", iterator->t->category);
    iterator = iterator->next;
  }
}

//this thing is gnarly ugly. just sayin
void printYYList(token_item* head){
  token_item* iterator = head;
  //printf("CategoryTextLinenoFilename\tIval/Sval\n\n");
  printf("%-10s %-20s%-10s%-30s%-20s\n", "Category","Text","Line #","Filename","Ival/Sval");
  while(iterator->next != 0){
    if(iterator->t->category == 332){
      printf("%-10d %-20s%-10d%-30s%-20d\n", iterator->t->category, iterator->t->text,iterator->t->lineno,iterator->t->filename,iterator->t->ival);
    }
    else if(iterator->t->category == 331){
      printf("%-10d %-20s%-10d%-30s%-20s\n", iterator->t->category, iterator->t->text,iterator->t->lineno,iterator->t->filename,iterator->t->sval);
    }
    else {
      printf("%-10d %-20s%-10d%-30s%-20s\n", iterator->t->category, iterator->t->text,iterator->t->lineno,iterator->t->filename,"null");
    }
    iterator = iterator->next;
  }
}

token* YYDup(){
  token* new = (token*)malloc(sizeof(token));

  new->category = YYTOKEN->category;
  new->text = strdup(YYTOKEN->text);
  new->lineno = LINENO;
  new->filename = strdup(YYTOKEN->filename);
  if(YYTOKEN->sval != NULL){
       new->sval = strdup(YYTOKEN->sval);
  }
  if(YYTOKEN->ival != 0){
    new->ival = YYTOKEN->ival;
  }
  
  return new;
}



//populating YYToken
void evalToYYToken(int category, char* yytext){
  addCategoryToYYToken(category);
  addStringToYYToken(yytext);
  populateYYGlobals();
  if(category == 331 || category == 332) ISval(category, yytext);   
}

void addCategoryToYYToken(int category){
  YYTOKEN->category = category;
}

void addStringToYYToken(char* yytext){
  YYTOKEN->text = yytext;
}

void populateYYGlobals(){
  YYTOKEN->lineno = LINENO;
  YYTOKEN->filename = FILENAME;
}

void ISval(int category, char* yytext){
  switch(category){
  case 331://string
    YYTOKEN->sval = strdup(yytext);
    YYTOKEN->sval++;
    char* iterator = YYTOKEN->sval;
    
    while(*iterator != '\0'){
      iterator++;
    }
    iterator--;
    *iterator = '\0';
    break;
  case 332://number
    YYTOKEN->ival = atoi(yytext);
    break;
  default:
    break;
  }
}
