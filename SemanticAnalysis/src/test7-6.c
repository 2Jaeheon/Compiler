int f() {
  return 1;
}

char g() {
  return 'x';
}

int h() {
  return 'a';
}

char k() {
  return 123;
}

int p() {
  return "hello";
}

char q() {
  return f();
}

char f() {
  int x;
  x = 10;
  return &x;
}