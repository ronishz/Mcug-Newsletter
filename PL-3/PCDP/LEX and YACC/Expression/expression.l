%{
        #include "y.tab.h"
        #include<stdio.h>
        extern int yyerror(char* e);
        extern int yylval;
%}
let [a-zA-Z]+
dig [0-9]+
%%
{dig}+ { printf("num ");return NUM;}
{let}({let}|{dig})* { printf("var ");return var;}
[=]  { printf("asg ");return asg;}
[ + | \- | * | / | % ] { printf("op ");return op;}
%%
extern int yywarp()
{ 
        return (1);
}
