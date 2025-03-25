%s AA BB

%%
// AA, BB 모드를 정의했음.
<AA>magic { printf("first\n"); BEGIN BB; }
<BB>magic { printf("second\n"); BEGIN AA; }
%%
// 처음에는 AA모드니까 first -> BB로 전환되어서 second 출력되고 AA로 변환 -> first 출력


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

	// AA모드로 시작하도록 정의해놨음. -> 이거 안 하면 안 됨. 모드를 설정했기 때문.
    BEGIN AA;
	yylex();
	return 0;
}
