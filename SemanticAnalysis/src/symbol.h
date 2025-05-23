#ifndef __SYMBOL_H__
#define __SYMBOL_H__

/* ========== 전역 변수 ========== */

typedef enum BaseType {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_POINTER,
    TYPE_STRUCT,
    TYPE_ARRAY,
} BaseType;

typedef struct TypeInfo {
    BaseType type; // 기본 타입
    struct TypeInfo *next; // 만약 포인터나 배열의 경우에는 기반 타입으로 연결
    char *struct_name; // 구조체 타입의 경우에는구조체 이름 
} TypeInfo;

// 심볼은 하나의 스코프 단위에서 유일한 이름을 가진다.
typedef struct Symbol {
    char *name; // 식별자 이름
    TypeInfo *type; // 식별자 타입 
    struct Symbol *next; // 다음 식별자 포인터 -> 이를 통해서 Symbol들을 연결시킴.
} Symbol;

// 심볼 테이블로 하나의 스코프 단위가 됨.
typedef struct SymbolTable {
    Symbol *symbols; // 식별자 테이블
    struct SymbolTable *parent; // 상위 스코프 연결 -> 이를 통해서 SymbolTable을 연결시켜 스택처럼 연결함.
} SymbolTable;

// extern 키워드를 사용하여 외부에서 접근 가능하도록 선언
extern SymbolTable *current_scope; //현재 스코프를 가리키는 포인터


/* ========== 함수 선언 ========== */
// 함수 선언
SymbolTable* create_symbol_table(SymbolTable* parent);
void free_symbol_table(SymbolTable* table);
void init_symbol_system();
void push_scope();
void pop_scope();
int insert_symbol(const char* name, TypeInfo* type);
int lookup_symbol_in_current_scope(const char* name);

#endif