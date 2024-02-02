//gcc 26-diaAnteriorStruct.c -o prog.exe

#include <stdio.h>

typedef struct tData {
  int dia, mes, ano;
} Data;

int isBissexto (int ano) {
  return ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0));
}

int ultimoDiaDoMes (int mes, int ano) {
  int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isBissexto(ano)) {
    dias[2]++;
  }
  return dias[mes];
}

int isValida (Data dt) {
  int dia = dt.dia, mes = dt.mes, ano = dt.ano;
  return (1 <= dia && dia <= ultimoDiaDoMes(mes,ano) && 1 <= mes & mes <= 12);
}

Data diaAnterior (Data dt) {
  dt.dia--;
  if (!isValida (dt)) {
    dt.dia = ultimoDiaDoMes (dt.mes-1, dt.ano);
    dt.mes--;
    if (!isValida (dt)) {
      dt.mes = 12;
      dt.dia = ultimoDiaDoMes (dt.mes, dt.ano);
      dt.ano--;
    }
  }
  return dt;
}

int main (){
  Data dt;
  scanf ("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
  dt = diaAnterior(dt);
  printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
  return 0;
}