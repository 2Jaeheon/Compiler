#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"  // 우리가 만든 심볼 관련 구조체와 함수 선언 포함

int main() {
    init_symbol_system();
    push_scope(); // 전역 내부 블록

    // int 타입 생성
    TypeInfo* int_type = malloc(sizeof(TypeInfo));
    int_type->type = TYPE_INT;
    int_type->next = NULL;
    int_type->struct_name = NULL;

    insert_symbol("x", int_type);  // 전역 블록에 삽입
    push_scope();                  // 중첩 스코프 진입

    // 같은 이름이 없으므로 상위에서 발견됨
    Symbol* found = lookup_symbol("x");
    if (found) {
        printf("'%s' 심볼이 발견됨\n", found->name);
    }

    // 없는 심볼 조회
    Symbol* not_found = lookup_symbol("y");
    if (!not_found) {
        printf("'y'는 선언되지 않음\n");
    }

    pop_scope(); // 내부 블록 나가기
    Symbol *symbol = lookup_symbol("x");
    if (symbol) {
        printf("'%s' 심볼이 발견됨\n", symbol->name);
    }
    pop_scope(); // 전역 스코프 나가기
    return 0;
}