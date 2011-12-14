#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>
#include "symbolTable.h"
#include "dataPacks.h"
#include "semanticAnalysis.h"


typedef struct node {
  //for tree control
  int nchildren; 
  int label;
  struct node** children;
  
  //for data contained within the node
  token* tok; //deprecated
  char* contents;
  int operator;
  int lineno;
  char* filename;

  
  //semantic analysis stuff
  char* nodeType;
  struct symbolTable* table;
  struct symbolTable* targetScope;
  int usage;

  //specific to functions
  list* args;
  int numArgs;
  
  //stuff for code gen
  list* code;
  field* place;
} node;

//  symbolTable* parent;
//node* makeNode(char* text,symbolTable* parent, token* tok, int nchildren, ...);
node* makeNode(int label, symbolTable* parent,  token* tok, int nchildren, ...);
void updateNodeWithToken(node* head, token* tok);
void printNodeDetails(node* head);
void printNodeDetailsVerbose(node* head);




void checkIdentsInInitialization(node* head, node* root);
void parseVariableName(node* var, node* parent_node);
void assignmentHandler( node* var, node* parent_node );
void traverseTree(node* head,node* parent_node, int level);
int comparetypes( node* var, node* parent_node);
node* miniTraverse( node* head, int label );
list* buildArgList(node* head, list* lst);

/*
deprecated
void classHandler(node* var, node* parent_node);
void functionHandler(node* var, node* parent_node);
void functionHandlerSmall(node* var);
*/

#endif
