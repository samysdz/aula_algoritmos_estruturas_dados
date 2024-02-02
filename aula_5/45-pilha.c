//gcc 45-pilha.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tItem {
    int chave;
    struct tItem *prox; 
} Item;

typedef struct tPilha {
    Item *topo;   
    int quantidade;  
} Pilha;


Pilha * criaPilhaVazia () {
    Pilha *pilha = malloc (sizeof (Pilha));
    pilha  -> topo = NULL;
    pilha -> quantidade = 0;
    return pilha;
}

Item * criaItem (int x) {
    Item *item = malloc (sizeof (item));
    item -> chave = x;
    item -> prox = NULL;
    return item;
}


void liberaPilha (Pilha *pilha) {
    Item *ant = NULL, *atu = pilha -> topo;
    while (atu != NULL) {
        ant = atu;
        atu = atu -> prox;
        free (ant);
    }
    free (pilha);
}

int vazia (Pilha *pilha) {
    return pilha -> topo == NULL;
}


void imprimir (Pilha *pilha) {
    Item *atu = pilha -> topo;
    while (atu != NULL && atu -> prox != NULL) {
        printf("%d ", atu -> chave);
        atu = atu -> prox;
    }
    if (atu != NULL) {
        printf("%d\n", atu -> chave);
    }
}

void empilha (Pilha *pilha, int x) {
    Item *novo = criaItem(x);
    novo -> prox = pilha -> topo;
    pilha -> topo = novo;
    pilha -> quantidade++;
}

int desempilha (Pilha *pilha) {
    if (!vazia (pilha)) {
        Item *rem = pilha -> topo;
        int x = rem -> chave;
        pilha -> topo = rem -> prox;
        pilha -> quantidade--;
        free(rem);
        return x;
    }
    return -1;
}


int main () {
    char op;
    int x;
    Pilha *pilha = criaPilhaVazia ();
    while (scanf (" %c", &op) != EOF) {  // leitura com um espaco em branco antes de %c
        switch (op) {
            case 'E': scanf ("%d", &x);
                      empilha (pilha, x);
                      break;
            case 'D': x = desempilha (pilha);
                      if (x >= 0) {
                          printf ("[%d\n", x);
                      }
                      break;
            case 'M': imprimir (pilha);
                      break;
        }
    }
    liberaPilha(pilha);
    return 0;
}
