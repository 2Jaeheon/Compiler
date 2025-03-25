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
/* 이 곳에 Rules를 넣으면 됨*/
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
