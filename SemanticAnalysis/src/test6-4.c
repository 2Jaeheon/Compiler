struct Point {
    int x;
    int y;
};

int main() {
    struct Point p;
    int a;
    int b;
    int c;

    a = p.x;
    b = p.z; /* error: not a struct member */
    c = p->x; /* error: not a struct pointer */
    d = 1.x; /* error: not a struct pointer */ /* 1은 구조체가 아니라서 에러 발생 */ 

}