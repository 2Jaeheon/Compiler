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
void error_struct(void);
void error_strurctp(void);
void error_member(void);
void error_array(void);
void error_subscript(void);
void error_incomplete(void);
void error_return(void);
void error_comparable(void);
void error_binary(void);
void error_unary(void);
void error_arguments(void);
void error_function(void);
void error_null(void);
void error_addressof(void);

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
%type<typeInfo> pointers
%type<paramList> args
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
    /* 전역 변수 선언 규칙 */

    /* 1. 기본 타입(type_specifier)에 포인터(pointers)를 연결해 최종 타입 생성 */
    TypeInfo* final_type = $1;
    if($2 != NULL) {
      $2->next = $1;
      final_type = $2;
    }
    
    /* 2. 타입 체크 및 심볼 테이블에 변수 추가 */
    if(final_type == NULL) {
      error_incomplete(); /* 불완전한 타입 에러 */
    } else if (!insert_symbol($3, final_type)) {
      error_redeclaration(); /* 변수 재선언 에러 */
    }
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';' {
    TypeInfo *base_type = $1; /* 배열 타입의 경우, 배열의 기본 타입을 저장 */
    
    // 포인터 타입이 있는 경우, 포인터 타입을 추가함.
    if($2 != NULL) {
      $2->next = $1;
      base_type = $2;
    }

    // 배열 타입 생성
    TypeInfo *array_type = malloc(sizeof(TypeInfo));
    array_type->type = TYPE_ARRAY; // 배열 타입으로 설정
    array_type->next = base_type; // 배열 타입을 설정 (배열의 기본 타입을 저장 ex_int, char 등)

    // 배열 타입의 경우, lvalue가 아님.
    array_type->is_lvalue = 0;
    array_type->struct_name = NULL;
    array_type->array_size = $5; // INTEGER_CONST를 통해서 배열의 크기를 저장

    // 심볼 테이블에 배열 타입 추가
    if(!insert_symbol($3, array_type)) {
      // 변수를 재선언함 에러 발생
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
    
    if (strcmp($1, "int") == 0) { // int 타입 처리
      $$->type = TYPE_INT;
    } else if (strcmp($1, "char") == 0) { // 문자 타입 처리
      $$->type = TYPE_CHAR;
    } else { // 기본 타입이 아닌 경우, int로 설정
      $$->type = TYPE_INT; 
    }
    // 타입 정보 초기화
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
    $$->is_lvalue = 0;
  }
  | struct_specifier 
  ;

struct_specifier
  : STRUCT ID {
    // error_lineno을 통해서 오류 발생 위치를 저장
    error_lineno = get_lineno();
  }
  '{' {
    // 스코프 추가
    push_scope();
  } def_list '}' {
    // 구조체 재선언 체크
    if(is_redelcare_struct($2)) {
      error_redeclaration();
      $$ = NULL;
    } else {
      // 구조체 타입 생성
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_STRUCT;
      $$->struct_name = strdup($2);
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
    StructType *current = global_type_list;
    
    while(current != NULL) {
      if(strcmp(current->name, $2) == 0) {
        $$ = malloc(sizeof(TypeInfo));
        $$->type = TYPE_STRUCT;
        $$->struct_name = strdup($2);
        $$->next = NULL;
        $$->array_size = 0;
        $$->is_lvalue = 0;
        $$->field_list = current->field_list;
        break;
      }
      current = current->next;
    }
    
    if (current == NULL) {
      error_undeclared();
      $$ = NULL;
    }
  }
  ;

func_decl
  : type_specifier pointers ID '(' ')' {
    // 함수 선언 규칙
    TypeInfo* final_type = $1;
    
    // pointer가 있으면 pointer 타입을 추가함.
    if($2 != NULL) {
      $2->next = $1;
      final_type = $2;
    }

    // 함수 반환 타입 설정
    current_function_return_type = final_type;

    // 함수 선언 체크
    if(!insert_symbol($3, final_type)) { // 함수가 선언이 가능한지를 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      $$ = NULL;
    } else if(is_func_declared($3)) { // 함수 재선언 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      $$ = NULL;
    } else { // 함수 선언 추가
      // 함수 추가
      insert_func_info($3, final_type, NULL);
      $$ = NULL;
    }
  }
  | type_specifier pointers ID '(' param_list ')' {
    // 함수 선언 규칙
    TypeInfo* final_type = $1;
    
    // pointer가 있으면 pointer 타입을 추가함.
    if ($2 != NULL) {
      $2->next = $1;
      final_type = $2;
    }

    // 함수 반환 타입 설정
    current_function_return_type = final_type;

    // 함수 파라미터 리스트 설정
    current_param_list = $5;

    // 함수 선언 체크
    if (is_func_declared($3)) { // 함수 재선언 체크
      // 함수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
      $$ = NULL;
    } else {
      // 함수 추가
      insert_func_info($3, final_type, $5);
      if (!insert_symbol($3, final_type)) { // 함수가 선언이 가능한지를 체크
        // 함수가 이미 선언되어 있는 경우 에러 발생
        error_redeclaration();
      }
      $$ = NULL;
    }
  }
  ;

pointers
  : '*' {
    // 포인터 타입 생성
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_POINTER;
    $$->next = NULL;
    $$->is_lvalue = 0;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | %empty {
    // 파라미터 리스트가 없는 경우 에러 발생
    $$ = NULL;
  }
  ;

param_list  
  : param_decl {
    $$ = $1;
  }
  | param_list ',' param_decl {
    // 파라미터 리스트가 있는 경우 파라미터 추가
    if ($1 != NULL && $3 != NULL) {
      $1->tail->next = $3->head;
      $1->tail = $3->tail;
    }
    $$ = $1;
  }
  ;		

param_decl 
  : type_specifier pointers ID {
    // 파라미터 타입 설정
    if ($1 == NULL) {
      error_incomplete();
      $$ = NULL;
    } else {
      // 파라미터 타입 설정
      TypeInfo* final_type = $1;
      if ($2 != NULL) { // 포인터가 있는 경우
        // 포인터 타입을 추가함
        $2->next = $1; /* POINTER -> INT 로 연결하는 부분 */
        final_type = $2; // $2는 포인터 타입임. 따라서 포인터 타입을 추가함
      }
      $$ = create_param_list(); // 파라미터 리스트 생성
      if(!add_param($$, $3, final_type)) {
        // 파라미터 추가 에러 발생
        error_redeclaration();
        $$ = NULL;
      }
    }
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' {
    // 만일 int *a[10] 이면 TYPE_POINTER -> TYPE_ARRAY -> TYPE_INT 로 연결되어야 함.
    if ($1 == NULL) {
      // 타입 정보가 없는 경우 에러 발생
      error_incomplete();
      $$ = NULL;
    } else { // 파라미터 타입 설정
      TypeInfo* param_type = deep_copy_typeinfo($1); // 파라미터 타입 복사
      param_type -> array_size = $5; // 파라미터 타입 배열 크기 설정

      $$ = create_param_list(); // 파라미터 리스트 생성
      if(!add_param($$, $3, param_type)) {
        // 재선언 에러 발생
        error_redeclaration();
        $$ = NULL;
      }
    }
  }
  ;

def_list    
  : def_list def 
  | %empty 
  ;

def
  : type_specifier pointers ID ';' {
    // 변수 선언 규칙
    TypeInfo* final_type = $1;

    // pointer가 있으면 pointer 타입을 추가함.
    if($2 != NULL) {
      $2->next = $1;
      final_type = $2;
    }

    // 변수 선언 체크
    if(final_type == NULL) { // 타입 정보가 없는 경우 에러 발생
      error_incomplete();
    } else if (!insert_symbol($3, final_type)) { // 변수 선언 체크
      // 변수가 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
    }
  }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';' {
    // 배열 선언 규칙
    TypeInfo* base_type = $1;

    // pointer가 있으면 pointer 타입을 추가함.
    if ($2 != NULL) {
        $2->next = $1;
        base_type = $2;
    }

    // 배열 타입 생성
    TypeInfo* array_type = malloc(sizeof(TypeInfo));
    // 배열 타입 설정
    array_type->type = TYPE_ARRAY;
    array_type->array_size = $5; // 배열 크기 설정
    array_type->next = base_type; // 배열 타입을 설정 (기본 타입을 저장)
    array_type->is_lvalue = 0; // 배열 타입은 lvalue가 아님
    array_type->struct_name = NULL;

    // 배열 타입 선언 체크
    if (!insert_symbol($3, array_type)) {
      // 배열 타입이 이미 선언되어 있는 경우 에러 발생
      error_redeclaration();
    }
  }
  ;

compound_stmt
  : '{' {
    // 스코프 추가
    push_scope();
    // 파라미터 리스트가 있는 경우 파라미터 추가
    if (current_param_list != NULL) {
      // 파라미터 리스트를 순회하며 파라미터 추가
        ParamNode* cur = current_param_list->head;
        while (cur != NULL) {
          if (!insert_symbol(cur->name, cur->type)) {
            // 파라미터가 이미 선언되어 있는 경우 에러 발생
            error_redeclaration();
          }
          cur = cur->next;
        }
        current_param_list = NULL; // 파라미터 리스트 초기화
      }
  } def_list stmt_list '}' {
    // 스코프 종료
    pop_scope();
  }
  ;

stmt_list
  : stmt_list stmt 
  | %empty 
  ;

stmt
  : expr ';' 
  | RETURN expr ';' {
    // 반환 타입 체크
    if ($2 != NULL && current_function_return_type != NULL) {
        if (!is_same_type($2, current_function_return_type)) {
            // 반환 타입이 일치하지 않는 경우 에러 발생
            error_return();
        }
    }
  }
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
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if(!is_lvalue($1)) { // 왼쪽 피연산자가 lvalue가 아닌 경우
      error_assignable(); /* 할당이 불가능 함 */
      $$ = NULL;
    } else if($3->type == TYPE_NULLPTR && $1->type != TYPE_POINTER) { // 오른쪽 피연산자가 NULL인 경우
      error_null();
      $$ = NULL;
    } else if(!is_same_type($1, $3)) { // 피연산자 타입이 일치하지 않는 경우
      error_incompatible();
      $$ = NULL;
    } else { // 정상적인 경우
      $$ = $1;
    }
  }
  | binary {
    $$ = $1; /* binary의 결과를 그대로 넘김 */
  }
  ;

binary
  : binary RELOP binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if (!is_comparable_type($1, $3)) { // 피연산자 타입이 비교 가능한 타입이 아닌 경우
      error_comparable();
      $$ = NULL;
    } else {
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_INT;
      $$->is_lvalue = 0;
      $$->next = NULL;
      $$->struct_name = NULL;
      $$->array_size = 0;
    }
  }
  | binary EQUOP binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if (!is_comparable_type($1, $3)) { // 피연산자 타입이 비교 가능한 타입이 아닌 경우
      error_comparable();
      $$ = NULL;
    } else {
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_INT;
      $$->is_lvalue = 0;
      $$->next = NULL;
      $$->struct_name = NULL;
      $$->array_size = 0;
    }
  }
  | binary '+' binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if(!is_arithmetic_type($1) || !is_arithmetic_type($3)) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else {
      $$ = deep_copy_typeinfo($1);
    }
  }
  | binary '-' binary  {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if(!is_arithmetic_type($1) || !is_arithmetic_type($3)) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else {
      $$ = deep_copy_typeinfo($1);
    }
  }
  | binary '*' binary {
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else if(!is_arithmetic_type($1) || !is_arithmetic_type($3)) {
      error_binary();
      $$ = NULL;
    } else {
      $$ = deep_copy_typeinfo($1);
    }
  }
  | binary '/' binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if(!is_arithmetic_type($1) || !is_arithmetic_type($3)) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else {
      $$ = deep_copy_typeinfo($1);
    }
  }
  | binary '%' binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if(!is_arithmetic_type($1) || !is_arithmetic_type($3)) { // 피연산자 타입이 산술 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else {
      $$ = deep_copy_typeinfo($1);
    }
  }
  | unary %prec '=' {
    $$ = $1;
  }
  | binary LOGICAL_AND binary  {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if (!is_boolean_type($1) || !is_boolean_type($3)) { // 피연산자 타입이 불리언 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else {
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_INT;
      $$->is_lvalue = 0;
      $$->next = NULL;
      $$->struct_name = NULL;
      $$->array_size = 0;
    }
  }
  | binary LOGICAL_OR binary {
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if (!is_boolean_type($1) || !is_boolean_type($3)) { // 피연산자 타입이 불리언 타입이 아닌 경우
      error_binary();
      $$ = NULL;
    } else { // 정상적인 경우
      $$ = $1;
    }
  }
  
  ;

