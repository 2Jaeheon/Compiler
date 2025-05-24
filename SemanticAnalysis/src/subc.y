/*
 * File Name    : subc.y
 * Description  : a skeleton bison input
 */

%{

/* Prologue section */

#include "subc.h"

int   yylex ();
void   yyerror (char* s);
int   get_lineno();
void error_redeclaration(void);
void error_undeclared(void);
void error_incompatible(void);
void error_assignable(void);
void error_indirection(void);
%}

/* Bison declarations section */

/* yylval types */
%union {
  /* 토큰 타입 */
  int   intVal;
  /* 문자열 타입 */
  char  *stringVal;
  /* type_specifier는 타입 정보를 담는 구조체 포인터(TypeInfo*)를 전달 */
  struct TypeInfo *typeInfo;
  struct ParamList *paramList;
}

/* Precedences and Associativities */
%left   ','
%right  '='
%left   LOGICAL_OR
%left   LOGICAL_AND
%left   EQUOP
%left   RELOP
%left   '+' '-'
%left   '*' '/' '%'
%right  '!' '&' INCOP DECOP
%left   '[' ']' '(' ')' '.' STRUCTOP

%precedence IF
%precedence ELSE

/* Tokens and Types */
/* terminal types: Flex(lexer)가 Bison(parser)에게 넘기는 터미널 토큰의 타입*/
%token STRUCT RETURN WHILE FOR BREAK CONTINUE SYM_NULL
%token<stringVal> TYPE
%token CHAR_CONST
%token STRING
%token<intVal> INTEGER_CONST
%token<stringVal> ID  /* identifier name */
/* non-terminal types: Bison 내부의 비터미널(non-terminal)이 계산된 결과($$)의 타입을 지정 */
%type<typeInfo> type_specifier  /* type_specifier는 타입 정보를 담는 구조체 포인터(TypeInfo*)를 전달 */
%type<typeInfo> struct_specifier
%type<typeInfo> unary
%type<typeInfo> expr
%type<typeInfo> binary
%type<typeInfo> expr_e
%type<typeInfo> func_decl
%type<paramList> param_list param_decl

/* Grammar rules */
%%
program
  : ext_def_list 
  ;

ext_def_list
  : ext_def_list ext_def 
  | %empty 
  ;

