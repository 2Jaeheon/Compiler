// 
letter	[A-Za-z]

%%
// ++ 먼저 뒤에 letter -> 액션 ( 뒤에 letter가 있을 때 ++을 읽는 것)
// leter 뒤에 ++ -> 액션 (뒤에 ++ 이 있을 떄 레터를 읽는것)
// 와일드 카드 안 쓰면 그냥 걸리지 않는 모든 것들 출력함.
"++"/{letter}   {printf("++a and yytext has %s\n",yytext);} 
{letter}/"++"   {printf("a++ and yytext has %s\n",yytext);} 
.               ;

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

