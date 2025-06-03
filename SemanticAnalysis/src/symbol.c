#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

SymbolTable* current_scope = NULL;
ParamList* current_param_list = NULL;
StructType* global_type_list = NULL;
FuncInfo* global_func_list = NULL;
TypeInfo* current_function_return_type = NULL;
char* current_filename = NULL;
int error_lineno = -1;

// 새로운 스코프를 생성
SymbolTable* create_symbol_table(SymbolTable* parent) {
    // 심볼 테이블 메모리 할당
    SymbolTable* symbol_table = (SymbolTable*)malloc(sizeof(SymbolTable));
    // 심볼 테이블 초기화
    symbol_table->symbols = NULL;
    // 상위 스코프 연결
    symbol_table->parent = parent;
    // 심볼 테이블 반환
    return symbol_table;
}

// 심볼 시스템 초기화
void init_symbol_system() {
    // 전역 스코프 생성
    current_scope = create_symbol_table(NULL);
}



// 새로운 스코프를 생성하고 진입
void push_scope() {
    SymbolTable *new_scope = create_symbol_table(current_scope); //현재 스코프를 부모로 연결해줌.
    current_scope = new_scope;
    // printf("push_scope 함수를 통해서 새로운 스코프를 생성하고 진입했습니다.\n");
}

// 현재 스코프를 해제하고 이전 스코프로 복귀
void pop_scope() {
    if (current_scope == NULL) {
        // printf("현재 스코프가 존재하지 않습니다.");
        return ;
    } else {
        SymbolTable *old_scope = current_scope;
        current_scope = current_scope->parent; //부모 스코프로 current_scope를 업데이트 해줌.
        free_symbol_table(old_scope);
        // printf("old_scope 함수를 통해서 현재 스코프를 해제하고 이전 스코프로 복귀했습니다.\n");
    }
}

int insert_symbol(const char *name, TypeInfo *type) {
    // 중복 선언 검사
    if(lookup_symbol_in_current_scope(name)) {
        // printf("중복 선언 오류: %s\n", name);
        return 0;
    }

    // 새로운 심볼을 생성 및 삽입
    // 심볼 메모리 할당
    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));

    // 심볼 초기화
    new_symbol->name = strdup(name);
    new_symbol->type = deep_copy_typeinfo(type);

    // 심볼을 현재 스코프의 심볼 테이블에 추가
    new_symbol->next = current_scope->symbols;
    current_scope->symbols = new_symbol;

    // 성공 반환
    // printf("심볼 삽입 완료: %s\n", name);
    return 1;
}

int lookup_symbol_in_current_scope(const char *name) {
    Symbol *symbol = current_scope -> symbols;
    // 심볼 리스트를 순회하면서 중복 선언 오류 검사
    while(symbol != NULL) {
        if (strcmp(symbol->name, name) == 0) {
            return 1; // 중복 선언 오류
        }

        symbol = symbol->next;
    }
    return 0; // 중복이 없음
}

// 모든 스코프에서 심볼을 탐색하는 함수
Symbol* lookup_symbol(const char *name){
    SymbolTable *scope = current_scope;

    while(scope != NULL) {
        Symbol *symbol = scope -> symbols;

        while(symbol != NULL) {
            // 심볼 이름이 일치하는지 확인
            if (strcmp(symbol->name, name) == 0) {
                // printf("심볼이 존재합니다. 심볼 이름: %s\n", name);
                return symbol;
            }
            symbol = symbol->next;
        }
        scope = scope->parent;
    }
    // printf("심볼이 존재하지 않습니다. 심볼 이름: %s\n", name);
    return NULL;
}

