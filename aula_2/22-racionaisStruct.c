//gcc 22-racionaisStruct.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

struct tRacional{
  int numerador, denominador;
}Racional;

struct tRacional racional(int num,int denom){
  struct tRacional r;
  r.numerador = num;
  r.denominador = denom;
  return r;
}

struct tRacional negativo(struct tRacional r1){
  struct tRacional r;
  r.numerador = -r1.numerador;
  r.denominador = r1.denominador;
  return r;
}

struct tRacional soma(struct tRacional r1,struct tRacional r2){
  struct tRacional r;
  r.numerador = r1.numerador*r2.denominador + r2.numerador*r1.denominador;
  r.denominador = r1.denominador*r2.denominador;
  return r;
}
struct tRacional multiplica(struct tRacional r1,struct tRacional r2){
  struct tRacional r;
  r.numerador = r1.numerador*r2.numerador;
  r.denominador = r1.denominador*r2.denominador;
  return r;
}

struct tRacional divide(struct tRacional r1,struct tRacional r2){
  struct tRacional r;
  r.numerador = r1.numerador*r2.denominador;
  r.denominador = r1.denominador*r2.numerador;
  return r;
}

int mdc (int a, int b) {
  int i;
  for (i = a; i > 1; i--) {
    if (a% i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}

struct tRacional reduz(struct tRacional r1){
  struct tRacional r;
  int m = mdc (abs(r1.numerador), abs(r1.denominador));
  r.numerador = r1.numerador/m;
  r.denominador = r1.denominador/m;
  if(r1.denominador<0){
    r.numerador = -r.numerador;
    r.denominador = -r.denominador;
  }
  return r;
}

int main (){
  int num1, denom1, num2, denom2;
  char op;
  while(scanf("%d %d %c %d %d",&num1, &denom1, &op, &num2, &denom2) != EOF){
    struct tRacional r1 = racional(num1,denom1);
    struct tRacional r2 = racional(num2,denom2);
    struct tRacional r;
    switch(op){
      case '+':
        r = soma(r1,r2);
        break;
      case '-': 
        r = negativo(r2);
        r = soma (r1,r2);
        break;
      case '*': r = multiplica(r1,r2);
        break;
      case '/': r = divide(r1,r2);
        break;
    }
    r = reduz (r);
    printf("%d %d\n", r.numerador, r.denominador);
    }
  return 0;
  }