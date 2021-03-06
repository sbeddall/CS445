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

/*
  Get If statement done
  get offsets done
  get local parameter space figured out
  ^^^ applies to classes,packages,functions
*/


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
  
  TAC* content = makeLabeledTAC("BEGIN", 0, NULL, NULL, NULL);
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
	//special cases for places
	/*if(head->nchildren == 1){
	  field* location = getField( head->table, head->children[0]->contents );
	  head->place = location;
	  }*/
	//add new variable to symbol table.
	//set place to that variable in symbol table.
	char* new = newVariable( head->table );
	
	field* location = getField( head->table, new );
	head->place = location;
	//printTable(head->table,0);
      }
      break;

    case expression:
      {
	char* new = newVariable( head->table );
	field* location = getField( head->table, new );
	head->place = location;
      }
      break;

    case functionCall:
      {
	char* new = newVariable( head->table );
	field* location = getField( head->table, new);
	
	head->place = location;
	break; 
      }
           
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
						 package, NULL, NULL, NULL);
	    endLabel->content = makeLabeledTAC(head->children[0]->contents,end, NULL, NULL, NULL);
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
      
      
          
    case functionCall:
      {
	head->code = newListItem();
	
	//build list.
	
	if(head->children[1] != NULL){
	  list* args = createArgumentTAC(head->children[1], NULL);
	  int numArgs = getNumArgs(head->children[1], 0);
	  char* buf = (char*)malloc(sizeof(char)*10);
	  itoa(numArgs,buf);
	    
	  concatenateList(args, head->code);
	  
	  head->code->content = makeTAC(CALL,head->children[0]->contents,
					buf,head->place->name);
	  
	  head->code = args;
	  
	}
	else {
	  head->code->content = makeTAC(CALL,head->children[0]->contents,
					"0",head->place->name);
	}
	
	list* new = concatenateChildren(head);
	list* next = head->code;
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
	}
      }
      break;
      
    
      
      
    case variableBinding:
      {
	/*
	  variableBinding (head)
	  name     type     initialization (head->children[2])
	  assign value (head->children[1])
	*/
	head->code = newListItem();
	if(head->children[2] != NULL){

	  if(head->children[2]->children[0]->place != NULL){
	    head->code->content = makeTAC(ASN, head->children[0]->contents,
					  head->children[2]->children[0]->place->name, NULL);
	  }
	  else {
	    head->code->content = makeTAC(ASN, head->children[0]->contents,
					  head->children[2]->children[0]->contents, NULL);
	  }

	}
	
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
	
	head->code->content = makeLabeledTAC(title, class,NULL,NULL,NULL);

	list* endLabel = newListItem();
	endLabel->content = makeLabeledTAC(title,end, NULL, NULL, NULL);
	
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
	
	head->code->content = makeLabeledTAC(ident,proc, NULL, NULL, NULL);
	endLabel->content = makeLabeledTAC(ident,end,  NULL, NULL, NULL);
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
	int cmd = 0;
	char* arg1 = NULL;
	char* arg2 = NULL;
	char* arg3 = NULL;
	
	/*
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
	*/

	if(head->children[1]->place == NULL){
	  cmd = ASN;
	  arg1 = head->children[0]->contents;
	  arg2 = head->children[1]->contents;
	}
	else {
	  cmd = ASN;
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
      
    case whileStatement:
      {
	//while statement
	list* bnif = newListItem();
	char* existing = newLabel();
	char* endLabel = newLabel();
	list* rest = NULL;
	list* expressionCode = NULL;
	list* end = newListItem();
	list* gotoTAC = newListItem();
	
	if(head->children[0]->place != NULL){
	  expressionCode = head->children[0]->code;
	  labelExistingTAC(existing, expressionCode->content);
	  
	  bnif->content = makeTAC(BNIF, head->children[0]->place->name,endLabel,NULL);
	  concatenateList(expressionCode,bnif); 
	}
	if(head->children[1] != NULL){
	  rest = concatenateChildren(head->children[1]);
	}
	
	gotoTAC->content = makeTAC(GOTO, existing, NULL,NULL);
	end->content = makeLabeledTAC(endLabel, -1, NULL,NULL,NULL);
	concatenateList(gotoTAC, end);
	
	//head->code = concatenateChildren(head->children[1]);
	
	concatenateList(expressionCode, rest);
	concatenateList(expressionCode, gotoTAC);

	head->code = expressionCode;
      }
      break;

    case ifStatement:
      {
	char* beginLabel = newLabel();
	char* endLabel = newLabel();
	char* elseLabel = newLabel();
	
	list* bnif = newListItem();
	list* ifCode = NULL;
	list* elseCode = NULL;
	
	if(head->children[0]->place != NULL){
	  ifCode = head->children[0]->code;
	  labelExistingTAC(beginLabel,ifCode->content);
	    
	  bnif->content = makeTAC(BNIF, head->children[0]->place->name, elseLabel, NULL);
	  concatenateList(ifCode,bnif);
	  concatenateList(ifCode,concatenateChildren(head->children[1]));
	}
	elseCode = newListItem();
	elseCode->content = makeLabeledTAC(elseLabel, -1, NULL, NULL, NULL);
	
	if(head->children[2] != NULL){
	  concatenateList(elseCode, concatenateChildren(head->children[2]->children[0]));
	}

	concatenateList(ifCode, elseCode);

	
	head->code = ifCode;
      }
      break;

    case expr:
      {
	head->code = newListItem();
	char* arg1 = NULL;
	char* arg2 = NULL;
	

	if(head->children[0]->place != NULL){
 
	  arg1 = head->children[0]->place->name;
	}
	else {
	  arg1 = head->children[0]->contents;
	}
	
	if(head->children[1] != NULL){
	  if(head->children[1]->place != NULL){
	    arg2 = head->children[1]->place->name;
	  }
	  else {
	    arg2 = head->children[1]->contents;
	  }
	}

	
	if(head->operator == INCREMENT){
	  head->code->content = makeTAC(ADD, 
					arg1, "1", NULL);
	}
	else if(head->operator == DECREMENT){
	  head->code->content = makeTAC(SUB, 
					arg1, "1", NULL);
	}
	else
	  head->code->content = makeTAC(decideOperator(head), 
					head->place->name, arg1, arg2);
	
	list* new = concatenateChildren(head);
	list* next = head->code;
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
	}
	//else head->code = concatenateChildren(head);
      }
      break;      

    case iterationStatement:
      {
	head->code = newListItem();
	if(head->operator == INCREMENT){
	  head->code->content = makeTAC(ADD, 
					head->children[0]->contents, "1", NULL);
	}
	else if(head->operator == DECREMENT){
	  head->code->content = makeTAC(SUB, 
					head->children[0]->contents, "1", NULL);
	}

	list* new = concatenateChildren(head);
	
	if(new != NULL){
	  concatenateList(head->code,new);
	}
	
      }
      break;

    case expression:
      {
	head->code = newListItem();
	char* arg1 = NULL;
	char* arg2 = NULL;
	
	if(head->children[0]->place != NULL){
	  arg1 = head->children[0]->place->name;
	}
	else {
	  arg1 = head->children[0]->contents;
	}
	
	if(head->children[1] != NULL){
	  if(head->children[1]->place != NULL){
	    arg2 = head->children[1]->place->name;
	  }
	  else {
	    arg2 = head->children[1]->contents;
	  }
	}
	
	head->code->content = makeTAC(decideOperator(head), 
				      head->place->name, arg1, arg2);
	 
	//printTACList(head->code);
	
	list* new = concatenateChildren(head);
	
	if(new != NULL){
	  concatenateList(new, head->code);
	  head->code = new;
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


//I'm actually reall happy with this function. it works!
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

int decideOperator(node* operator){

  //printf("IM GOING IN! %d\n",operator->label);
  switch(operator->operator){
    //add
  case PLUS:
    return ADD;
    break;
    
    //sub
  case MINUS:
    return SUB;
    break;
    
    //mul
  case MULTIPLY:
    return MUL;
    break;
    
    //div
  case DIVIDE:
    return DIV;
    break;

    //mod
  case MODULO:
    return MOD;
    break;
    
    //now logical operators!
  case LESSTHAN:
    return LT;
    break;
    
  case GREATERTHAN:
    return GT;
    break;
    
  case EQUALSEQUALS:
    return EQ;
    break;

  case STRICTEQUALS:
    break;

  case STRICTNOTEQ:
    break;

  case GTHANEQ:
    return GTE;
    break;

  case LTHANEQ:
    return LTE;
    break;

  case NOTEQUAL:
    break;

  case NOT:
    break;

  case NOTEQUALEQUAL:
    break;
 
  case LOGICALAND:
    break;
    
  case LOGICALOR:
    break;

    //we have problems if we get to here!
  case INCREMENT:
    break;
    
  case DECREMENT:
    break;
  }

  
  return 0;
}


list* createArgumentTAC(node* head, list* lst){
  switch(head->label){
  case valueList:
    {
      if(lst == NULL){
	lst = newListItem();
	lst->content = makeTAC(PARM,head->children[0]->contents,NULL,NULL);
      }
      else {
	genericAdd(lst,makeTAC(PARM,head->children[0]->contents,NULL,NULL));
      }
      
      return createArgumentTAC(head->children[1],lst);
    }
    break;
  default:
    {
      if(lst == NULL){
	lst = newListItem();
	lst->content = makeTAC(PARM,head->contents,NULL,NULL);
      }
      else {
	genericAdd(lst,makeTAC(PARM,head->contents,NULL,NULL));
      }
      return lst;
    }
  }
}



/*
val 53
new 53%10 = 3
val 53/10 = 5
new 5%10 = 5
val 5/10 = 0
*/

//alternate method of concatenating list. deprecated for now. 
/*
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

      break;
      
      
    case variableBinding:
      {
	/*
	      variableBinding (head)
	  name     type     initialization (head->children[2])
	                           assign value (head->children[1])
	 
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
	case mathvalue
	case expr sign expr
	case expr++
       
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


*/