// 두 타입이 일치하는지를 비교하는 함수
int is_same_type(TypeInfo *type1, TypeInfo *type2) {
    // 둘 다 NULL이면 동일한 것
    if (type1 == NULL && type2 == NULL) {
        // printf("타입 비교 실패: 둘 다 NULL\n");
        return 1;
    }

    // 한 쪽만 NULL이면 다른 타입
    if (type1 == NULL || type2 == NULL) {
        // printf("타입 비교 실패: 한 쪽만 NULL\n");
        return 0;
    }

    if ((type1->type == TYPE_NULLPTR && type2->type == TYPE_POINTER) ||
        (type2->type == TYPE_NULLPTR && type1->type == TYPE_POINTER)) {
        return 1;
    }


    // 타입의 종류가 다르면, 다른 타입
    if (type1->type != type2->type) {
        // printf("타입 비교 실패: 타입 종류가 다름\n");
        return 0;
    }

    // 구조체 타입의 경우에는 구조체 이름을 비교해줘야 함.
    if (type1->type == TYPE_STRUCT) {
        if (type1->struct_name == NULL || type2->struct_name == NULL) {
            return 0;
        }
        // struct_name이 같으면 ok
        if (strcmp(type1->struct_name, type2->struct_name) == 0) {
            return 1;
        }
        
        // struct_name이 다르면, 둘 중 하나가 변수 이름 (즉, 심볼테이블에 등록된 구조체 변수)면
        // 그 변수 타입의 struct_name이 같으면 ok
        Symbol* s1 = lookup_symbol(type1->struct_name);
        Symbol* s2 = lookup_symbol(type2->struct_name);
        if ((s1 && s1->type && s1->type->type == TYPE_STRUCT &&
             strcmp(s1->type->struct_name, type2->struct_name) == 0) ||
            (s2 && s2->type && s2->type->type == TYPE_STRUCT &&
             strcmp(s2->type->struct_name, type1->struct_name) == 0)) {
            return 1;
        }
        return 0;
    }

    // 배열 타입의 경우에는 배열의 사이즈를 비교해줘야 함.
    if (type1->type == TYPE_ARRAY) {
        if (type1->array_size != type2->array_size) {
            // printf("타입 비교 실패: 배열 사이즈가 다름\n");
            return 0;
        }
    }

    if (type1->next == NULL && type2->next == NULL) {
        return 1;
    }

    // 다음 타입 비교 (재귀 호출)
    // 같은 타입이라면 바로 다음의 타입을 비교시키면 되는 것 => 재귀적으로 진행함.
    return is_same_type(type1->next, type2->next);    
}

// LHS의 lvalue 여부를 판단하는 함수
int is_lvalue(TypeInfo *type) {
    if (type == NULL) {
        return 0;
    }
    return type->is_lvalue;
}

// ParamList 초기화
ParamList* create_param_list() {
    // 파라미터 리스트 메모리 할당
    ParamList* list = (ParamList*)malloc(sizeof(ParamList));
    // 파라미터 리스트 초기화
    list->head = list->tail = NULL;

    return list;
}

// 파라미터 추가
int add_param(ParamList* list, const char* name, TypeInfo* type) {

    // 파라미터 리스트가 비어있지 않으면, 중복된 이름이 있는지 확인함.
    // 리스트의 tail 노드의 next 포인터를 현재 추가한 파라미터 노드로 업데이트
    ParamNode* curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            return 0;  // 삽입 중단
        }
        curr = curr->next;
    }

    // 파라미터 노드 메모리 할당
    ParamNode* node = (ParamNode*)malloc(sizeof(ParamNode));
    node->name = strdup(name);
    node->type = deep_copy_typeinfo(type);
    node->next = NULL;

    // 파라미터 리스트에 추가
    if(list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    return 1;
}

void insert_param_list_to_scope(ParamList* list){
    ParamNode* current_node = list->head;

    // 파라미터 리스트의 모든 노드를 순회하면서 심볼 테이블에 추가
    while(current_node != NULL) {
        insert_symbol(current_node->name, current_node->type);
        current_node = current_node->next;
    }
}

// 스코프 내의 모든 심볼들을 fieldInfo 리스트로 변환함.
FieldInfo* convert_scope_to_field_list() {
    if (current_scope == NULL) {
        return NULL;
    }

    Symbol *symbol = current_scope -> symbols;
    FieldInfo *head = NULL;
    FieldInfo *tail = NULL;

    // 스코프 내의 모든 심볼들을 순회하면서 fieldInfo 리스트로 변환
    while(symbol != NULL) {
        FieldInfo* field = (FieldInfo*)malloc(sizeof(FieldInfo));
        field->name = strdup(symbol->name);
        field->type = deep_copy_typeinfo(symbol->type);
        field->next = NULL;

        // 첫 번째 필드인 경우
        if(head == NULL) {
            head = tail = field;
        } else { // 두 번째 이후 필드인 경우
            tail->next = field;
            tail = field;
        }

        // 다음 심볼로 이동
        symbol = symbol->next;
    }

    // 변환된 필드 리스트 반환
    return head;
}

