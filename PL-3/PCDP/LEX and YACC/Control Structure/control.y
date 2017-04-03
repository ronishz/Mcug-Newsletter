%{
	#include<math.h>
	#include<stdio.h>
	extern int yyparse();
	extern int yylex();
	extern int yyerror(char* e);
%}
%token var
%token dig
%token KW
%token OCB
%token CCB
%token OB
%token CB
%token op
%token asg
%token condn
%token SC
%start s
%%

s : KW OB condition CB OCB stmt CCB {printf("\nValid!!!\n"); exit(0);}

stmt 	: exp SC | stmt stmt | s

exp	: var asg exp
	| exp op exp
	| var op var
	| dig op dig
	| var op dig
	| dig op var
	| var 
	| dig

condition : var condn var 
	  | var condn dig
	  | var
	  | '1'
	  | '0'
	
%%
int main(){
	yyparse();
}
extern int yyerror(char* e){
printf("Syntax Error!!!\n");
}
