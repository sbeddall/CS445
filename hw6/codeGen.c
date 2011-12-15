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


#if (DEBUG == 1)
#define printTACListToFile(code) printTACList(code)
#endif

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
  
  TAC* content = makeLabeledTAC("BEGIN", NULL, NULL, NULL, NULL);
  list* lst = newListItem();
  lst->content = content;
  
  
  
  //generateTACList(head, lst);
  generateTAC(head);

  printTACListToFile(head->code);
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
	list* endLabel = newListItem();
	
	head->code = newListItem();
	//if(head->nchildren > 2){
	if(head->children[0]->label == IDENT){
	  if(head->children[0]->contents != NULL){
	    head->code->content = makeLabeledTAC(head->children[0]->contents,
						 "package", NULL, NULL, NULL);
	    endLabel->content = makeLabeledTAC(head->children[0]->contents,"end", NULL, NULL, NULL);
	  }
	}
	  /*}
	else 
	  head->code->content = makeLabeledTAC("anon_pkg",NULL,NULL,NULL,NULL);
	  */
	
	
	concatenateList(head->code,concatenateChildren(head));
	concatenateList(head->code, endLabel);
	
      }
      break;
      
      
    case whileStatement:
      //make new item
      
      //makelabel
      //code
      //endlabel
      
      break;
      
    case functionCall:
      //head->code = newListItem();
      
      

      
      head->code = concatenateChildren(head);
      break;
      
    
      
      
    case variableBinding:
      {
	/*
	      variableBinding (head)
	  name     type     initialization (head->children[2])
	                           assign value (head->children[1])
	 */
	//printf("Variable Binding Here!\n");
	head->code = newListItem();
	if(head->children[2] != NULL){
	  if(head->children[2]->children[0]->label == expr){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[0]->place->name,NULL);
	    // printTAC(head->code->content);
	  }
	  
	  if(head->children[2]->children[0]->label == NUMBERLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[0]->contents,NULL);
	    //printTAC(head->code->content);
	  }

	  if(head->children[2]->children[0]->label == STRINGLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[1]->contents,NULL);
	    //	    printTAC(head->code->content);
	  }
	  
	}
	
	/*
	list* new = concatenateChildren(head);	
	concatenateList(new, head->code);
	head->code = new;
	*/
	
	list* new = concatenateChildren(head);
	list* next = head->code;
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
	}
      }
      break;
      
    case classStatement:
      {
	head->code = newListItem();
	char* title = "ANON";
	if(head->nchildren == 2){
	  //1
	  if(head->children[0]->label == IDENT){
	    title = head->children[0]->contents;
	  }
	}
	else if(head->nchildren == 3){
	  //2
	  if(head->children[1]->label == IDENT){
	    title = head->children[1]->contents;
	  }
	}
	else if(head->nchildren == 3){
	  //1
	  if(head->children[0]->label == IDENT){
	    title = head->children[0]->contents;
	  }
	}
	else if(head->nchildren == 4){
	  //2
	  if(head->children[1]->label == IDENT){
	    title = head->children[1]->contents;
	  }
	}
	
	head->code->content = makeLabeledTAC(title, "class",NULL,NULL,NULL);

	list* endLabel = newListItem();
	endLabel->content = makeLabeledTAC(title,"end", NULL, NULL, NULL);
	
	list* new = concatenateChildren(head);
	/*	list* next = head->code;
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
	  }*/

	concatenateList(head->code, new);
	
	concatenateList(head->code, endLabel);
       }
      break;
      

    case functionDeclaration:
      {
	head->code = newListItem();
	
	list* endLabel = newListItem();

	
	//get ident. use to start the PROC
	char* ident = "ANON";
	char* arg1 = NULL;
	char* arg2 = NULL;
	
	if(head->children[1]->label == IDENT){
	  ident = head->children[1]->contents;
	}
	else if(head->children[2]->label == IDENT){
	  ident = head->children[2]->contents;
	}
	
	head->code->content = makeLabeledTAC(ident,"proc", NULL, NULL, NULL);
	endLabel->content = makeLabeledTAC(ident,"end",  NULL, NULL, NULL);
	list* new = concatenateChildren(head);
	
	if(new != NULL){
	  concatenateList(head->code, new);
	}
	
	
	concatenateList(head->code, endLabel);
      }
      break;
      
    case assignStatement:
      {
	head->code = newListItem();
	char* cmd = NULL;
	char* arg1 = NULL;
	char* arg2 = NULL;
	char* arg3 = NULL;
	
	if(head->children[1]->label == newObject){
	  if(head->children[1]->children[1] != NULL){
	    cmd = "NEWOBJ";
	    arg1 = head->children[0]->contents;
	    arg2 = head->children[2]->children[1]->contents;
	  }
	}
	if(head->children[1]->label == expr){
	  cmd = "ASN";
	  arg1 = head->children[0]->contents;
	  arg2 = head->children[1]->place->name;
	}

	head->code->content = makeTAC(cmd, arg1, arg2, arg3);

	
	list* new = concatenateChildren(head);
	list* next = head->code;
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
	}
      }
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
	
	//left side should never be NULL
	if(head->children[0]->label == expr){
	  arg1 = head->children[0]->place->name;
	}
	if(head->children[0]->label == IDENT){
	  arg1 = head->children[0]->contents;
	}
	if(head->children[0]->label == NUMBERLIT ||
	   head->children[0]->label == STRINGLIT)
	  arg1 = head->children[0]->contents;
	
	//right side MAY be NULL. must check it.
	if(head->children[2] != NULL ){
	  if(head->children[2]->label == expr){
	    arg2 = head->children[2]->place->name;
	  } 
	  //variableName?
	  if(head->children[2]->label == IDENT){
	    arg2 = head->children[2]->contents;
	  }
	  if(head->children[2]->label == NUMBERLIT ||
	     head->children[2]->label == STRINGLIT)
	    arg2 = head->children[2]->contents;
	}
	//	printf("%d\n", head->children[1]->label);
	head->code->content = makeTAC(decideOperator(head), 
				      head->place->name, arg1, arg2);
	
	//printTAC(head->code->content);
	
	list* new = concatenateChildren(head);
	list* next = head->code;
	
	
	if(new != NULL){
	  //	  printf("In expr, printing children: \n");
	  //printTACList(new);
	  //	  printf("In expr, printing me: \n");
	  // printTACList(next);
	  
	  concatenateList(new, head->code);
	  head->code = new;
	}
	else {
	  //do nothing?
	}
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

