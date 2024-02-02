//gcc 23-bissexto.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

int isBissexto(int ano) {
  return ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0));
}

int main (){
  int ano;
  scanf("%d", &ano);
  if(isBissexto (ano)) {
    printf("ANO BISSEXTO\n");
  }
  else {
    printf("ANO NAO BISSEXTO\n");
  }
  return 0;
}