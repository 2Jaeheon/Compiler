/*
 * File Name    : subc.y
 * Description  : a skeleton bison input
 * 
 * Course       : Compiler
 */

%{
/* Prologue section */
#include <stdio.h>
#include <strings.h>

int   yylex ();
int   yyerror (char* s);
void  reduce(char* s);
%}

/* Bison declarations section */
/* Precedences and Associativities */
%left ','                   
%right '='                 
%left LOGICAL_OR           
%left LOGICAL_AND          
%left EQUOP                
%left RELOP                
%left '+' '-'              
%left '*' '/' '%'
     
%left '[' '.' '('
%left STRUCTOP INCOP DECOP
%right '!' '&' DEREF

%nonassoc LOWER_THAN_ELSE UMINUS
%nonassoc ELSE

/* Tokens */
%token TYPE STRUCT SYM_NULL RETURN
%token INTEGER_CONST CHAR_CONST STRING
%token IF ELSE WHILE FOR BREAK CONTINUE
%token LOGICAL_OR LOGICAL_AND
%token RELOP EQUOP INCOP DECOP STRUCTOP
%token ID


%%
/* Grammar rules section*/
program
: ext_def_list  { printf("program->ext_def_list\n"); }
;

ext_def_list
: ext_def_list ext_def  { printf("ext_def_list->ext_def_list ext_def\n"); }
| %empty  { printf("ext_def_list->epsilon\n"); }

;

ext_def
: type_specifier pointers ID ';'  { printf("ext_def->type_specifier pointers ID ';'\n"); }
| type_specifier pointers ID '[' INTEGER_CONST ']' ';'  { printf("ext_def->type_specifier pointers ID '[' INTEGER_CONST ']' ';'\n"); }
| STRUCT ID '{' def_list '}' ';'  { printf("ext_def->STRUCT ID '{' def_list '}' ';'\n"); }
| func_decl compound_stmt  { printf("ext_def->func_decl compound_stmt\n"); }
;

type_specifier
: TYPE  { printf("type_specifier->TYPE\n"); }
| struct_specifier  { printf("type_specifier->struct_specifier\n"); }
;

struct_specifier
: STRUCT ID '{' def_list '}'  { printf("struct_specifier->STRUCT ID '{' def_list '}'\n"); }
| STRUCT ID  { printf("struct_specifier->STRUCT ID\n"); }
;

func_decl
: type_specifier pointers ID '(' ')'  { printf("func_decl->type_specifier pointers ID '(' ')'\n"); }
| type_specifier pointers ID '(' param_list ')'  { printf("func_decl->type_specifier pointers ID '(' param_list ')'\n"); }
;

pointers
: '*'  { printf("pointers->'*'\n"); }
| %empty  { printf("pointers->epsilon\n"); }
;

param_list
: param_decl  { printf("param_list->param_decl\n"); }
| param_list ',' param_decl  { printf("param_list->param_list ',' param_decl\n"); }
;

param_decl
: type_specifier pointers ID  { printf("param_decl->type_specifier pointers ID\n"); }
| type_specifier pointers ID '[' INTEGER_CONST ']'  { printf("param_decl->type_specifier pointers ID '[' INTEGER_CONST ']'\n"); }
;

def_list
: def_list def  { printf("def_list->def_list def\n"); }
| %empty  { printf("def_list->epsilon\n"); }
;

def
: type_specifier pointers ID ';'  { printf("def->type_specifier pointers ID ';'\n"); }
| type_specifier pointers ID '[' INTEGER_CONST ']' ';'  { printf("def->type_specifier pointers ID '[' INTEGER_CONST ']' ';'\n"); }
;

compound_stmt
: '{' def_list stmt_list '}'  { printf("compound_stmt->'{' def_list stmt_list '}'\n"); }
;

stmt_list
: stmt_list stmt  { printf("stmt_list->stmt_list stmt\n"); }
| %empty  { printf("stmt_list->epsilon\n"); }
;

stmt
: expr ';'  { printf("stmt->expr ';'\n"); }
| compound_stmt  { printf("stmt->compound_stmt\n"); }
| RETURN expr ';'  { printf("stmt->RETURN expr ';'\n"); }
| ';'  { printf("stmt->';'\n"); }
| IF '(' expr ')' stmt %prec LOWER_THAN_ELSE  { printf("stmt->IF '(' expr ')' stmt\n"); }
| IF '(' expr ')' stmt ELSE stmt  { printf("stmt->IF '(' expr ')' stmt ELSE stmt\n"); }
| WHILE '(' expr ')' stmt  { printf("stmt->WHILE '(' expr ')' stmt\n"); }
| FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt  { printf("stmt->FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt\n"); }
| BREAK ';'  { printf("stmt->BREAK ';'\n"); }
| CONTINUE ';'  { printf("stmt->CONTINUE ';'\n"); }
;

expr_e
: expr  { printf("expr_e->expr\n"); }
| %empty  { printf("expr_e->epsilon\n"); }
;

expr
: unary '=' expr  { printf("expr->unary '=' expr\n"); }
| binary  { printf("expr->binary\n"); }
;

binary
: binary RELOP binary  { printf("binary->binary RELOP binary\n"); }
| binary EQUOP binary  { printf("binary->binary EQUOP binary\n"); }
| binary '+' binary  { printf("binary->binary '+' binary\n"); }
| binary '-' binary  { printf("binary->binary '-' binary\n"); }
| binary '*' binary  { printf("binary->binary '*' binary\n"); }
| binary '/' binary  { printf("binary->binary '/' binary\n"); }
| binary '%' binary  { printf("binary->binary '%%' binary\n"); }
| unary %prec '='  { printf("binary->unary\n"); }
| binary LOGICAL_AND binary  { printf("binary->binary LOGICAL_AND binary\n"); }
| binary LOGICAL_OR binary  { printf("binary->binary LOGICAL_OR binary\n"); }
;

unary
: '(' expr ')'  { printf("unary->'(' expr ')'\n"); }
| INTEGER_CONST  { printf("unary->INTEGER_CONST\n"); }
| CHAR_CONST  { printf("unary->CHAR_CONST\n"); }
| STRING  { printf("unary->STRING\n"); }
| ID  { printf("unary->ID\n"); }
| '-' unary %prec UMINUS  { printf("unary->'-' unary\n"); }
| '!' unary  { printf("unary->'!' unary\n"); }
| unary INCOP %prec STRUCTOP  { printf("unary->unary INCOP\n"); }
| unary DECOP %prec STRUCTOP  { printf("unary->unary DECOP\n"); }
| INCOP unary %prec UMINUS  { printf("unary->INCOP unary\n"); }
| DECOP unary %prec UMINUS  { printf("unary->DECOP unary\n"); }
| '&' unary  { printf("unary->'&' unary\n"); }
| '*' unary %prec DEREF  { printf("unary->'*' unary\n"); }
| unary '[' expr ']'  { printf("unary->unary '[' expr ']'\n"); }
| unary '.' ID  { printf("unary->unary '.' ID\n"); }
| unary STRUCTOP ID  { printf("unary->unary STRUCTOP ID\n"); }
| unary '(' args ')'  { printf("unary->unary '(' args ')'\n"); }
| unary '(' ')'  { printf("unary->unary '(' ')'\n"); }
| SYM_NULL  { printf("unary->SYM_NULL\n"); }
;

args
: expr  { printf("args->expr\n"); }
| args ',' expr  { printf("args->args ',' expr\n"); }
%%

/* Epilogue section */

int yyerror (char* s) {
  fprintf (stderr, "yyerror: %s\n", s);
}

void reduce(char* s) {
  printf("%s\n", s);
}
