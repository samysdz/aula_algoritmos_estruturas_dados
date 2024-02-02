// gcc 08-eq2.c -o prog.exe

#include <stdio.h>
#include <math.h>

int main () {
  int a, b, c;
  double x1, x2, delta;
  scanf("%d %d %d", &a, &b, &c);
  delta = b*b - 4.0*a*c;
  x1 = (-b + sqrt (delta))/(2.0*a);
  x2 = (-b - sqrt (delta))/(2.0*a);
  printf("%.4lf %.4lf", x1,x2);
  return 0;
}