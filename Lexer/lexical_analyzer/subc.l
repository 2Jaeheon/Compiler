%{
/**************************************************************
* File Name   : subc.l
*
* Description
*	This is a skeleton input file to lex.
*
* Which tool to use
*	The GNU lex-clone, flex/flex++ is recommended to use.
*	It supports a C++ mode.
*	For any information about flex, refer to flex.man.
*
*	Good Luck!
*
***************************************************************/

/**************************************************************/
/* This section will appear at the head of lex.yy.c/lex.yy.cc */
/**************************************************************/

/***************************************************************
{Other useful code segments can be here.}
***************************************************************/
int commentdepth=0;
%}

letter      [A-Za-z_]
digit       [0-9]
id  		{letter}({letter}|{digit})*
op1         [+-=]
op2 		(\(|\)|\{|\}|\;)
operator	{op1}|{op2}
whitespace	[ \t\n]+
integer-constant -?{digit}+
float-constant -?{digit}+.{digit}*((eE)[+-]?{digit}+)?

/* CODE 모드와 COMMENT 모드로 나뉘어져 있음. */
%start CODE COMMENT

%%
/* Keywords! */
<CODE>"auto" {printf("KEY\t%s\n", yytext);}
<CODE>"break" {printf("KEY\t%s\n", yytext);}
<CODE>"case" {printf("KEY\t%s\n", yytext);}
<CODE>"char" {printf("KEY\t%s\n", yytext);}
<CODE>"continue" {printf("KEY\t%s\n", yytext);}
<CODE>"default" {printf("KEY\t%s\n", yytext);}
<CODE>"do" {printf("KEY\t%s\n", yytext);}
<CODE>"double" {printf("KEY\t%s\n", yytext);}
<CODE>"else" {printf("KEY\t%s\n", yytext);}
<CODE>"extern" {printf("KEY\t%s\n", yytext);}
<CODE>"float" {printf("KEY\t%s\n", yytext);}
<CODE>"for" {printf("KEY\t%s\n", yytext);}
<CODE>"goto" {printf("KEY\t%s\n", yytext);}
<CODE>"if" {printf("KEY\t%s\n", yytext);}
<CODE>"int" {printf("KEY\t%s\n", yytext);}
<CODE>"long" {printf("KEY\t%s\n", yytext);}
<CODE>"register" {printf("KEY\t%s\n", yytext);}
<CODE>"return" {printf("KEY\t%s\n", yytext);}
<CODE>"short" {printf("KEY\t%s\n", yytext);}
<CODE>"sizeof" {printf("KEY\t%s\n", yytext);}
<CODE>"static" {printf("KEY\t%s\n", yytext);}
<CODE>"struct" {printf("KEY\t%s\n", yytext);}
<CODE>"switch" {printf("KEY\t%s\n", yytext);}
<CODE>"typedef" {printf("KEY\t%s\n", yytext);}
<CODE>"union" {printf("KEY\t%s\n", yytext);}
<CODE>"unsigned" {printf("KEY\t%s\n", yytext);}
<CODE>"void" {printf("KEY\t%s\n", yytext);}
<CODE>"while" {printf("KEY\t%s\n", yytext);}
%%

int main (int argc, char** argv)
{
	struct id* temp;
	++argv, --argc;
	if (argc > 0) {
		yyin = fopen (argv[0], "r");
	} else {
		yyin = stdin;
	}
	BEGIN CODE;
	yylex ();
	return 0;
}
