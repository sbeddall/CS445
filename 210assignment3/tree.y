%{
#include "treeClass.h"
#include <stdlib.h>
#include <cassert>
#include <stdio.h>
#include <iostream>
#include <string>

  using namespace std;

  extern int yylex();
  extern char* yy_scan_string(const char *msg);
  extern void yy_delete_buffer(char *msg);
  //define our error catching
#define YYERROR_VERBOSE


  extern int yyerror(char *m){
    //  cout<<"Error Occured: "<<m<<endl;
  }


  //use for variables
  Node* vars[26];
 
  /*different set command
  float def_translate_x=72.0;
  float def_translate_y=0;
  float def_rotation=0;
  float def_scale_x=1.0;
  float def_scale_y=1.0;
  float def_spacing=20.0;
  float def_length=5.0; */

  //booleans, is show on (1) or off (0)
  //might not need these
  int debug=0;

  Node* dummy=new Node();

%}

%union {
  Node* node_; 
  char* s_val;
  // float num_float;
  float num;
  int var;
}
//types
%type <node_>node
%type <node_>node_seq
%type <node_>tree
%type <node_>command


 //tokens
%token <s_val> NAME //duplicated character pointer
%token NEWNODE //'('
%token ENDNODE //')'
%token AND //','
%token <var>VAR //single character
%token END //';'
%token <num>NUM //number, double
%token NUM_FLOAT  // or float
%token EDGE
%token ENDLINE


 //commands

%token DRAW
%token SHOW
%token <num>TRANSLATE
%token DEFAULT_LEN
%token SPACING
%token SCALE
%token VARIABLE
%token DEBUG
%token ROTATE
%token ASSIGN


%%

loop: loop command
    | command
    ;

command : DRAW tree {$$=$2; $$->draw();}  
        | SHOW tree {$$=$2; $$->display();} 
        | tree {$$=$1;}
        | DEBUG {yydebug=1;}
        | VAR ASSIGN tree {vars[$1]=$3;}
        | TRANSLATE NUM NUM {dummy->setTranslate($2,$3)}
        | SCALE NUM NUM {dummy->setScale($2,$3);}
        | ROTATE NUM {dummy->setRotate($2);}
        | SPACING NUM {dummy->setYDelta($2);}
        | DEFAULT_LEN NUM {dummy->setMinLen($2);}
        | ENDLINE
        ;

tree : node END {$$=$1;} 
     ;

node_seq : node_seq AND node {$$=$1; $$->addSibling($3);}
         | node {$$=$1;}
         ;

node : NEWNODE node_seq ENDNODE EDGE NUM {$$=new Node(); $$->setLen($5); $$->setChild($2);}
     | NEWNODE node_seq ENDNODE NAME {$$=new Node(); $$->setName($4); $$->setChild($2);}
     | NEWNODE node_seq ENDNODE NAME EDGE NUM {$$=new Node(); $$->setName($4); $$->setLen($6); $$->setChild($2);}
     | NEWNODE node_seq ENDNODE {$$=new Node(); $$->setChild($2);}
     | NAME EDGE NUM {$$=new Node(); $$->setName($1); $$->setLen($3);}
     | NAME {$$=new Node(); $$->setName($1);}
     | VAR EDGE NUM{$$=new Node(); $$=vars[$1]->copy(); $$->setLen($3);} //set minlen or set len?
     | VAR {$$=new Node(); $$=vars[$1]->copy();} 
     | tree {$$=$1;}
     ;

%%



bool passes(char *str) {
  char* my_string_buffer = yy_scan_string(str);
  int ret_val = yyparse();
  return (ret_val == 0);
}

bool fails(char *str) {
  return !passes(str);
}



int main(){
  yyparse();
  /*enter wall of assertions for use in checking grammar
  assert(passes("cats;"));
  assert(passes("(cats);"));
  assert(passes("cats:45;"));
  assert(passes("(cats:300);"));
  assert(passes("((((cats))));"));
  assert(passes("(cats):34;"));
  assert(passes("((cats):34):37;"));
  assert(passes("(cats, dogs, fish);"));
  assert(fails("cats, dogs, fish;"));
  assert(passes("((cats), (dogs), (fish));"));
  assert(passes("(ant:17, (bat:31, cow:22):7);"));
  assert(passes("( (raccoon:19, bear:7):3, ((sea_lion:12, seal:12):7, ((monkey:100, cat:47):20, weasel:19 ):4 ):4, dog:25 ):10;"));
  assert(passes("(Bovine:69, (Gibbon:36));"));
  assert(passes("(Bovine:69, (Gibbon:36, (Orang:33, (Gorilla:17, (Chimp:19,  Human:11):8):6):15):54, Mouse:121):30;"));
  assert(passes("((cow:22, gnu:30)bigThings:3, (ant:43, termite:9)smallThings:25)root;"));
  assert(passes("((\"cute cows\":12, \"dusty gnus\":10)\"big things\":3, (ant:23, bat:19)\"small things\":5);"));
  assert(passes("(cows:12, \"dusty gnus\":10):6;"));
  assert(passes("(((ants, bats, cows, dogs, eels), (((xxx))), (foxs, gnus, (hogs, ibex, (junko, kiwi)))));"));
  assert(passes("draw (ants, (bats, cows, dogs, eels):34, ((foxs))vixen, gnus, (hogs, ibex))root:23;"));
  assert(passes("show (cats,dogs);"));
  assert(passes("debug"));
  assert(passes("#v = (cats,dogs);"));
  assert(passes("translate 30.0 30.0"));
  assert(passes("rotate 30.0"));
  assert(passes("scale 30.0"));
  assert(passes("spacing 30.0"));
  assert(passes("defaultlen 30.0"));
  assert(passes("bye"));
  assert(passes("exit"));
  */
  return 0;
}
