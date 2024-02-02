//gcc 33-selectionSort.c -o prog.exe

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


int selectionSort (int *A, int n) {
  int i, j, c, d = 0;
  for (i = 0; i < n-1; i++) {
    for (j= i + 1; j < n; i++) {
      if (A[i] > A[j]) {
        c = A[i];
        A[i] = A[j];
        A[j] = c;
        d++;
      }
    }
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
  d = selectionSort (v, n);
  printf ("Deslocamentos: %d\n",d);
  free (v);
  return 0;
}