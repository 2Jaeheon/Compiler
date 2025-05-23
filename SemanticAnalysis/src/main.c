#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"  // 우리가 만든 심볼 관련 구조체와 함수 선언 포함

int main() {
    // 심볼 시스템 초기화: 전역 스코프 생성
    init_symbol_system();
    printf("전역 스코프가 초기화되었습니다.\n");

    // 전역 스코프에 하나의 심볼 테이블이 존재
    if (current_scope != NULL) {
        printf("current_scope가 유효. 전역 스코프가 존재.\n");
    }

    // 새 스코프를 생성하고 진입 (임시 테스트용)
    SymbolTable* new_scope = create_symbol_table(current_scope);
    current_scope = new_scope;
    printf("새 스코프를 생성하여 진입했습니다.\n");

    // 스코프를 종료하고 이전 스코프로 복귀
    SymbolTable* old_scope = current_scope;
    current_scope = current_scope->parent;
    free_symbol_table(old_scope);
    printf("현재 스코프를 해제하고 이전 스코프로 복귀\n");
    
    // ========== push & pop 함수 테스트 ==========

    init_symbol_system();  // 전역 스코프 초기화
    printf("전역 스코프 초기화 완료\n");

    push_scope(); // 첫 번째 블록 진입
    push_scope(); // 중첩 블록 진입

    pop_scope();  // 중첩 블록 탈출
    pop_scope();  // 전역 스코프 복귀


    // 타입 정의 예시 (int 타입)
    push_scope();         // 블록 진입
    TypeInfo* int_type = (TypeInfo*)malloc(sizeof(TypeInfo));
    int_type->type = TYPE_INT;
    int_type->next = NULL;
    int_type->struct_name = NULL;

    insert_symbol("a", int_type);  // 성공
    insert_symbol("a", int_type);  // 중복 실패

    pop_scope(); // 스코프 탈출

    return 0;
}