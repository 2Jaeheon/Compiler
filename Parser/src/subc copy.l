/*                                                                          */
/* File Name    : subc.l                                                    */
/* Description  : a skeleton flex input                                     */
/*                                                                          */
/* Course       : Compiler                                                  */
/*                                                                          */

%{
/* C Code Section */
/* Any code placed inside the brackets will be literally copied into the generated C file. */

#include <stdio.h>
#include <strings.h>
#include "subc.tab.h"
%}

/* Definitions Section */
/* This section contains simple name definitions and declarations of start conditions. */

letter        [A-Za-z_]
digit         [0-9]
integer_const ([1-9]{digit}*)|"0"
whitespace    [ \t]
special_char  \\[nt]

%%
  /* Rules Section */
  /* This section contains series of rules for recognizing tokens. */

  /* Keywords */
"int" | "char"                  { return TYPE; }
"struct"                        { return STRUCT; }
"NULL"  { return SYM_NULL; }
"return"  { return RETURN; }
"if"  { return IF; }
"else"  { return ELSE; }
"while"  { return WHILE; }
"for" { return FOR; }
"break" { return BREAK; }
"continue"  { return CONTINUE; } 

  /* 논리 연산자 Logical Operators */
"||"  {return LOGICAL_OR; }
"&&"  {return LOGICAL_AND; }

  /* 관계 연산자 Relational Operators */
"==" | "!=" { return EQUOP; }
"<" | "<=" | ">" | ">="  { return RELOP; }

  /* 증감 연산자 */
"++"  { return INCOP; }
"--"  { return DECOP; }

  /* 화살표 연산자 */
"->"  { return STRUCTOP; }



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
";"|","                         { return yytext[0]; }
"+"|"-"|"*"|"/"|"%"|"="|"!"|"&"|"("|")"|"["|"]"|"{"|"}"|"."  { return yytext[0]; }

  /* Whitespaces */
{whitespace}                    {}


%%
   
/* User Code Section */
/* The user code section is simply copied to lex.yy.c verbatim. */

int main(int argc, char* argv[]) {
  // I/O stream settings
  if (argc >= 2) {
    yyin = fopen(argv[1], "r");
  } else {
    yyin = stdin;
  }

  if(!yyin) {
    printf("Can't open input stream!\n");
    exit(1);
  }
  
  yyparse();
  fclose(yyin);
  
  return 0;
}
