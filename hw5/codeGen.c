#include "codeGen.h"
#include <stdlib.h>
#include "symbolTable.h"
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "enums.h"
#include "yyparse.tab.h"
#include "TAC.h"


extern int NUMVARIABLES;
extern int NUMLABELS;

char* newLabel(){

  char* new = (char*)malloc(sizeof(char)*10);

  new[0] = 'L';
  new[1] = '_';
  new[2] = '\0';
  
  char* integerToString = (char*)malloc(sizeof(char) * 10);
  
  itoa(NUMLABELS, integerToString);
  
  reverseString(integerToString);
  
  strcat(new,integerToString);

  NUMLABELS++;

  return new;
}

void yycodegen(node* head){
  populatePlaces(head);
  generateTAC(head);
  printTACList(head->code);
}

//do I want to put the actual symbolTable functionality here?
char* newVariable(symbolTable* parent){
  char* new = (char*)malloc(sizeof(char)*10);
  new[0] = '_';
  new[1] = '_';
  new[2] = 't';
  new[3] = '\0'; 
  
  char* integerToString = (char*)malloc(sizeof(char) * 10);
  
  itoa(NUMVARIABLES, integerToString);
  
  reverseString(integerToString);
  
  strcat(integerToString,"__");
  strcat(new,integerToString);
  
  NUMVARIABLES++;
  
  //add to symbolTable! We get offset that way!
  int result = addSymbol( parent, new, 1, NULL, NULL);
  

  return new;   
}


void populatePlaces(node* head){
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	populatePlaces(head->children[i]);
      }
    }
    
    
    //the places of variables should be taken care of already in semantic
    switch(head->label){
      
    case expr:
      {
	
	//add new variable to symbol table.
	//set place to that variable in symbol table.
	char* new = newVariable( head->table );
	
	field* location = getField( head->table, new );
	head->place = location;
	//printTable(head->table,0);
      }
      break;
           
    default:
      //default, do nothing
      break;
      
    }
  }
}

void generateTAC(node* head){;
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	generateTAC(head->children[i]);
      }
    }
    
    switch(head->label){
      
    case packageStatement:
      {
	head->code = newListItem();
	if(head->children[2] != NULL){
	  if(head->children[2]->tok->text != NULL){
	    head->code->content = makeLabeledTAC(head->children[2]->tok->text,
						 NULL, NULL, NULL, NULL);
	  }
	}
	head->code->content = makeLabeledTAC("anon_pkg",NULL,NULL,NULL,NULL);
	
	concatenateList(head->code,concatenateChildren(head));
      }
      break;
      
      
    case whileStatement:
      //make new item
      
      //makelabel
      //code
      //endlabel
      
      break;
      
    case functionCall:
      head->code = newListItem();
      
      head->code = concatenateChildren(head);
      break;
      
      
    case variableBinding:
      {
	/*
	      variableBinding (head)
	  name     type     initialization (head->children[2])
	                           assign value (head->children[1])
	 */
	printf("Variable Binding Here!\n");
	head->code = newListItem();
	if(head->children[2] != NULL){
	  if(head->children[2]->children[1]->label == expr){
	    head->code->content = makeTAC("ASN", head->children[0]->tok->text,
			   head->children[2]->children[1]->place->name,NULL);
	    // printTAC(head->code->content);
	  }
	  if(head->children[2]->children[1]->label == NUMBERLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->tok->text,
			   head->children[2]->children[1]->tok->text,NULL);
	    //printTAC(head->code->content);
	  }
	  if(head->children[2]->children[1]->label == STRINGLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->tok->text,
			   head->children[2]->children[1]->tok->text,NULL);
	    //	    printTAC(head->code->content);
	  }
	 
	}
	
	concatenateList(head->code,concatenateChildren(head));
      }
      break;
      

    case assignStatement:
      head->code = concatenateChildren(head);
      break;

    case expr:
      /*
            expr
	| mathvalue
	| expr sign expr
	| expr++
       */
      {
	head->code = newListItem();
	char* arg1 = NULL;
	char* arg2 = NULL;
	if(head->children[0]->label == expr){
	  arg1 = head->children[0]->place->name;
	}
	if(head->children[2]->label == expr){
	  arg2 = head->children[2]->place->name;
	} 
	
	head->code->content = makeTAC(head->children[1]->tok->text, 
				      head->place->name, arg1, arg2);
	
	printTAC(head->code->content);

	concatenateList(head->code,concatenateChildren(head));
      }
      break;
      


    default:
      head->code = concatenateChildren(head);
      break;
    }
    
  }  
}

list* concatenateChildren(node* head){
  list* first = NULL;
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i] != NULL && head->children[i]->code != NULL){
	//make sure we aren't concatenating null stuff
	if(first == NULL){
	  first = head->children[i]->code;
	}
	else
	  concatenateList(first, head->children[i]->code);	
      }
    }
  }
  

  return first;
}



char* itoa(int val, char* buf){
  int new = (unsigned int)val;
  char* temp = buf;
  
  
  while(val > 0){
    
    new = val % 10;
    val /= 10;
    
    *temp++ = new + '0';
  }

  *temp++ = '\0';
  
  return NULL;
}

void reverseString(char* buf){
  char* temp1 = buf;
  char* temp2 = buf;
  
  while(*temp2 != '\0'){
    temp2++;
  }
  temp2--;
  char new;
  
  while(temp1 < temp2){
    new = *temp1;
    *temp1 = *temp2;
    *temp2 = new;
    
    temp1++;
    temp2--;
  }
}

/*
val 53
new 53%10 = 3
val 53/10 = 5
new 5%10 = 5
val 5/10 = 0
*/
