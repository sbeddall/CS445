#include "structures.h"
#include <string.h>

extern token* YYTOKEN;
extern int LINENO;


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

void printYYList(token_item* head){
  token_item* iterator = head;
  printf("Category\tText\tLineno\tFilename\tIval/Sval\n\n");
  while(iterator->next != 0){
    printf("%d %*s\t%d\t%s\t\n", iterator->t->category,20, iterator->t->text,iterator->t->lineno,"test",0);
    iterator = iterator->next;
  }
}

token* YYDup(){
  token* new = (token*)malloc(sizeof(token));

  new->category = YYTOKEN->category;
  new->text = strdup(YYTOKEN->text);
  new->lineno = LINENO;
  
  return new;
}



//populating YYToken
void evalToYYToken(int category, char* yytext){
  addCategoryToYYToken(category);
  addStringToYYToken(yytext);
  populateYYGlobals();
}

void addCategoryToYYToken(int category){
  YYTOKEN->category = category;
}

void addStringToYYToken(char* yytext){
  YYTOKEN->text = yytext;
}

void populateYYGlobals(){
  YYTOKEN->lineno = LINENO;
  //YYTOKEN->filename = FILENAME;
}
