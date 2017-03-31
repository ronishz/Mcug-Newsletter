/*program to recognize a valid variable which start with a letter, followed by any number of tokens or digit*/
%{
#include<math.h>
#include<stdio.h>
extern int yyparse();
extern int yylex();
extern int yyerror(char *e);
%}
%token num
%token var
%%
s : stmt { printf("valid") ; exit(0);}
 ;
stmt : stmt num
     | stmt var
     | var
    ;
%%
int  main()
{ 
yyparse();
}
extern int yyerror(char *e)
{
printf("syntax error:::");
}

