/* program to test the validity of a simple expression involving operators +,*etc.*/

%{
#include "y.tab.h"
extern int yyerror(char * e);
extern int yylval;
%}
%%
[a-z]+ {return VAR;}
[0-9]+ {return NUM;}
[+/]  {return op;}
[*]  {return op1;}
[=] {return op2;}
%%
extern int yywrap()
{ 
return (1);
}
