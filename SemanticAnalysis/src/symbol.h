#ifndef __SYMBOL_H__
#define __SYMBOL_H__
#define TYPE_NULLPTR 999
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
    int array_size; // 배열의 경우에는 배열의 사이즈를 저장
    int is_lvalue; // 해당 타입이 lvalue인지 확인하는 플래그
    struct FieldInfo *field_list; // 구조체 필드 리스트
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

// Parameter들 저장하는 구조체
typedef struct ParamNode {
    char* name;
    TypeInfo* type;
    struct ParamNode* next;
} ParamNode;

typedef struct ParamList {
    ParamNode* head;
    ParamNode* tail;
} ParamList;

// 구조체 필드 정보 저장하는 구조체
typedef struct FieldInfo {
    char *name;
    TypeInfo* type;
    struct FieldInfo* next;
} FieldInfo;

// 전역으로 선언된 구조체 정보 저장하는 구조체
typedef struct StructType {
    char *name;
    FieldInfo *field_list;
    struct StructType *next;
} StructType;

// 함수 저장
typedef struct FuncInfo {
    char *name;
    TypeInfo *return_type;
    ParamList *param_list;
    struct FuncInfo *next;
} FuncInfo;



// extern 키워드를 사용하여 외부에서 접근 가능하도록 선언
extern SymbolTable *current_scope; //현재 스코프를 가리키는 포인터
extern ParamList* current_param_list; // 현재 함수의 파라미터 리스트를 가리키는 포인터
extern StructType* global_type_list; // 전역으로 선언된 구조체 정보 저장하는 구조체
extern FuncInfo* global_func_list; // 전역으로 선언된 함수 정보 저장하는 구조체
extern TypeInfo* current_function_return_type; // 현재 함수의 반환 타입을 가리키는 포인터
extern char* current_filename; // 현재 파일 이름을 저장하는 변수
extern int error_lineno; // 에러 줄 번호를 저장하는 변수
/* ========== 함수 선언 ========== */
// 함수 선언
SymbolTable* create_symbol_table(SymbolTable* parent);
void free_symbol_table(SymbolTable* table);
void init_symbol_system();
void push_scope();
void pop_scope();
int insert_symbol(const char* name, TypeInfo* type);
int lookup_symbol_in_current_scope(const char* name);
Symbol* lookup_symbol(const char *name);
int is_same_type(TypeInfo* type1, TypeInfo* type2);
int is_lvalue(TypeInfo *type);
ParamList* create_param_list();
int add_param(ParamList* list, const char* name, TypeInfo* type);
void insert_param_list_to_scope(ParamList* list);
void error_redeclaration(); 
FieldInfo* convert_scope_to_filed_list();
int is_redelcare_struct(const char *name);
void register_struct_type(const char *name, FieldInfo *field_list);
TypeInfo* find_field_type(TypeInfo *struct_type, const char *field_name);
TypeInfo* deep_copy_typeinfo(TypeInfo* src);
FieldInfo* deep_copy_field_list(FieldInfo* src);
int is_arithmetic_type(TypeInfo* type);
int is_boolean_type(TypeInfo* type);
int is_comparable_type(TypeInfo* type1, TypeInfo* type2);
int is_func_declared(char* name);
void insert_func_info(char* name, TypeInfo* return_type, ParamList* param_list);
FuncInfo* find_func_info(const char* name);
int is_same_param_list(ParamList* p1, ParamList* p2);
ParamList* create_arg_list(TypeInfo* type);
int add_arg(ParamList* list, TypeInfo* type);
void print_param_list(ParamList* list, const char* msg);
int is_compatible_arguments(ParamList* declared, ParamList* args);

#endif