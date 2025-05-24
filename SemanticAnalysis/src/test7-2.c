int main() {
    int a;
    int* p;
    int b;
    p = &a;
    *p = 10;
    p = NULL;
    a = NULL;
}