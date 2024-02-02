//gcc 46-fila.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tItem {
    int chave;
    struct tItem *prox; 
} Item;

typedef struct tFila {
    Item *inicio, *fim;   
} Fila;


Fila * criaFilaVazia () {
    Fila *fila = malloc (sizeof (Fila));
    fila -> inicio = fila -> fim = NULL;
    return fila;
}

Item * criaItem (int x) {
    Item *item = malloc (sizeof (item));
    item -> chave = x;
    item -> prox = NULL;
    return item;
}


void liberaFila (Fila *fila) {
    Item *ant = NULL, *atu = fila -> inicio;
    while (atu != NULL) {
        ant = atu;
        atu = atu -> prox;
        free (ant);
    }
    free (fila);
}

int vazia (Fila *fila) {
    return fila -> inicio == NULL;
}


void imprimir (Fila *fila) {
    Item *atu = fila -> inicio;
    while (atu != NULL && atu -> prox != NULL) {
        printf("%d ", atu -> chave);
        atu = atu -> prox;
    }
    if (atu != NULL) {
        printf("%d\n", atu -> chave);
    }
}

void enfileirar (Fila * fila, int x) {
    Item *novo = criaItem(x);
    if (vazia (fila)) {
        fila -> inicio = fila -> fim = novo;
    }
    else {
        (fila -> fim) -> prox = novo;
        fila -> fim = novo;
    }
}

int desenfileirar (Fila *fila) {
    if (!vazia (fila)) {
        Item *rem = fila -> inicio;
        int x = rem -> chave;
        fila -> inicio = rem -> prox;
        if (fila -> inicio == NULL) {
            fila -> fim = NULL;
        }
        free(rem);
        return x;
    }
    return -1;
}


int main () {
    char op;
    int x;
    Fila *fila = criaFilaVazia ();
    while (scanf (" %c", &op) != EOF) {  // leitura com um espaco em branco antes de %c
        switch (op) {
            case 'E': scanf ("%d", &x);
                      enfileirar (fila, x);
                      break;
            case 'D': x = desenfileirar (fila);
                      if (x >= 0) {
                          printf ("<%d>\n", x);
                      }
                      break;
            case 'M': imprimir (fila);
                      break;
        }
    }
    liberaFila(fila);
    return 0;
}
