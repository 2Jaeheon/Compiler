#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

SymbolTable* current_scope = NULL;

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

void push_scope() {
    SymbolTable *new_scope = create_symbol_table(current_scope); //현재 스코프를 부모로 연결해줌.
    current_scope = new_scope;
    printf("push_scope 함수를 통해서 새로운 스코프를 생성하고 진입했습니다.\n");
}

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

