#include "structures.h"
#include <string.h>
#include "tree.h"

extern token* YYTOKEN;
extern int LINENO;
extern char* FILENAME;
extern int status;

//generic linked list stuff
void genericAdd(list* head, void* argument){
  //check to see if it's the first one
  
  list* iterator = head;
  if(iterator->content != NULL){
    //fill it!
    while(iterator->next != NULL){
      iterator = iterator->next;
    }
    list* newOne = (list*)malloc(sizeof(list));
    iterator->next = newOne;
    
    newOne->content = argument;
  }
  else{
    //its the first one! fill it!
    iterator->content = argument;
  }
}

int genericInsert(list* head, void* argument, int where){
  list* saved = NULL;
  int i = 1;
  list* iterator = head;
  
  if(where < 0){
    printf("%s\n", "Something went terribly wrong");
    return 0;
  }
  
  while(i <= where && iterator->next != NULL){
    iterator = iterator->next;
    i++;
  }
  
  list* newOne = (list*)malloc(sizeof(list));  
  newOne->next = iterator->next;
  
  
  iterator->next = newOne;
  newOne->content = argument;
}

void genericPrint(list* head){
  list* iterator = head;
  
  while(iterator->next != NULL){
    printf("%p\n",iterator); 
    iterator = iterator->next;
  }
  printf("%p\n", iterator);
}

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

//string comparison
int compareStrings(char* first, char* second){
  //step through to compare until we hit the end of the first string
  char* iterator = first;
  int i = 0;
  while(*iterator){
    if(*iterator != second[i]) return 0;  
    iterator++;
    i++;
  }
  if(second[i] != '\0') return 0; 
  
  
  return 1;
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

void printError(char* errorText, struct node* head){
  //status update as per assignment
  status = -3;
}

void printErrorVerbose(char* errorText, struct node* head){
  
  if( head->tok != NULL) printf("%s: %s\n", errorText, head->tok->text);
  printf("\tNode label: %d\n", head->label);
  if( head->tok != NULL) printf("\tLine Number: %d\n", head->tok->lineno);
  printf("\tSymbol Table: %p\n\n", head->table); 

  //status update as per assignment
  status = -3;
  
}