ext_def
  : type_specifier pointers ID ';' { 
    /* 타입 정보 생성 */
    if (!insert_symbol($3, $1)) {
      error_redeclaration();
    }
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';' {
    /* 타입 정보 생성 */
    if (!insert_symbol($3, $1)) {
      error_redeclaration();
    }
  }
  | struct_specifier ';' 
  | func_decl compound_stmt
  ;

type_specifier
  : TYPE {
    /* 타입 정보 생성 */
    /* 만약 int 또는 char가 들어오면 해당 타입을 나타내는 TypeInfo를 생성해 반환 */
    $$ = malloc(sizeof(TypeInfo));
    /* 타입 정보 초기화 */
    
    if (strcmp($1, "int") == 0) {
      $$->type = TYPE_INT;
    } else if (strcmp($1, "char") == 0) {
      $$->type = TYPE_CHAR;
    } else {
      $$->type = TYPE_INT; 
    }
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
    $$->is_lvalue = 0;
  }
  | struct_specifier 
  ;

struct_specifier
  : STRUCT ID '{' {
    push_scope();
  } def_list '}' {
    if(is_redelcare_struct($2)) {
      error_redeclaration();
      $$ = NULL;
    } else {
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_STRUCT;
      $$->struct_name = $2;
      $$->next = NULL;
      $$->array_size = 0;
      $$->is_lvalue = 0;
      /* 스코프 내의 모든 심볼들을 fieldInfo 리스트로 변환 */
      $$->field_list = convert_scope_to_filed_list();

      /* 전역 구조체 리스트에 추가(구조체 이름을 키로 사용하여 구조체 정보를 저장) */
      register_struct_type($2, $$->field_list);
    }
    /* 스코프 종료 */
    pop_scope();
  }
  | STRUCT ID {
    /* 단순한 구조체 선언( struct S; 와 같은 경우) */
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_STRUCT;
    $$->struct_name = $2;
    $$->next = NULL;
    $$->array_size = 0;
    $$->is_lvalue = 0;
    $$->field_list = NULL;
  }
  ;

func_decl
  : type_specifier pointers ID '(' ')' {
    if (!insert_symbol($3, $1)) {
        error_redeclaration();
        current_param_list = NULL; 
        $$ = NULL; 
    } else {
        $$ = NULL;
    }
  }
  | type_specifier pointers ID '(' param_list ')' {
    if (!insert_symbol($3, $1)) {
        error_redeclaration();
        current_param_list = NULL; 
        $$ = NULL;
    } else {
         current_param_list = $5;
    }
  }
  ;

pointers
  : '*' 
  | %empty 
  ;

param_list  
  : param_decl {
    $$ = $1;
  }
  | param_list ',' param_decl {
    if ($1 != NULL && $3 != NULL) {
      $1->tail->next = $3->head;
      $1->tail = $3->tail;
    }
    $$ = $1;
  }
  ;		

param_decl 
  : type_specifier pointers ID {
    $$ = create_param_list();
    add_param($$, $3, $1); 
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' {
    $1 -> array_size = $5;
    $$ = create_param_list();
    add_param($$, $3, $1);
  }
  ;

def_list    
  : def_list def 
  | %empty 
  ;

def
  : type_specifier pointers ID ';' {
    /* 타입 정보 생성 */
    /* insert_symbol(이름, 타입)을 호출해 심볼 테이블에 추가 */
    if (!insert_symbol($3, $1)) {
      error_redeclaration();
    }
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';' {
    /* 타입 정보 생성 */
    if (!insert_symbol($3, $1)) {
      error_redeclaration();
    }
  }
  ;

compound_stmt
  : '{' {
    push_scope();
    if (current_param_list != NULL) {
      insert_param_list_to_scope(current_param_list);
      current_param_list = NULL;
    }
  } def_list stmt_list '}' {
    pop_scope();
  }
  ;

stmt_list
  : stmt_list stmt 
  | %empty 
  ;

stmt
  : expr ';' 
  | RETURN expr ';' 
  | BREAK ';' 
  | CONTINUE ';' 
  | ';' 
  | compound_stmt 
  | IF '(' expr ')' stmt 
  | IF '(' expr ')' stmt ELSE stmt 
  | WHILE '(' expr ')' stmt 
  | FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt 
  ;

expr_e
  : expr 
  | %empty {
    $$ = NULL;
  }
  ;

expr
  : unary '=' expr { /* 대입문을 분석할 때, 왼쪽과 오른쪽의 타입 검사 및 할당 가능한지를 체크하는 부분
  만약 a가 선언되지 않았는데, lookup_symbol()을 통해 타입을 찾으려고 하면, 에러가 발생함.
  따라서 이를 통해서 둘 중 하나라도 문제가 있는 경우에는 NULL을 반환하게 한다. */
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else if(!is_lvalue($1)) {
      error_assignable(); /* 할당이 불가능 함 */
      $$ = NULL;
    } else if(!is_same_type($1, $3)) {
      error_incompatible();
      $$ = NULL;
    } else {
      $$ = $1;
    }
  }
  | binary {
    $$ = $1; /* binary의 결과를 그대로 넘김 */
  }
  ;

binary
  : binary RELOP binary { /* 하나가 NULL이면 무조건 NULL을 반환해줘야 함 */
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | binary EQUOP binary 
  | binary '+' binary {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | binary '-' binary  {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | binary '*' binary {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | binary '/' binary {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | unary %prec '=' {
    $$ = $1;
  }
  | binary LOGICAL_AND binary  {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  | binary LOGICAL_OR binary {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else {
      /* 타입을 검사함 */
      $$ = $1;
    }
  }
  
  ;

unary
  : '(' expr ')' {
    $$ = $2;
  }
  | '(' unary ')' {
    $$ = $2;
  }
  | INTEGER_CONST {
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_INT;
    $$->is_lvalue = 0;
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | CHAR_CONST {
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_CHAR;
    $$->is_lvalue = 0;
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | STRING {
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_INT;
    $$->is_lvalue = 0;
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | ID {
    /* ID를 사용할 때, 이전에 선언된 적이 있는 지 확인해야함. */
    Symbol *symbol = lookup_symbol($1);
    if (!symbol) {
      error_undeclared();
      $$ = NULL;
    } else { 
      $$ = symbol -> type;
      $$ -> is_lvalue = 1;
    }
  }
  | '-' unary %prec '!' {
    if ($2 == NULL){
      $$ = NULL;
    } else {
      $$ = $2;
    }
  }
  | '!' unary {
    if ($2 == NULL) {
      $$ = NULL;
    } else {
      $$ = $2;
    }
  }
  | unary INCOP %prec STRUCTOP 
  | unary DECOP %prec STRUCTOP 
  | INCOP unary %prec '!' {
    if ($2 == NULL) {
      $$ = NULL;
    } else {
      $$ = $2;
    }
  }
  | DECOP unary %prec '!' {
    if ($2 == NULL) {
      $$ = NULL;
    } else {
      $$ = $2;
    }
  }
  | '&' unary {
    if ($2 == NULL) {
      $$ = NULL;
    } else {
      $$ = $2;
    }
  }
  | '*' unary %prec '!' {
    if ($2 == NULL) {
      $$ = NULL;
    } else if($2 -> type != TYPE_POINTER) { /* 만일 $2의 타입이 포인터가 아니라면, 에러 메시지를 출력함 */
      error_indirection();
      $$ = NULL;
    } else {
      $$ = $2 -> next; /* 포인터의 경우에는 값을 가지고 있는 것이기 때문에 포인터의 값을 가지고 있는 타입을 반환함 */
      $$ -> is_lvalue = 1;  /* 포인터의 경우에는 값을 가지고 있는 것이기 때문에 lvalue로 처리함 */
    }
  }
  | unary '[' expr ']' 
  | unary '.' ID 
  | unary STRUCTOP ID 
  | unary '(' args ')' 
  | unary '(' ')' 
  | SYM_NULL {
    $$ = NULL;
  }
  ;

args
  : expr 
  | args ',' expr 
  ;

%%

/* Epilogue section */

// Print the preamble of error message.
void error_preamble(void) {
  // TODO
  // Implement this function using get_lineno() function.
  // need to get the filename too
  printf("%s:%d: error: ", "filename", 1234);
}

void error_undeclared(void) {
  error_preamble();
  printf("use of undeclared identifier\n");
}

void error_redeclaration(void) {
  error_preamble();
  printf("redeclaration\n");
}

void error_assignable(void) {
  error_preamble();
  printf("lvalue is not assignable\n");
}

void error_incompatible(void) {
  error_preamble();
  printf("incompatible types for assignment operation\n");
}

void error_null(void) {
  error_preamble();
  printf("cannot assign 'NULL' to non-pointer type\n");
}

void error_binary(void) {
  error_preamble();
  printf("invalid operands to binary expression\n");
}

void error_unary(void) {
  error_preamble();
  printf("invalid argument type to unary expression\n");
}

void error_comparable(void) {
  error_preamble();
  printf("types are not comparable in binary expression\n");
}

void error_indirection(void) {
  error_preamble();
  printf("indirection requires pointer operand\n");
}

void error_addressof(void) {
  error_preamble();
  printf("cannot take the address of an rvalue\n");
}

void error_struct(void) {
  error_preamble();
  printf("member reference base type is not a struct\n");
}

void error_strurctp(void){
  error_preamble();
  printf("member reference base type is not a struct pointer\n");
}

void error_member(void) {
  error_preamble();
  printf("no such member in struct\n");
}

void error_array(void) {
  error_preamble();
  printf("subscripted value is not an array\n");
}

void error_subscript(void) {
  error_preamble();
  printf("array subscript is not an integer\n");
}

void error_incomplete(void) {
  error_preamble();
  printf("incomplete type\n");
}

void error_return(void) {
  error_preamble();
  printf("incompatible return types\n");
}

void error_function(void) {
  error_preamble();
  printf("not a function\n");
}

void error_arguments(void) {
  error_preamble();
  printf("incompatible arguments in function call\n");
}

void yyerror(char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}