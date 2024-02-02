//gcc 57-quickSort.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

void imprimir (int *v, int e, int d) {
  int i;
  for (i = e; i < d -1; i++) {
    printf("%d ", v[i]);
  }
  if (d > e) {
    printf("%d\n", v[d-1]);
  }
}

void troca (int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int particiona (int *v, int e, int d, int p) {
    troca (v, d-1, p);
    int j = e, i = j - 1;
    while (j < d - 1) {
        if (v[j] <= v[d-1]) {
            i++;
            troca (v, i, j);
        }
        j++;
    }
    i++;
    troca (v, i, d-1);
    return i;
}

void quickSortR (int *v, int e, int d) {
    if (e < d -1) {
        int p = d - 1;
        p = particiona (v, e, d, p);
        printf("Pivo: [%d] %d\n", p, v[p]);
        imprimir (v, e, d);
        quickSortR (v, e, p);
        quickSortR (v, p+1, d);
    }
}

void quickSort (int *v, int n) {
    quickSortR (v, 0, n);
}

int main () {
  int n, i;
  scanf ("%d", &n);
  int *v = malloc (sizeof (int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  quickSort(v, n);
  imprimir (v, 0,n);
  free(v);
  return 0;
}