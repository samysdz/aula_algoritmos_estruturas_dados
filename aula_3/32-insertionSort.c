//gcc 32-racionaisStruct.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

void imprime (int *v, int n) {
  int i;
  for (i = 0; i < n-1; i++) {
    printf("%d ", v[i]);
  }
  if (n > 0) {
    printf("%d\n", v[n-1]);
  }
}

int insertionSort (int *A, int n) {
  int i, j, c, d = 0;
  for (j = 1; j < n; j++) {
    c = A[j];
    i = j - 1;
    while (i >= 0 && c < A[i]) {
      A[i+1] = A[i];
      d ++;
      imprime (A,n);
      i--;
    }
    A[i+1] = c;
    imprime (A,n);
  }
  return d;
}

int main () {
  int n, i, d;
  scanf("%d", &n);
  int *v = malloc (sizeof (int) * n);
  for (i = 0; i < n; i++) {
    scanf ("%d", &v[i]);  
  }
  d = insertionSort (v, n);
  printf ("Deslocamentos: %d\n",d);
  free (v);
  return 0;
}