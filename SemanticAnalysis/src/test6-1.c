struct Inner {
    int inner_x;
    char inner_y;
};

struct Outer {
    int outer_a;
    struct Inner inner_struct;
    char outer_b;
    int arr[10];
};