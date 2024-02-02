//gcc 30-ordenadoDecrescente.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

char resposta(int *A, int n) {
  char r = 'S';
  for(int i = 0; i < n-1; i++) {
    if(A[i]<A[i+1]) {
      r = 'N';
      break;
    } 
  }
  return r;
}

int main () {
  int n, x, i = 0, r;
  int *v = malloc(sizeof(int)*n);
  while (scanf("%d",&n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d",&v[i]);
    }
    r = resposta(v,n);
    printf("%c\n",r);
  }
  free(v);
  return 0;
}
