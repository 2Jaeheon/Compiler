// c 코드의 헤더 부분에 들어감. library 및 global variables 선언, 카운트를 위해서 지금 해놓았음.
%{
unsigned charCount = 0, wordCount = 0, lineCount = 0; // global variables for count
%}

// regular expression
// 공백 white space, tab, newline을 제외한 모든 문자
word    [^ \t\n]+
// line의 개수를 샐 수 있음. 
eol     \n

// 실행은 make -> 실행파일 만들기(컴파일)
// 실행 ./wordcount text.c

%%
{word}  { wordCount++; charCount += yyleng; }
{eol}   { charCount++; lineCount++; }
.       { charCount++; }
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
	printf("%u %u %u\n", charCount, wordCount, lineCount);
	return 0;
}

