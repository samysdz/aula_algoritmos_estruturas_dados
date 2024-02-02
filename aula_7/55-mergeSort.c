//gcc 55-mergeSort.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

void imprimir (int *v, int n) {
  int i;
  for (i = 0; i < n -1; i++) {
    printf("%d ", v[i]);
  }
  if (n > 0) {
    printf("%d\n", v[n-1]);
  }
}

void intercala (int *v, int  e, int m, int d) {
  int n = d - e;
  int *vaux = malloc (sizeof (int) * n);
  int i = 0, j = e, k = m;
  while (j < m && k < d) {
    if (v[j] < v[k]) {
      vaux[i++] = v[j++];
    }
    else {
      vaux[i++] = v[k++];
    }
  }
  while (j < m) {
    vaux[i++] = v[j++];
  }
  while (k < d) {
    vaux[i++] =v [k++];
  }
  for (i = 0; i < n; i++) {
    v[e+i] = vaux[i];
  }
  imprimir(vaux,n);
  free(vaux);
}

void mergeSortR(int *v, int e, int d) {
  int meio;
  if (e < d - 1) {
    meio = (d+e)/2;
    mergeSortR (v, e, meio);
    mergeSortR (v, meio, d);
    intercala(v, e, meio, d);
  }
}
void mergeSort (int *v, int n) {
  mergeSortR (v, 0, n);
}

int main () {
  int n, i;
  scanf ("%d", &n);
  int *v = malloc (sizeof (int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  mergeSort(v, n);
  free(v);
  return 0;
}