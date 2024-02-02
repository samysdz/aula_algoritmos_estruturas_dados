// gcc 10-divisoresPares.c -o prog.exe

#include <stdio.h>
#include <math.h>

int main () {
  int a, b =0, c;
  scanf("%d", &a);
  for(c = 1; c<=a;c++){
    if(a%c==0 && c%2==0){
      b++;
    }
  }
  printf("%d\n",b);
  return 0;
}