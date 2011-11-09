#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>
#include "symbolTable.h"
#include "dataPacks.h"

typedef struct node {
  int nchildren; 
  int label;
  token* tok;
  struct symbolTable* table;
  struct node** children;
  char* nodeType;
  struct symbolTable* targetScope;
} node;

//  symbolTable* parent;
//node* makeNode(char* text,symbolTable* parent, token* tok, int nchildren, ...);
node* makeNode(int label, symbolTable* parent,  token* tok, int nchildren, ...);
node* getVariable( symbolTable* scope, node* var );
void yysemantics(node* head);
void populateSymbolTables(node* head, node* parent_node);
void buildSymbolTables(node* head, node* parent_node);
void functionHandler(node* var, node* parent_node);
void variableHandler(node* var, node* parent_node, variableDataPack* data);
void checkIdentsInInitialization(node* head, node* root);
void parseVariableName(node* var, node* parent_node);
void assignmentHandler( node* var, node* parent_node );
void classHandler(node* var, node* parent_node);
char* getOptionalNodeType( node* var );
void traverseTree(node* head,node* parent_node, int level);
int comparetypes( node* var, node* parent_node);
node* miniTraverse( node* head, int label );

#endif
