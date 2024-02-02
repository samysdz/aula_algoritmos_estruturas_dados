// gcc 06-idade.c -o prog.exe

#include <stdio.h>

int main () {
  int a,c;
  char b[50];
  scanf("%d", &a);
  scanf("%s", b);
  scanf("%d", &c);
  printf("%s, voce completa %d anos de idade neste ano.",b, a-c);
  return 0;
}