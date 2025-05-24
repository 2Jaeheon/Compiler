struct Point {
  int x;
  int y;
};

int main() {
    int a;
    int b;
    char c;
    struct Point p;

    a = b && c;
    a = b && p;
    a = b || c;
    a = b || p;
    a = b == c;
    a = b == p.x;

    a = b != c;
    a = b != p.x;

    a = b < c;
    a = b < p.x;

    a = b > c;
    a = b > p;

    a = a + b;
    a = a - p;
    a = a * c;
    a = a / p;
    a = a % b;

    return 0;
}