// 구조체 중복을 확인
int is_redelcare_struct(const char *name) {
    StructType *current = global_type_list;

    while(current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void register_struct_type(const char *name, FieldInfo *field_list) {
    StructType *new_struct = malloc(sizeof(StructType));

    new_struct->name = strdup(name);
    new_struct->field_list = field_list;
    new_struct->next = global_type_list;
    global_type_list = new_struct;
}

// 구조체 멤버 탐색 함수 추가
// 예를 들어서 a.b 이럴 때 탐색해야함
TypeInfo* find_field_type(TypeInfo *struct_type, const char *field_name) {
    if (!struct_type) {
        // printf("구조체 타입이 아닙니다.\n");
        return NULL;
    }
    
    if (struct_type->type != TYPE_STRUCT) {
        // printf("구조체 타입이 아닙니다.\n");
        return NULL;
    }
    
    if (!struct_type->field_list) {
        // printf("필드 리스트가 없습니다.\n");
        return NULL;
    }

    FieldInfo *field = struct_type->field_list;
    
    while(field != NULL) {
        // printf(" 필드 탐색 중: %s\n", field->name);
        if (strcmp(field->name, field_name) == 0) {
            // printf("필드 일치: %s\n", field->name);
            return field->type;
        }
        field = field->next;
    }
    // printf("필드를 찾을 수 없습니다: %s\n", field_name);
    return NULL;
}


// 깊은 복사
TypeInfo* deep_copy_typeinfo(TypeInfo* src) {
    if(src == NULL) return NULL;
    TypeInfo* dst = malloc(sizeof(TypeInfo));
    dst->type = src->type;
    dst->next = deep_copy_typeinfo(src->next);
    dst->array_size = src->array_size;
    dst->is_lvalue = src->is_lvalue;

    if (src->type == TYPE_STRUCT) {
        dst->struct_name = src->struct_name ? strdup(src->struct_name) : NULL;
        StructType* cur = global_type_list;
        dst->field_list = NULL;
        while (cur) {
            if (strcmp(cur->name, dst->struct_name) == 0) {
                dst->field_list = deep_copy_field_list(cur->field_list);
                break;
            }
            cur = cur->next;
        }
    } else {
        dst->struct_name = NULL;
        dst->field_list = deep_copy_field_list(src->field_list);
    }
    return dst;
}

FieldInfo* deep_copy_field_list(FieldInfo* src) {
    if(src == NULL) {
        return NULL;
    }

    FieldInfo* head = NULL;
    FieldInfo* tail = NULL;

    while(src != NULL) {
        FieldInfo* field = malloc(sizeof(FieldInfo));
        field->name = strdup(src->name);
        field->type = deep_copy_typeinfo(src->type);
        field->next = NULL;

        if(tail != NULL) {
            tail->next = field;
        } else {
            head = field;
        }
        tail = field;
        src = src->next;
    }

    return head;
}

// 연산자 함수
int is_arithmetic_type(TypeInfo* type) {
    return type->type == TYPE_INT || type->type == TYPE_CHAR;
}

int is_boolean_type(TypeInfo* type) {
    return type->type == TYPE_INT;
}

int is_comparable_type(TypeInfo* type1, TypeInfo* type2) {
    if (type1 == NULL || type2 == NULL) return 0;
    if (type1->type == TYPE_STRUCT || type2->type == TYPE_STRUCT) return 0;
    if ((type1->type == TYPE_INT || type1->type == TYPE_CHAR) &&
        (type2->type == TYPE_INT || type2->type == TYPE_CHAR)) {
        return 1;
    }
    return 0;
}

// 함수 중복 선언 확인
int is_func_declared(char* name) {
    FuncInfo* current = global_func_list;
    // 함수 리스트를 순회하면서 함수 이름이 일치하는지 확인
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) { // 함수 이름이 일치하면, 1 반환
            return 1;
        }
        // 다음 함수로 이동
        current = current->next;
    }
    
    // 함수 이름이 일치하지 않으면, 0 반환
    return 0;
}

// 함수 정보 삽입
void insert_func_info(char* name, TypeInfo* return_type, ParamList* param_list) {
    FuncInfo* new_func = malloc(sizeof(FuncInfo));
    new_func->name = strdup(name);
    new_func->return_type = deep_copy_typeinfo(return_type);
    new_func->param_list = param_list;
    new_func->next = global_func_list;
    global_func_list = new_func;
}

// 함수 정보 탐색
FuncInfo* find_func_info(const char* name) {
    // 함수 리스트의 첫 노드
    FuncInfo* current = global_func_list;
    // 함수 리스트를 순회하면서 함수 이름이 일치하는지 확인
    while (current) {
        if (strcmp(current->name, name) == 0) { // 함수 이름이 일치하면, 함수 정보 반환
            return current;
        }
        // 다음 함수로 이동
        current = current->next;
    }
    // 함수 이름이 일치하지 않으면, NULL 반환
    return NULL;
}

