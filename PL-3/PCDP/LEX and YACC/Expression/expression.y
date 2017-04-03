%{
        #include<math.h>
        #include<stdio.h>
        extern int yyparse();
        extern int yylex();
        extern int yyerror(char* e);
%}
%token NUM
%token var
%token op
%token asg
%start s
%%

s : var asg exp { printf("\nValid!!!\n"); exit(0);}

exp : exp op exp 
    | exp op var
    | NUM op NUM
    | var op var
    | var op NUM
    | NUM op var
    | NUM
    | var

%%
int main(){
        yyparse();
}
extern int yyerror(char* e){
printf("Syntax Error!!!\n");
}
