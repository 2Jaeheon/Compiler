# 프로젝트 개요
Lex(Flex)와 Yacc(Bison)를 이용하여 C 언어의 파서를 구현.
C 코드가 주어졌을 때, 해당 코드가 문법적으로 올바른지 판단하고,
그 판단 과정을 reduce 로그로 출력하는 시스템을 구현.

# 전체적인 동작 과정
- C언어로 작성된 파일을 Parser에 입력
- main() 함수에서 파일을 열어 yyin을 통해서 입력 소스를 지정
- yylex() 또는 yyparse() 함수 호출로 분석 시작
- Yacc는 입력에 따라 어떤 토큰이 필요한지를 판단하고, 그때마다 Lex의 yylex()를 호출
- 그러면 Lex는 실제 입력 문자열을 분석하여 해당 토큰을 반환
- Yacc은 Lex에게 받은 토큰을 가지고 Shift를 할지 Reduce를 할지 판단
- Reduce가 일어날 때마다 로그를 출력

즉, 다음과 같은 과정을 진행함.
1.	어휘 분석기(Lex)가 C 코드를 읽어 토큰(token)으로 전환
2.	구문 분석기(Yacc)가 토큰 시퀀스를 읽어 문법 구조를 생성
3.	reduce가 일어날 때마다 해당 문법 구조를 로그로 출력
```
[C 코드 입력]
    ↓
Lex (Flex) – 토큰화
    ↓
Yacc (Bison) – 문법 분석, reduce 로그 출력
```

# 문법 구조 (Grammer)
먼저 이 과제를 구현하기 위해서는 Grammer에 대한 사전 이해를 하는 것이 도움이 됩니다. 따라서 문법 구조에 대해서 먼저 짚고 넘어갑니다.

Grammer: 입력된 C 코드가 문법적으로 올바른지 판별을 하는 기준

Grammer는 다음과 같이 큰 논리적인 개념으로 나뉩니다
```
program
 └── ext_def_list
       ├── ext_def (변수 선언, 함수 정의, 구조체 정의)
              ├── type_specifier (int, char 등)
              ├── pointers (포인터)
              ├── ID, 배열 등
              └── func_decl compound_stmt (함수 정의)
```

### 이해를 위 한 각 용어들
| **문법 요소**      | **역할 (기능)**       | **설명**                                    |
| -------------- | ----------------- | ----------------------------------------- |
| program        | 프로그램의 시작점         | 하나의 C 프로그램 전체를 표현하는 최상위 단위                |
| ext_def_list   | 외부 정의들의 나열        | 여러 개의 전역 정의(함수, 변수, 구조체 등)를 연속적으로 배치하는 구조 |
| ext_def        | 외부 정의 단위          | 함수 정의, 전역 변수 선언, 구조체 정의 등을 하나씩 표현         |
| type_specifier | 자료형 정의            | int, char, struct 등 타입을 지정하는 구성요소         |
| pointers       | 포인터 여부 지정         | 변수나 매개변수가 포인터인지 여부를 표현                    |
| func_decl      | 함수 선언부            | 함수의 이름, 반환형, 인자 등을 정의하는 부분                |
| param_list     | 함수 인자 목록          | 함수에 전달되는 여러 개의 인자들을 순차적으로 표현              |
| param_decl     | 하나의 함수 인자 선언      | 각각의 인자에 대한 타입, 이름, 포인터 여부 등을 포함           |
| compound_stmt  | 중괄호 블록            | 여러 문장과 선언이 포함된 코드 블록. 함수 몸체나 제어문에서 사용     |
| def_list       | 지역 변수 선언들의 모음     | 블록 안에서 선언되는 여러 변수들을 순차적으로 표현              |
| def            | 하나의 지역 변수 선언      | 단일 변수 또는 배열의 선언을 의미                       |
| stmt_list      | 문장들의 나열           | 여러 개의 실행 문장을 순차적으로 처리하는 리스트 구조            |
| stmt           | 하나의 실행 문장         | 대입, 조건문, 반복문, return 등 실행 가능한 한 문장을 표현    |
| expr           | 표현식               | 연산, 대입, 비교 등 결과를 산출하는 계산식 표현              |
| binary         | 이항 연산 표현식         | 두 값을 이용한 연산 (산술, 논리, 비교 등)을 표현            |
| unary          | 단항 표현식 및 최소 단위 표현 | 상수, 변수, 배열/구조체 접근, 함수 호출 등 가장 기본적인 표현 단위  |
| args           | 함수 호출 시의 인자 목록    | 함수에 실제로 전달되는 여러 개의 인자 표현                  |
| expr_e         | 선택적 표현식           | 비워둘 수 있는 표현식 (주로 for 루프에서 사용)             |


