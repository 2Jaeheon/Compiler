%%
[\n\t ]     ;
숫자를 판별하고 싶을 때 사용 -> 음수, 소수 등 				action은 아래와 같음 읽은 숫자를 출력해줌.
-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) { printf("number %s\n", yytext); }
아래는 와일드카드 -> action 없음 => 왜 있는데? 공백과 넘버 이외의 문자는 처리 X, 이걸 제일 마지막에 써야 문제 없음. 우선순위에 따르기 때문. 와일드카드는 마지막에 쓰는게 안전하다.
.           ;

출력 make -> 파일만듬
./number test.c -> 실행

%%

#include <stdio.h>
int main(int argc, char ** argv)
{
	if (argc > 1) {
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file) {
			fprintf(stderr, "could not open %s\n", argv[1]);
			exit(1);	
		} 
		yyin = file;
	}
	yylex();
	return 0;
}
