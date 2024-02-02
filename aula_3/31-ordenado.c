//gcc 31-ordenado.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

char resposta(int *A, int n) {
  char r = 'S', i = 0;
  if(A[i]<A[i+1]) {
    for(int i = 1; i < n-1; i++) {    
      if(A[i]>A[i+1]) {
      r = 'N';
      break;
      } 
    }
  }
  if(A[i]>A[i+1]) {
    for(int i = 1; i < n-1; i++) {
      if(A[i]<A[i+1]) {
      r = 'N';
      break;
      } 
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
