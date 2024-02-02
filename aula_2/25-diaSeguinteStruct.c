//gcc 25-diaSeguinteStruct.c -o prog.exe

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

Data diaSeguinte (Data dt) {
  dt.dia++;
  if (!isValida (dt)) {
    dt.dia = 1;
    dt.mes++;
    if (!isValida (dt)) {
      dt.mes = 1;
      dt.ano++;
    }
  }
  return dt;
}

int main (){
  Data dt;
  scanf ("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
  dt = diaSeguinte (dt);
 ´printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
  return 0;
}