#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

SymbolTable* current_scope = NULL;
ParamList* current_param_list = NULL;
StructType* global_type_list = NULL;

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

// 심볼 테이블 메모리 해제
void free_symbol_table(SymbolTable* table) {
    Symbol* symbol = table -> symbols;
    // 심볼이 존재하는 동안 반복하면서 메모리 해제
    while(symbol != NULL) {
        // 다음 심볼을 가리키는 포인터를 저장
        Symbol* next = symbol->next;
        // 심볼의 메모리 해제
        free(symbol->name);
        free(symbol->type);
        free(symbol);
        
        // 다음 심볼로 이동
        symbol = next;
    }
    // 심볼 테이블 메모리 해제
    free(table);
}

// 새로운 스코프를 생성하고 진입
void push_scope() {
    SymbolTable *new_scope = create_symbol_table(current_scope); //현재 스코프를 부모로 연결해줌.
    current_scope = new_scope;
    printf("push_scope 함수를 통해서 새로운 스코프를 생성하고 진입했습니다.\n");
}

// 현재 스코프를 해제하고 이전 스코프로 복귀
void pop_scope() {
    if (current_scope == NULL) {
        printf("현재 스코프가 존재하지 않습니다.");
        return ;
    } else {
        SymbolTable *old_scope = current_scope;
        current_scope = current_scope->parent; //부모 스코프로 current_scope를 업데이트 해줌.
        free_symbol_table(old_scope);
        printf("old_scope 함수를 통해서 현재 스코프를 해제하고 이전 스코프로 복귀했습니다.\n");
    }
}

int insert_symbol(const char *name, TypeInfo *type) {
    // 중복 선언 검사
    if(lookup_symbol_in_current_scope(name)) {
        printf("중복 선언 오류: %s\n", name);
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
    printf("심볼 삽입 완료: %s\n", name);
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
                printf("심볼이 존재합니다. 심볼 이름: %s\n", name);
                return symbol;
            }
            symbol = symbol->next;
        }
        scope = scope->parent;
    }
    printf("심볼이 존재하지 않습니다. 심볼 이름: %s\n", name);
    return NULL;
}

// 두 타입이 일치하는지를 비교하는 함수
int is_same_type(TypeInfo *type1, TypeInfo *type2) {
    // 둘 다 NULL이면 동일한 것
    if (type1 == NULL && type2 == NULL) {
        printf("타입 비교 실패: 둘 다 NULL\n");
        return 1;
    }

    // 한 쪽만 NULL이면 다른 타입
    if (type1 == NULL || type2 == NULL) {
        printf("타입 비교 실패: 한 쪽만 NULL\n");
        return 0;
    }

    if ((type1->type == TYPE_NULLPTR && type2->type == TYPE_POINTER) ||
        (type2->type == TYPE_NULLPTR && type1->type == TYPE_POINTER)) {
        return 1;
    }


    // 타입의 종류가 다르면, 다른 타입
    if (type1->type != type2->type) {
        printf("타입 비교 실패: 타입 종류가 다름\n");
        return 0;
    }

    // 구조체 타입의 경우에는 구조체 이름을 비교해줘야 함.
    if (type1->type == TYPE_STRUCT) {
        // 구조체 이름이 없으면, 다른 타입
        if (type1->struct_name == NULL || type2->struct_name == NULL) {
            printf("타입 비교 실패: 구조체 이름이 없음\n");
            return 0;
        }
        // 구조체 이름이 다르면, 다른 타입
        if (strcmp(type1->struct_name, type2->struct_name) != 0) {
            printf("타입 비교 실패: 구조체 이름이 다름\n");
            return 0;
        }
    }

    // 배열 타입의 경우에는 배열의 사이즈를 비교해줘야 함.
    if (type1->type == TYPE_ARRAY) {
        if (type1->array_size != type2->array_size) {
            printf("타입 비교 실패: 배열 사이즈가 다름\n");
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
void add_param(ParamList* list, const char* name, TypeInfo* type) {
    // 파라미터 노드 메모리 할당
    ParamNode* node = (ParamNode*)malloc(sizeof(ParamNode));
    node->name = strdup(name);
    node->type = deep_copy_typeinfo(type);
    node->next = NULL;

    // 파라미터 리스트가 비어있지 않으면, 리스트의 tail 노드의 next 포인터를 현재 추가한 파라미터 노드로 업데이트
    if(list->tail != NULL) {
        // 파라미터 리스트의 tail 노드의 next 포인터를 현재 추가한 파라미터 노드로 업데이트
        list->tail->next = node;
    } else { // 파라미터 리스트가 비어있으면, 파라미터 리스트의 head 노드를 현재 추가한 파라미터 노드로 업데이트
        list->head = node;
    }
    // 파라미터 리스트의 테일을 현재 추가한 파라미터 노드로 업데이트
    list->tail = node;
}

void insert_param_list_to_scope(ParamList* list){
    ParamNode* current_node = list->head;

    // 파라미터 리스트의 모든 노드를 순회하면서 심볼 테이블에 추가
    while(current_node != NULL) {
        if(!insert_symbol(current_node->name, current_node->type)){
            // 중복 선언 오류 발생 시, 에러 메시지 출력
            printf("중복 선언 오류: %s\n", current_node->name);
        }
        // 다음 노드로 이동
        current_node = current_node->next;
    }
}

// 스코프 내의 모든 심볼들을 fieldInfo 리스트로 변환함.
FieldInfo* convert_scope_to_filed_list() {
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
        field->type = symbol->type;
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
        printf("구조체 타입이 아닙니다.\n");
        return NULL;
    }
    
    if (struct_type->type != TYPE_STRUCT) {
        printf("구조체 타입이 아닙니다.\n");
        return NULL;
    }
    
    if (!struct_type->field_list) {
        printf("필드 리스트가 없습니다.\n");
        return NULL;
    }

    FieldInfo *field = struct_type->field_list;

    while(field != NULL) {
        printf(" 필드 탐색 중: %s\n", field->name);
        if (strcmp(field->name, field_name) == 0) {
            printf("필드 일치: %s\n", field->name);
            return field->type;
        }
        field = field->next;
    }
    printf("필드를 찾을 수 없습니다: %s\n", field_name);
    return NULL;
}


// 깊은 복사
TypeInfo* deep_copy_typeinfo(TypeInfo* src) {
    if(src == NULL) {
        return NULL;
    }

    TypeInfo* dst = malloc(sizeof(TypeInfo));
    dst->type = src->type;
    dst->next = deep_copy_typeinfo(src->next);
    dst->struct_name = src->struct_name ? strdup(src->struct_name) : NULL;
    dst->array_size = src->array_size;
    dst->is_lvalue = src->is_lvalue;
    dst->field_list = deep_copy_field_list(src->field_list);

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

