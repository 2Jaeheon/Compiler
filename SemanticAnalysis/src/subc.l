/*                                                                          */
/* File Name    : subc.l                                                    */
/* Description  : a skeleton flex input                                     */
/*                                                                          */

%{

/* C Code Section */
/* Any code placed inside the brackets will be literally copied into the generated C file. */

#include "subc.h"
#include "subc.tab.h"
static int lineno = 1;
static char* file_name;

%}

/* Definitions Section */
/* This section contains simple name definitions and declarations of start conditions. */

letter        [A-Za-z_]
digit         [0-9]
id            {letter}({letter}|{digit})*
integer_const ([1-9]{digit}*)|"0"
whitespace    [ \t]
special_char  \\[nt]

%x COMMENT

%%

  /* Rules Section */
  /* This section contains series of rules for recognizing tokens. */
 
  /* Keywords */
"int"|"char"                    { 
                                  /* 이게 없으면 Bison에서 $1이 NULL이 되어 세그폴트 발생 */
                                  yylval.stringVal = strdup(yytext);
                                  /* 타입 토큰을 반환 */
                                  return TYPE; 
                                }
"struct"                        { return STRUCT; } 
"NULL"                          { return SYM_NULL; }
"return"                        { return RETURN; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"while"                         { return WHILE; }
"for"                           { return FOR; }
"break"                         { return BREAK; }
"continue"                      { return CONTINUE; }

  /* Identifiers */
{id}                            {
                                  /* 식별자 (변수명 등)는 ID 토큰으로 반환되고 문자열 값을 저장 */
                                  yylval.stringVal = strdup(yytext);
                                  /* 식별자 토큰을 반환 */
                                  return ID;
                                }

  /* Integer constants */
{integer_const}                 {
                                  return INTEGER_CONST;
                                }

  /* String variables */
\"({special_char}|[^\\\"\n])*\" {
                                  return STRING;
                                }

  /* Character variables */
'({special_char}|[^\\'\n])'     {    
                                  return CHAR_CONST;
                                }

  /* Operators */
","|";"|"("|")"|"["|"]"|"{"|"}" { return yytext[0]; }
"!"|"*"|"/"|"%"|"+"|"-"|"&"     { return yytext[0]; }
"="|"."                         { return yytext[0]; }

"&&"                            { return LOGICAL_AND; }
"||"                            { return LOGICAL_OR; }
"<"|"<="|">"|">="               { return RELOP; }
"=="|"!="                       { return EQUOP; }
"++"                            { return INCOP; }
"--"                            { return DECOP; }
"->"                            { return STRUCTOP; }

  /* Whitespaces */
{whitespace}


  /* Comment blocks */
"/*"                            {
                                  BEGIN (COMMENT);
                                }
<COMMENT>"*/"                   { 
                                  BEGIN (INITIAL);
                                }
<COMMENT>.

  /* Line number tracking */
<*>\n       { ++lineno; }

%%
   
/* User Code Section */
/* The user code section is simply copied to lex.yy.c verbatim. */

int get_lineno() {
   return lineno;
}

int main(int argc, char* argv[]) {
  if(argc >= 2) {
    yyin = fopen(argv[1], "r");
  } else {
    yyin = stdin;
  }

  if(!yyin) {
    printf("Can't open input stream!\n");
    exit(1);
  }
  init_symbol_system();
  yyparse();
  fclose(yyin);

  return 0;
}
