# Parser 구현 단계
### Goal: 문자열 w가 들어올 때 이를 Grammer에 부합하는지를 확인해야 함.

# 1. 준비과정
- 과제를 진행하기 위해 Bottom-up Parser 개념 복습
- Project Instruction 상세하게 확인
- yacc & lex의 흐름 확인

# 2. 기본 구조 설정 및 Lexer 수정
- 각 토큰에 대해 정규 표현식과 return 값 정의
- Instruction에 지정한 모든 토큰을 처리
- Parser의 Declarations에 토큰을 정의


# 3. 우선순위 및 결합법 결정
- Goal: Shift/Reduce Conflict를 회피
- %left, %right, %nonassoc 선언
- %prec를 이용해 ambiguous rule 정리
- IF-ELSE의 Shift/Reduce 충돌 해결

# 4. Grammer
- Instruction에 나와있는 Grammer rule을 그대로 이용
- 수정 X