char* decideOperator(node* operator){
  char* new = new;
  //printf("IM GOING IN! %d\n",operator->label);
  switch(operator->operator){
    //add
  case PLUS:
    new = makeNewString("ADD");
    return new;
    break;
    
    //sub
  case MINUS:
    new = makeNewString("SUB");
    return new;
    break;
    
    //mul
  case MULTIPLY:
    new = makeNewString("MUL");
    return new;
    break;
    
    //div
  case DIVIDE:
    new = makeNewString("DIV");
    return new;
    break;

    //mod
  case MODULO:
    new = makeNewString("MOD");
    return new;
    break;
    
    //we have problems if we get to here!
  case INCREMENT:
    break;
  case DECREMENT:
    break;
  }

  
  return new;;
}

/*
val 53
new 53%10 = 3
val 53/10 = 5
new 5%10 = 5
val 5/10 = 0
*/

//alternate method of concatenating list. deprecated for now. 
void generateTACList(node* head, list* lst){;
  if(head != NULL){
    printf("%d\n", head->label);
    
    switch(head->label){
      
    case packageStatement:
      {
	head->code = newListItem();
	
	if(head->children[0]->contents != NULL){
	  head->code->content = makeLabeledTAC(head->children[0]->contents,
					       NULL, NULL, NULL, NULL);
	}
	/*
	else 
	  head->code->content = makeLabeledTAC("anon_pkg",NULL,NULL,NULL,NULL);
	*/
	
	concatenateList(lst,head->code);
      }
      break;
      
      
    case whileStatement:
      //make new item
      
      //makelabel
      //code
      //endlabel
      
      break;
      
    case functionCall:
      //head->code = newListItem();
      

      break;
      
      
    case variableBinding:
      {
	/*
	      variableBinding (head)
	  name     type     initialization (head->children[2])
	                           assign value (head->children[1])
	 */
	//printf("Variable Binding Here!\n");
	head->code = newListItem();
	if(head->children[2] != NULL){
	  if(head->children[2]->children[1]->label == expr){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[1]->place->name,NULL);
	    // printTAC(head->code->content);
	  }
	  
	  if(head->children[2]->children[1]->label == NUMBERLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[1]->contents,NULL);
	    //printTAC(head->code->content);
	  }

	  if(head->children[2]->children[1]->label == STRINGLIT){
	    head->code->content = makeTAC("ASN", head->children[0]->contents,
			   head->children[2]->children[1]->contents,NULL);
	    //	    printTAC(head->code->content);
	  }
	  
	}
	
	
	concatenateList(lst,head->code);
      }
      break;
      
      
    case assignStatement:
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
	
	//left side should never be NULL
	if(head->children[0]->label == expr){
	  arg1 = head->children[0]->place->name;
	}
	if(head->children[0]->label == IDENT){
	  arg1 = head->children[0]->contents;
	}
	if(head->children[0]->label == NUMBERLIT ||
	   head->children[0]->label == STRINGLIT)
	  arg1 = head->children[0]->contents;
	
	//right side MAY be NULL. must check it.
	if(head->children[2] != NULL ){
	  if(head->children[2]->label == expr){
	    arg2 = head->children[2]->place->name;
	  } 
	  //variableName?
	  if(head->children[2]->label == IDENT){
	    arg2 = head->children[2]->contents;
	  }
	  if(head->children[2]->label == NUMBERLIT ||
	     head->children[2]->label == STRINGLIT)
	    arg2 = head->children[2]->contents;
	}
	//	printf("%d\n", head->children[1]->label);
	head->code->content = makeTAC(decideOperator(head->children[1]), 
				      head->place->name, arg1, arg2);
	
	//printTAC(head->code->content);
	
	concatenateList(lst, head->code);
      }
      break;      

    case expression:
      head->code = newListItem();
      
      
      
      break;
      

    default:
      
      break;
    }

    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	generateTACList(head->children[i], lst);
      }
    }
    
    

    
  }  
}


