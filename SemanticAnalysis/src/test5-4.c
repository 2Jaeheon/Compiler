int func1(int a, char b) { return 0; }
int func2(int a, char b) { return 'c'; } /* OK */
int func1() { return 0; } /* error: redeclaration */