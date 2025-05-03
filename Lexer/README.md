# Lexer

# 1. 준비

##  개발 환경 세팅

- Jcloud 환경
- Ubuntu 24.04
- flex, gcc 설치
- VSCode에서 SSH 연결해서 코드 작성

##  학습

- 프로그래밍 언어의 문법적 특성을 파악
- lex 사용방법에 관해 학습
- 기존 C언어에 더해서 새로운 요구사항 학습
    - 1 .. 50 == 1~50을 의미함.
    - /* */ 주석 사이에 /* */를 넣을 수 있어야 함.

#  2. Lex 기본 구조 만들기

Lex 프로그램은 크게 세 가지의 Section으로 구성되어있음.

```cpp
%{ ... %}    // C 코드 삽입 (전역 변수나 include 등)
%%
...          // Lex 정규식 + 동작 정의
%%
main()       // 실행 시작 함수
```

-  subc.l 기본 구조 작성
- main() 함수에서 yylex()를 호출하도록 함
- 상태 선언 (%start AA BB)

###  구조

- **Definition Section** (%{ %}): 헤더 및 전역변수
- **Rules Section** (%% ... %%): 각 토큰별 정규표현식과 동작을 정의
- **User Code Section:** main() 함수를 작

#  3. Regular Expression and Basic Token

Regular Expression을 통해 문자를 인식하고, 인식된 문자열(lexeme)에 따라서 동작을 지정해줄 수 있음.

다음의 예를 보면 하나 이상의 변수를 인식하는 경우 이에 대해서 ID로 출력해주는 것! 여기서 yytext는 매칭된 문자열 자체를 담고있는 전역변수로 lex가 제공해줌.

```cpp
[a-zA-Z_][a-zA-Z0-9_]*   { printf("ID\t%s\n", yytext); }
```

### 해야할 일

-  모든 **keyword**, **identifier**, **operator**, **number**, **whitespace**에 대해 **정규표현식**을 정의.
- 우선순위에 주의해서 순서를 정함. (e.g., keyword가 identifier보다 먼저)
- yytext를 이용해 적절한 lexeme을 출력하도록 함.

> Compiler는 왼쪽에서 오른쪽으로 앞에서부터 순서대로 읽어감. 여러 개의 Regular Expression중 가장 먼저 매칭되는 규칙을 찾음. 만약 여러 개가 매칭되는 경우 더 긴 문자열이 우선이며, 그 중에서도 먼저 정의된 규칙(위)가 우선임.

다음의 순서대로 정규표현식을 정의하자~!

1. **Keywords (키워드)**
2. **Operators / Delimiters (연산자, 구분자)**
3. **Number (숫자: 정수, 실수)**
4. **Identifier (식별자)**
5. **Whitespace (공백)**
6. **Comments (주석)** → Start condition 따로 처리 (주석 모드로 전환)

### 정수와 실수 처리

INT와 FLOAT 구분해서 인식

```cpp
<INITIAL>{float_const}   { printf("F\t%s\n", yytext); }
<INITIAL>{int_const}     { printf("INT\t%s\n", yytext); }
```

- > 1.  → 허용
- > .5 → 허용 안됨
- > 1..5 → INT + OP + INT 로 해석해야 함



# 4. 중첩 주석 처리

###  /* ... */ 안에 또 다른 주석이 들어가는 주석을 처리

Lex는 StartCondition을 통해서 상태 전환이 가능함.

예를들어서 `/*` 을 만나는 경우 `BEGIN(COMMENT);` 를 통해서 주석으로 들어가고 `depth++` 로 깊이를 하나 증가시킴. 또한, `*/` 를 만나는 경우 `depth--` 로 depth를 감소시킴. 또한, `depth == 0` 일 때 `BEGIN(CODE)`로 복귀함.

```cpp
<NORMAL>"/*" {
    commentdepth = 1;
    BEGIN COMMENT;
}
<COMMENT>"/*" {
    commentdepth++;
}
<COMMENT>"*/" {
    commentdepth--;
    if (commentdepth == 0)
        BEGIN NORMAL;
}
<COMMENT>.|\n ;
```

#  5. `..` 연산자 처리

1 . . 5 ← 이걸 뭘로 나눌까? → Lex에서는 두 가지경우가 존재함. 이걸 정확히 분리해줘야함.

-  "1." + ".5"? -> 오류!
- "1" + ".." + "5"? -> 우리가 원하는 것

### Lookahead

- 1..5는 INT .. INT로 인식
- float와 헷갈리지 않도록 . + 숫자는 실수로, ..은 연산자로 구분
- 이 과정에서 lookahead 기법을 사용해야함. 즉, `.` 뒤에 또 다른 `.`이 나오는지를 확인해야함.

