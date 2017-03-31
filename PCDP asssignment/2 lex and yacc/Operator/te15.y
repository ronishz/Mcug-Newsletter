/* program to test the validity of a simple expression involving operators +,*etc.*/
%{
#include<math.h>
#include<stdio.h>
extern int yyparse();
extern int yylex();
extern int yyerror(char *e);
%}
%token NUM
%token op
%token op1
%token VAR
%token op2
%%
s :ID EQU exp { printf("valid") ; exit(0);}
 
ID : VAR

EQU : op2 

exp : exp op NUM
    | exp op VAR
    | exp op1 NUM
    | exp op1 VAR
    | NUM
    | VAR
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