#### Program - 프로그램
이는 프로그램의 시작점으로 ext_def_list가 몸체를 담당함

#### ext_def_list - 외부 정의 리스트
```
ext_def_list : ext_def_list ext_def
             | %empty ;
```
외부 정의 리스트로 여러개의 ext_def가 처리가 가능 <br>
%empty는 epsilon으로 정의가 하나도 없는 경우를 나타냄

#### ext_def - 외부 정의
```
ext_def : type_specifier pointers ID ';'
        | type_specifier pointers ID '[' INTEGER_CONST ']' ';'
        | STRUCT ID '{' def_list '}' ';'
        | func_decl compound_stmt ;
```
외부 정의로서 다음과 같은 요소들을 나타냄. <br>
이 문법들이 실제로 가장 많이 reduce 됨
- 변수 선언 
- 배열 선언
- 구조체 정의
- 함수 정의 

#### type_specifier – 타입 지정자
```
type_specifier : TYPE
               | struct_specifier ;
```
int, char, struct(구조체) 타입을 지정함.

#### func_decl – 함수 선언부
```
func_decl : type_specifier pointers ID '(' ')'
          | type_specifier pointers ID '(' param_list ')' ;
```
반환 타입, 함수 이름, 매개변수 리스트로 구성됨<br>
main() 함수도 이 문법에 포함.

#### compound_stmt – 중괄호 블록
```
compound_stmt : '{' def_list stmt_list '}' ;
```
함수의 몸체, 조건문 등에서 사용되는 중괄호 구조

#### def_list, def – 지역 변수 정의
```
def_list : def_list def
         | %empty ;

def : type_specifier pointers ID ';'
    | type_specifier pointers ID '[' INTEGER_CONST ']' ';' ;
```
지역 변수를 처리해줌.<br>
def는 한 개의 선언문, def_list는 선언문의 리스트를 의미함.

#### stmt_list, stmt – 실행 문장 목록
```
stmt_list : stmt_list stmt
          | %empty ;

stmt : expr ';'
     | compound_stmt
     | RETURN expr ';'
     | ';'
     | IF '(' expr ')' stmt
     | IF '(' expr ')' stmt ELSE stmt
     | WHILE '(' expr ')' stmt
     | FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt
     | BREAK ';'
     | CONTINUE ';' ;
```
- 모든 실행문은 stmt로 정의
- 표현식, 조건문, 반복문, return문 등 모든 종류 포함

#### expr, binary, unary – 표현식의 핵심
```
expr : unary '=' expr
     | binary ;

binary : binary '+' binary
       | binary '-' binary
       | binary '*' binary
       | binary '/' binary
       | binary LOGICAL_OR binary
       | binary RELOP binary
       | unary %prec '=' ;
```
- expr = expr, a + b, x == y 등 복합 표현식들을 처리
- 우선순위와 결합성은 %left, %right, %prec를 통해 정의됨

#### unary – 단항 연산과 기본값들
```
unary : '(' expr ')'
      | INTEGER_CONST
      | CHAR_CONST
      | ID
      | '-' unary %prec '!'
      | '!' unary
      | unary '[' expr ']'
      | unary '.' ID
      | unary STRUCTOP ID
      | unary '(' args ')'
      | SYM_NULL ;
```
문법 구조에서 단항 표현식을 의미하는 non-terminal symbol<br>
10, -x, a[3], f(x, y) 등의 표현을 모두 수용


# Conflict 해결 전략
기본적으로 구현하는 문법이 Ambiguous한 문법임
따라서 모호하지 않도록 우선순위를 설정해주는 과정이 필요함
또한, 다양한 표현식을 다루어야 하기 때문에 복잡한 문법이고, 이 과정에서 Shift/Reduce Conflict가 발생하는데 이를 해결해줘야 함.

