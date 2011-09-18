%{
#include "treeClass.h"
#include "tree.tab.h"
#include <iostream>
#include <cstdio>
  using namespace std;
%}

%%

"//".*                            {;}
"exit"                            {exit (0);}
"bye"                             {exit (0);}
"quit"                            {exit (0);}
"show"                            {return SHOW;}
"debug"                           {yylval.num=atof(yytext);return DEBUG;}
"draw"                            {yylval.num=atof(yytext);return DRAW;}
"translate"                       {yylval.num=atof(yytext);return TRANSLATE;}
"rotate"                          {yylval.num=atof(yytext);return ROTATE;}
"scale"                           {yylval.num=atof(yytext);return SCALE;}
"spacing"                         {yylval.num=atof(yytext);return SPACING;}
"defaultlen"                      {yylval.num=atof(yytext);return DEFAULT_LEN; }
"("                               {return NEWNODE;}
")"                               {return ENDNODE;}
([0-9]*\.?[0-9]+)|([0-9]*".")     {yylval.num=atof(yytext);return NUM;}
#[a-zA-Z]+                        {
                                   int temp=yytext[1];
                                   temp=temp-'a';
                                   yylval.var=temp;
                                   return VAR;
                                  }
  
\"[^\"]*\"                        {
                                   yytext[strlen(yytext)-1]='\0';
                                   yylval.s_val=strdup(yytext+1);
                                   return NAME;
                                  }

[a-zA-Z]([a-zA-Z0-9\.\_\-]+)?     {
                                   yylval.s_val=strdup(yytext);
                                   return NAME;
                                  }

"="                               {return ASSIGN;}
","                               {return AND;}
":"                               {return EDGE;}
"\n"                              {return ENDLINE;}
";"                               {return END;}
.                                 {;}

%%


//cout<<"EOL"<<endl;} //cout<<"Exit"<<endl;} //cout<<"Exit"<<endl;}
//cout<<"Exit"<<endl;} //cout<<"Variable "<<yytext+1<<endl;}
//cout<<"String "<<"\""<<yytext<<"\""<<endl;} //cout<<"Start internal
//node"<<endl;} //cout<<"End internal node"<<endl;}
//cout<<"Draw"<<endl;} //cout<<"and"<<endl;} //cout<<"End of
//tree"<<endl;} //printf("Number %8.3f\n",atof(yytext))
//cout<<"String "<<yytext<<endl;
// //return ENDLINE;}
