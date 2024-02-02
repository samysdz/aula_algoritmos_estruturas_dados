//gcc 24-datasStruct.c -o prog.exe

#include <stdio.h>

typedef struct tData {
  int dia, mes, ano;
} Data;

int isBissexto (iint ano) {
  return ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0));
}

int isValida (Data dt) {
  int dia = dt.dia, mes = dt.mes, ano = dt.ano;
  int ultimoDiaDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isBissexto(ano)) {
    ultimoDiaDoMes[2]++;
  }
  return (1 <= dia && dia <= ultimoDiaDoMes[mes] && 1 <= mes & mes <= 12);
}

int main (){
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      Data dt;
      scanf ("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
      if (isValida (dt)) {
        printf("DATA VALIDA\n");
      }
      else {
        printf("DATA INVALIDA\n");
      }
   }
  return 0;
}