```cpp
".."/[0-9]     { printf("OP\t%s\n", yytext); } // range operator
[0-9]+"."[0-9]*([eE][+-]?[0-9]+)?/[^.]    { printf("FLOAT\t%s\n", yytext); } // float
-?[0-9]+                 { printf("INT\t%s\n", yytext); } // integer
```

or (아래에는 float에 lookahead 붙이지 않았음)

```cpp
".."/[0-9]     { printf("OP\t%s\n", yytext); }  // 먼저 정의
[0-9]+"."[0-9]*([eE][+-]?[0-9]+)?     { printf("FLOAT\t%s\n", yytext); } // 뒤에 둠
-?[0-9]+                   { printf("INT\t%s\n", yytext); }
```

#  6. Test

다음의 코드를 테스트함.

```cpp
/************************
   /* nested comments*/
 ************************/
struct _point {    loat x, y, z; int color;
} point[20];
struct _line {    truct _point *p[2]; int color; float meter = 0.5;
} line[20];

1..50
```

다음의 결과가 나와야함.

```cpp
KEY	struct
ID	_point
OP	{
ID	loat
ID	x
OP	,
ID	y
OP	,
ID	z
OP	;
KEY	int
ID	color
OP	;
OP	}
ID	point
OP	[
INT	20
OP	]
OP	;
KEY	struct
ID	_line
OP	{
ID	truct
ID	_point
OP	*
ID	p
OP	[
INT	2
OP	]
OP	;
KEY	int
ID	color
OP	;
KEY	float
ID	meter
OP	=
F	0.5
OP	;
OP	}
ID	line
OP	[
INT	20
OP	]
OP	;
INT	1
OP	..
INT	50
```



# 완성을 위한 Checklist

### 기본 구조

- [ ] subc.l 파일에 Lex 기본 구조 (%{ %}, %%, main())를 만든다.
- [ ] main() 함수에 BEGIN NORMAL;과 yylex(); 호출을 추가한다.
- [ ] int commentdepth = 0;를 선언하고 %start NORMAL COMMENT로 상태를 정의한다.
- [ ] Keyword들을 정규표현식으로 정의하고, identifier보다 위에 배치한다.
- [ ] Identifier 패턴을 [a-zA-Z_][a-zA-Z0-9_]*로 작성하고 ID로 출력한다.
- [ ] 모든 operator (++, --, {, }, ==, =, +=, .., 등)를 정규표현식으로 정의한다.
- [ ] 모든 출력은 printf("TYPE\t%s\n", yytext); 형태로 작성한다.

### ..연산자 

- [ ] .. 연산자를 /[0-9] lookahead와 함께 정의하고 float보다 위에 배치한다.
- [ ] Float은 [0-9]+"."[0-9]*([eE][+-]?[0-9]+)? 형태로 정의하고 .5는 허용하지 않는다.
- [ ] 정수는 -?[0-9]+ 패턴으로 정의한다.
- [ ] whitespace ([ \t\n]+)는 무시되도록 정의한다.

### 중첩 주석

- [ ] 주석 시작 /*를 만나면 BEGIN COMMENT, commentdepth++를 수행한다.
- [ ] 주석 안에서 또 다른 /*를 만나면 commentdepth++ 한다.
- [ ] */를 만나면 commentdepth-- 하고, commentdepth == 0이면 BEGIN NORMAL로 돌아온다.
- [ ] COMMENT 상태에서 나머지 문자들은 무시한다 (.|\n ;).

### 출력 및 제출

- [ ] 출력 형식이 반드시 TYPE<tab>lexeme (\t) 형식으로 나오도록 한다.
- [ ] Makefile을 작성해서 make 명령어로 빌드가 가능하도록 한다.
- [ ] subc 실행 파일이 생성되고, ./subc input.c와 같은 테스트가 가능하다.
- [ ] shortex.c 예제처럼 실제 테스트 케이스를 입력하고 결과가 예상과 일치하는지 확인한다.
- [ ] 다양한 입력(1..5, 3.14, nested comments)으로 테스트하고 예상대로 작동하는지 점검한다.
- [ ] 최종 제출 전 subc.l, Makefile, 필요한 소스 파일만 zip으로 압축한다.
- [ ] 압축 파일 이름은 Compiler_Project1_학번.zip 형식으로 지정한다.
- [ ] .o, lex.yy.c, subc 실행 파일 등 불필요한 빌드 산출물은 zip에 포함하지 않는다.
- [ ] LMS에 정상 제출되었는지, 제출 마감 시간을 지켰는지 확인한다.