// 인자 리스트 생성
ParamList* create_arg_list(TypeInfo* type) {
    // 인자 리스트 생성
    ParamList* list = create_param_list();

    // 인자 리스트가 비어있지 않으면, 타입을 추가
    if (type != NULL) {
        add_arg(list, type);
    }

    // 인자 리스트 반환
    return list;
}

// 인자 리스트에 타입 추가
int add_arg(ParamList* list, TypeInfo* type) {
    // 인자 노드 메모리 할당
    ParamNode* node = malloc(sizeof(ParamNode));
    node->type = deep_copy_typeinfo(type);
    node->name = NULL;
    node->next = NULL;

    // 인자 리스트가 비어있으면, 첫 노드로 추가
    if (!list->head) {
        list->head = list->tail = node;
    } else { // 인자 리스트가 비어있지 않으면, 마지막 노드에 추가
        list->tail->next = node;
        list->tail = node;
    }

    // 성공 반환
    return 1;
}

// 함수 선언부의 매개변수 리스트와 호출부의 인자 리스트가 호환되는지 검사
int is_compatible_arguments(ParamList* declared, ParamList* args) {
    // 선언부 매개변수 리스트의 첫 노드
    ParamNode *p1 = declared ? declared->head : NULL;  
    // 호출부 인자 리스트의 첫 노드
    ParamNode *p2 = args ? args->head : NULL;        
    // 두 리스트를 순회하면서
    while (p1 && p2) {                               
        // 타입이 일치하지 않으면
        if (!is_same_type(p1->type, p2->type))      
            return 0;            

        // 다음 노드로 이동
        p1 = p1->next;                               
        p2 = p2->next;
    }

    // 두 리스트의 길이가 같아야 호환됨
    return (p1 == NULL && p2 == NULL);               
}



void free_type(TypeInfo *type) {
    if (type == NULL) {
        return ;
    }
    
    // 배열이나 포인터 등과같은 연속된 타입 체인을 해제함.
    free_type(type->next);

    // 구조체의 경우 구조체 이름 메모리 해제
    if(type -> struct_name) {
        free(type->struct_name);
    }

    // 구조체 타입의 경우 필드 리스트 해제
    free_field_list(type->field_list);

    // 자기 자신을 해제
    free(type);
}

// 구조체 내부의 필드 정보를 해제함.
void free_field_list(FieldInfo *field_list) {
    // 필드는 계속해서 연결되어있음. 따라서 이를 하나씩 해제해줘야함
    // 필드 리스트가 비어있을 때까지 반복
    while(field_list) {
        // 다음 필드 정보를 저장
        FieldInfo *next = field_list->next;
        
        // 필드 이름 해제
        if (field_list->name){
            free(field_list->name);
        }

        // 필드 타입 해제
        free_type(field_list->type);

        // 현재 필드를 해제
        free(field_list);

        field_list = next;
    }
}

// 파라미터 리스트 내부의 파라미터 노드들을 해제하는 함수
void free_param_list(ParamList* list) {
    if (list == NULL) {
        return ;
    }

    // 파라미터 리스트의 첫 노드부터 순회하면서 해제
    ParamNode* current = list->head;

    while(current) {
        ParamNode* next = current->next;

        // 파라미터 이름 해제
        if(current->name) {
            free(current->name);
        }

        // 파라미터 타입 해제
        if(current->type) {
            free_type(current->type);
        }

        // 현재 노드 해제
        free(current);
        // 다음 노드로 이동
        current = next;
    }

    // 파라미터 리스트 해제
    free(list);
}

void free_symbol(Symbol* symbol) {
    while(symbol) {
        Symbol* next = symbol->next;

        if(symbol->name) {
            free(symbol->name);
        }

        free_type(symbol->type);
        
        // 심볼 해제
        free(symbol);
        symbol = next;
    }
}

void free_symbol_table(SymbolTable* table) {
    if (table == NULL) {
        return ;
    }

    // 심볼테이블 내부의 심볼 해제
    free_symbol(table->symbols);

    // 테이블 해제
    free(table);
}

void free_struct_type_list(StructType* list){
    while(list) {
        StructType* next = list->next;

        if(list->name) {
            free(list->name);
        }

        free_field_list(list->field_list);
        free(list);
        list = next;
    }
}

void free_func_list(FuncInfo* list) {
    while(list) {
        FuncInfo* next = list->next;

        if(list->name) {
            free(list->name);
        }

        free_type(list->return_type);
        free_param_list(list->param_list);

        free(list);
        list = next;
    }
}