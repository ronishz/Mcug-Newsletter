/* program to recognize a valid variable which start with a letter, followed by any number of tokens or digit*/

%{
#include "y.tab.h"
extern int yyerror(char * e);
extern int yylval;
%}
%%
[a-z]+ {return var;}
[0-9]+ { return num;}
. { return yytext[0];}
%%
extern int yywarp()
{ 
return (1);
}
