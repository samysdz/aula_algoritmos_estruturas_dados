// gcc 09-imc.c -o prog.exe

#include <stdio.h>
#include <math.h>

int main () {
  float a, p, i;
  char *m;
  scanf("%f %f", &a, &p);
  i = p/(a*a);
  if (i<16){
    m = "Magreza grave";
  }
  else if (i<17){
    m = "Magreza moderada";
  }
  else if (i<18.5){
    m = "Magreza leve";
  }
  else if (i<25){
    m = "Saudavel";
  }
  else if (i<30){
    m =  "Sobrepeso";
  }
  else if (i<35){
    m = "Obesidade Grau I";
  }
  else if (i<40){
    m = "Obesidade Grau II (severa)";
  }
  else{
    m = "Obesidade Grau III (morbida)";
  }
  printf("%s\n", m);
  return 0;
}