%{
#include "y.tab.h"
#include<stdio.h>
extern int yerror(char* e);
extern int yylval;
%}
dig [0-9]+
let [a-zA-Z]+
condn  (==|<=|>=|<|>|!=)
%%
{dig}+ {printf("dig ");return dig;}
"while"|"if" {printf("keyword ");return KW;}
{let}({let}|{dig})* {printf("var ");return var;}
[{]* {printf("ocb ");return OCB;}
[}]* {printf("ccb ");return CCB;}
[(]* {printf("ob ");return OB;}
[)]* {printf("cb ");return CB;}
[ + | - | * | / | % ]+ {printf("op ");return op;}
[;] {printf("sc ");return SC;}
{condn} {printf("condn ");return condn;}
[=] {printf("asg ");return asg;}
%%
extern int yywrap(){
	return (1);
}
