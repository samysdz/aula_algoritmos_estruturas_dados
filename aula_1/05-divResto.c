// gcc 05-divResto.c -o prog.exe

#include <stdio.h>

int main () {
  int a,b;
  scanf("%d", &a);
  scanf("%d", &b);
  printf("%d %d", a/b, a%b);
  return 0;
}