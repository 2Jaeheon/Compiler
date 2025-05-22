# Semantic Analysis

# 프로젝트 개요
이 프로젝트는 input C 코드가 의미에 부합하는지를 확인하는 과정입니다. 

이 프로젝트는 다음의 5가지 Semantic Error를 중점적으로 탐지합니다
- **Undeclared Variables & Functions**  
  선언되지 않은 식별자의 사용 여부 탐지
- **Re-declaration**  
  동일 스코프 내 중복 선언 탐지
- **Type Checking**  
  대입, 연산, 함수 호출 시 타입 불일치 검출
- **Structure & Structure Pointer Declaration**  
  구조체 정의 전 사용, 구조체 멤버 접근 오류 검출
- **Function Declaration**  
  함수 선언/정의의 일관성, 파라미터 및 반환 타입 오류 탐지

이 논리 구조를 기준으로 **Semantic Analysis의 커버리지를 판단**합니다.
<br><br>

# 실제 구현 흐름
다만, 위의 과정에서는 오류를 탐색하는 과정이기 때문에 다음과 같은 구현 과정으로 하나씩 진행합니다.

1. **심볼 테이블 및 스코프 시스템 구축**  
   `Symbol`, `SymbolTable`, `push_scope()`, `pop_scope()` 등 기본 구조 구현
2. **구현 연동: subc.y 내 Action 코드로 심볼 연동**  
   변수 선언 시 심볼 등록, 중복 선언 검사
3. **선언된 심볼 탐색 및 에러 처리**  
   `lookup_symbol()`을 활용한 undeclared 탐지 및 에러 메시지 출력
4. **타입 검사 고도화**  
   `TypeInfo`, `ExtendedTypeInfo`, `is_same_type()` 구현을 통한 정교한 타입 검사
5. **스코프 고도화**  
   함수, 구조체, 일반 블록 내 스코프 분리 및 shadowing 처리

기능이 복잡하고 처리해야 할 요소들이 많기 때문에 다음과 같이 5단계로 나누어, 구현을 순차적으로 쌓아나갈 수 있도록 마일스톤을 설정하여 진행합니다.