### Solution1: 연산자 우선순위 및 결합 방향 지정
동일한 시작 토큰을 가지는 여러 문법 규칙이 충돌하는 경우,
어떤 것을 우선적으로 shift할지, reduce할지 정해줘야함.

Yacc의 precedence 지정자를 통해서 해결함
```
%left ','                   // 쉼표 연산자
%right '='                 // 대입은 오른쪽 결합
%left LOGICAL_OR           
%left LOGICAL_AND          
%left EQUOP                
%left RELOP                
%left '+' '-'              
%left '*' '/' '%'          // 산술 연산자 우선순위
```
- a = b + c * d; 를 파싱할 때:
- *의 우선순위가 +보다 높고, +가 =보다 높음
- 따라서 c * d → b + (c * d) → a = (b + (c * d)) 순으로 파싱됨
- Conflict가 발생하지 않고, 정확한 AST(구문 트리)를 구성 가능

### Solution2: 단항 연산자 처리
-a처럼 단항 음수 연산자와 이항 빼기 연산자가 동일한 기호(’-’)를 사용하여 충돌 발생<br>
단항 -, !, &, * 등의 연산자에는 우선순위 지시자(%prec) 사용<br>
UMINUS, DEREF와 같은 가상 토큰을 도입하여 우선순위를 직접 부여

```
%nonassoc LOWER_THAN_ELSE UMINUS
%right '!' '&' DEREF

unary
  : '-' unary %prec UMINUS         // 단항 마이너스
  | '*' unary %prec DEREF          // 포인터 역참조
  | INCOP unary %prec UMINUS       // 전위 증가
  ...
```
- %prec UMINUS를 사용함으로써, -a가 a - b와 충돌하지 않도록 함
- Yacc은 - 기호가 나왔을 때 context에 따라 적절한 문법 규칙을 선택할 수 있게 됨

### Solution3: 조건문 if-else문 모호성 해결
if (cond) if (inner) stmt; else stmt; <br>와 같이 중첩된 if-else 문에서
else가 어떤 if와 매칭되는지를 파악할 수 없어 Conflict 발생

```
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

stmt
  : IF '(' expr ')' stmt %prec LOWER_THAN_ELSE
  | IF '(' expr ')' stmt ELSE stmt
```
- IF (...) stmt %prec LOWER_THAN_ELSE는 ELSE보다 우선순위가 낮은 것으로 처리
- 	따라서 ELSE가 있는 경우 항상 두 번째 규칙(ELSE 버전)이 선택되어, “ELSE와 가장 가까운 IF”와 매칭되도록 

### Solution4: 구조체, 배열, 함수 호출 등 연산자 우선순위
a[3], s.member, ptr->x, func(x, y) 등의 표현식은 모두 unary로 분류되지만,
내부적으로 연산자 간의 우선순위 및 결합 방식이 다름
```
%left '[' '.' '('                // 구조체/배열/함수 접근 연산자 우선순위 낮춤
%left STRUCTOP INCOP DECOP       // 구조체 포인터 접근, 후위 연산자
```
- 배열 접근 a[3] → unary '[' expr ']'
- 구조체 접근 s.x, ptr->x → unary '.' ID, unary STRUCTOP ID
- 후위 증가/감소 연산자 → unary INCOP, unary DECOP
- 후위 연산자(++, –), 구조체 접근 등이 다른 연산자보다 우선적으로 Reduce되도록 우선순위를 배정

# 구현하면서 발생한 문제와 해결 방법
- 기존의 교재에서 나온 %precedence IF & %precedence ELSE로 해결하려고 하였으나, Bison에서 지원하지 않음 => 이를 해결하기 위해서 %prec을 사용함.

- Yacc 이전에 Lex에서 파싱이 제대로 이루어지지 않아서 Syntax Error를 발생함. => | 연산자로 여러 개 묶어놓은 부분에서 문제가 발생 -> | 로 나누지 않고 각 개별로 구현하였더니 정상 작동함.


# 참고사항
- 기본 Grammer는 파일로 제공됨
- Grammer의 Production rule은 변경하면 안 됨