unary
  : '(' expr ')' {
    // expr을 괄호로 감싸면 타입 정보를 그대로 넘김
    $$ = $2;
  }
  | '(' unary ')' {
    // 피연산자를 괄호로 감싸면 타입 정보를 그대로 넘김
    $$ = $2;
  }
  | INTEGER_CONST {
    // 정수 상수 타입 생성
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_INT;
    $$->is_lvalue = 0;
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | CHAR_CONST {
    // 문자 상수 타입 생성
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_CHAR;
    $$->is_lvalue = 0;
    $$->next = NULL;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | STRING {
    // 문자열 타입 생성
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_POINTER;
    $$->next = malloc(sizeof(TypeInfo));
    $$->next->type = TYPE_CHAR;
    $$->next->is_lvalue = 0;
    $$->next->next = NULL;
    $$->next->struct_name = NULL;
    $$->next->array_size = 0;

    $$->is_lvalue = 0;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  | ID {
    // 심볼 테이블에서 타입 정보를 찾음
    Symbol* symbol = lookup_symbol($1); // ID의 타입 정보를 찾음
    // 여기서 나올 수 있는 것은 심볼이 없는 경우와 심볼이 있는 경우 두 가지 경우가 있음.
    // 심볼이 없는 경우는 변수가 선언되지 않은 경우임.
    // 심볼이 있는 경우는 변수가 선언된 경우임.
    // 따라서 심볼이 없는 경우는 에러 발생하고, 심볼이 있는 경우는 타입 정보를 복사하고, lvalue 여부를 결정함.

    if (!symbol) { // 심볼이 없는 경우 에러 발생
        error_undeclared();
        $$ = NULL;
    } else { // 심볼이 있는 경우
        // 피연산자의 타입 정보를 복사
        $$ = deep_copy_typeinfo(symbol->type);

        // 배열이면 lvalue가 아님!
        // lvalue는 대입 연산자의 왼쪽에 올 수 있는 값을 의미
        // 예를 들어 변수는 lvalue가 될 수 있지만, 상수나 표현식의 결과는 lvalue가 될 수 없음
        // 즉, int a = 10; 에서 a는 lvalue이고 10은 rvalue임
        // 포인터를 통한 간접 참조도 lvalue가 될 수 있음

        if ($$->type == TYPE_ARRAY) { // 배열이면 lvalue가 아님
            $$->is_lvalue = 0;
        } else { // 배열이 아닌 경우, lvalue로 처리
            $$->is_lvalue = 1;
        }

        // 구조체 이름 복사해서 저장
        $$->struct_name = strdup($1);
    }
}
  | '-' unary %prec '!' {
    if ($2 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else { // 정상적인 경우
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
  | unary INCOP %prec STRUCTOP { // 후위 증감 연산
    // 피연산자가 NULL인 경우 즉, 피연산자가 없는 경우
    if ($1 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue($1)) {
      error_unary();
      $$ = NULL;
    } else { // 정상적인 경우
      $$ = deep_copy_typeinfo($1);
      $$->is_lvalue = 0; // 후위 증감 연산 결과는 rvalue
    }
  }
  | unary DECOP %prec STRUCTOP { // 후위 감소 연산
    // 피연산자가 NULL인 경우 즉, 피연산자가 없는 경우
    if ($1 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue($1)) {
      error_unary();
      $$ = NULL;
    } else { // 정상적인 경우
      // 피연산자의 타입 정보를 복사
      $$ = deep_copy_typeinfo($1);
      $$->is_lvalue = 0; // 후위 증감 연산 결과는 rvalue
    }
  }
  | INCOP unary %prec '!' {
    // 피연산자가 NULL인 경우
    if ($2 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue($2)) {
      error_unary();
      $$ = NULL;
    } 
    // 정상적인 경우
    else {
      // 피연산자의 타입 정보를 복사
      $$ = deep_copy_typeinfo($2);
      $$->is_lvalue = 0; // 전위 증감 연산 결과도 rvalue
    }
  }
  | DECOP unary %prec '!' {
    // 피연산자가 NULL인 경우
    if ($2 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue($2)) {
      error_unary();
      $$ = NULL;
    }
    // 정상적인 경우
    else {
      // 피연산자의 타입 정보를 복사
      $$ = deep_copy_typeinfo($2);
      // 전위 감소 연산의 결과는 rvalue
      $$->is_lvalue = 0;
    }
  }
  | '&' unary {
    // 피연산자가 NULL인 경우
    if ($2 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if(!is_lvalue($2)) {
      if ($2->type == TYPE_ARRAY) { // 나눠서 처리해야 에러 메시지가 제대로 출력됨.
        // 배열 타입의 경우, 주소 연산 에러 발생
        error_addressof();
      } else {
        // 포인터 타입의 경우, 주소 연산 에러 발생
        error_unary();
      }
      $$ = NULL;
    } else {
      // 포인터 타입 생성
      $$ = malloc(sizeof(TypeInfo));
      $$->type = TYPE_POINTER;
      $$->next = deep_copy_typeinfo($2);
      $$->is_lvalue = 0;
      $$->struct_name = NULL;
      $$->array_size = 0;
    }
}
  | '*' unary %prec '!' {
    // 피연산자가 NULL인 경우
    if ($2 == NULL) {
      $$ = NULL;
    } 
    // 피연산자가 포인터가 아닌 경우 에러 발생
    else if($2->type != TYPE_POINTER) {
      error_indirection();
      $$ = NULL;
    } 
    // 피연산자가 lvalue가 아닌 경우 에러 발생
    else if (!is_lvalue($2)) {
      error_unary();
      $$ = NULL;
    } 
    // 정상적인 경우
    else { 
      // 피연산자의 타입 정보를 복사
      $$ = deep_copy_typeinfo($2->next);
      // 포인터 타입의 경우, lvalue로 처리
      $$->is_lvalue = 1;
    }
  }
  | unary '[' expr ']' {
    // 배열 인덱스 연산 규칙
    if ($1 == NULL || $3 == NULL) {
      $$ = NULL;
    } else if($1->type != TYPE_ARRAY) { // 피연산자가 배열이 아닌 경우
      error_array();
      $$ = NULL;
    } else if($3->type != TYPE_INT) { // 피연산자가 정수가 아닌 경우
      error_subscript();
      $$ = NULL;
    } else { // 정상적인 경우
      $$ = deep_copy_typeinfo($1->next);
      $$->is_lvalue = 1;
    }
  }
  | unary '.' ID {
    // 구조체 멤버 접근 규칙
    if ($1 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if($1->type != TYPE_STRUCT) { // 피연산자가 구조체가 아닌 경우
      error_lineno = get_lineno(); /* 여기에서 라인번호 기록 */
      // 타입 호환 에러 발생
      error_incompatible(); 
      $$ = NULL;
    } else { // 정상적인 경우
      TypeInfo *field_type = find_field_type($1, $3);
      // 필드 없을 때도 마찬가지
      if(field_type == NULL) {
        error_lineno = get_lineno();
        // 필드 없을 때도 마찬가지
        error_member();
        $$ = NULL;
      } else {
        // 필드 타입 복사
        $$ = deep_copy_typeinfo(field_type);
        $$->is_lvalue = 1;
      }
    }
  }
  | unary STRUCTOP ID {
    // 구조체 포인터 멤버 접근 규칙
    if($1 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else if($1->type != TYPE_POINTER || $1->next->type != TYPE_STRUCT) { // 피연산자가 구조체 포인터가 아닌 경우
      error_strurctp(); /* 구조체 포인터가 아니라면 에러 메시지를 출력함 */
      $$ = NULL;
    } else {
      // 구조체 타입 정보 복사
      TypeInfo *struct_type = $1->next;
      // 필드 타입 찾기
      TypeInfo *field_type = find_field_type(struct_type, $3);

      // 필드가 없으면 에러 발생
      if(field_type == NULL) {
        error_member();
        $$ = NULL;
      } else {
        // 필드 타입 복사
        $$ = deep_copy_typeinfo(field_type);
        $$->is_lvalue = 1;
      }
    }
  }
  | unary '(' args ')' {
    // 함수 호출 규칙
    if ($1 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else {
      // 함수 타입 정보 찾기
      FuncInfo* func = find_func_info($1->struct_name); /* struct_name에 함수 이름 저장됨 */
        if (func == NULL) { /* 함수가 아니라면 */
            error_function(); /* 에러 메시지를 출력함 */
            $$ = NULL;
        } else if (!is_compatible_arguments(func->param_list, $3)) {
            error_arguments(); /* 인자 리스트가 호환되지 않으면 에러 메시지를 출력함 */
            $$ = NULL;
        } else {
            $$ = deep_copy_typeinfo(func->return_type); /* 함수 반환 타입을 반환함 */
            $$->is_lvalue = 0;
        }
    }
  }
  | unary '(' ')' {
    // 함수 호출 규칙
    if ($1 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else {
      // 함수 타입 정보 찾기
        FuncInfo* func = find_func_info($1->struct_name);
      if (func == NULL) { // 함수가 없는 경우
        error_function();
        $$ = NULL;
      } else if (func->param_list != NULL) { // 인자 리스트가 호환되지 않는 경우
        error_arguments();
        $$ = NULL;
      } else { // 정상적인 경우
          // 함수 반환 타입 복사
          $$ = deep_copy_typeinfo(func->return_type);
          $$->is_lvalue = 0;
        }
    }
}
  | SYM_NULL {
    // NULL 타입 생성
    $$ = malloc(sizeof(TypeInfo));
    $$->type = TYPE_NULLPTR;
    $$->next = NULL;
    $$->is_lvalue = 0;
    $$->struct_name = NULL;
    $$->array_size = 0;
  }
  ;

args
  : expr {
    // 함수 호출 시 인자 리스트 생성
    // 인자 리스트 생성
    if ($1 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else { // 정상적인 경우
      $$ = create_param_list();
      // 인자 리스트에 피연산자 추가
      add_arg($$, $1);
    }
  }
  | args ',' expr {
    // 함수 호출 시 인자 리스트 생성
    // 인자 리스트 생성
    if ($1 == NULL || $3 == NULL) { // 피연산자가 NULL인 경우
      $$ = NULL;
    } else { // 정상적인 경우
        $$ = $1;
        // 인자 리스트에 피연산자 추가
        add_arg($$, $3);
    }
  }
  ;

%%

/* Epilogue section */

void error_preamble(void) {
  if (error_lineno != -1) {
    printf("%s:%d: error: ", current_filename, error_lineno);
  } else {
    printf("%s:%d: error: ", current_filename, get_lineno());
  }
  error_lineno = -1;
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