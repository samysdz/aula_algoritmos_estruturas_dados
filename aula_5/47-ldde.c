//gcc 47-ldde.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tItem {
    int chave;
    struct tItem *ant, *prox;  
} Item;

typedef struct tLista {
    Item *primeiro, *ultimo;     
    int quantidade;   
} Lista;

Lista * criaListaVazia () {
    Lista *lista = malloc (sizeof (Lista));
    lista -> primeiro = lista -> ultimo = NULL;
    lista -> quantidade = 0;
    return lista;
}

Item * criaItem (int x) {
    Item *item = malloc (sizeof (item));
    item -> chave = x;
    item -> ant = item -> prox= NULL;
    return item;
}


void liberaLista (Lista *lista) {
    Item *ant = NULL, *atu = lista -> primeiro;
    while (atu != NULL) {
        ant = atu;
        atu = atu -> prox;
        free (ant);
    }
    free (lista);
}


int vazia (Lista *lista) {
    return lista -> primeiro == NULL;
}


void imprimir (Lista *lista) {
    Item *atu = lista -> primeiro;
    while (atu != NULL && atu -> prox != NULL) {
        printf("%d ", atu -> chave);
        atu = atu -> prox;
    }
    if (atu != NULL) {
        printf("%d\n", atu -> chave);
    }
}

void imprimirReverso (Lista *lista) {
    Item * atu = lista -> ultimo;
    while (atu != NULL && atu -> ant != NULL) {
        printf ("%d ", atu -> chave);
        atu = atu -> ant;
    }
    if (atu != NULL) {
        printf ("%d\n", atu -> chave);
    }
}

Item * buscaPosicao (Lista * lista, int x) {
    Item *atu = lista -> primeiro;
    while (atu != NULL && x > atu -> chave) {
        atu = atu -> prox;
    }
    return atu;
}

void inserir (Lista *lista, int x) {
    Item *novo = criaItem(x);
    if (vazia (lista)) {
        lista -> primeiro = lista -> ultimo = novo;
        lista -> quantidade++;
    }
    else {
        Item *atu = buscaPosicao (lista, x);
        if (atu != NULL && atu -> chave == x) {
            free (novo);
        }
        else {
            if (atu == NULL) {
                (lista -> ultimo) -> prox = novo;
                novo -> ant = lista -> ultimo;
                lista -> ultimo = novo;
            }
            else if (atu -> ant == NULL) {
                lista -> primeiro = novo;
                atu -> ant = novo;
            }
            else {
                (atu -> ant) -> prox = novo;
                novo -> ant = atu -> ant;
                atu -> ant = novo;
            }
            novo -> prox = atu;
            lista -> quantidade++;
        }
    }
}


void remover (Lista *lista, int x) {
    Item *atu = buscaPosicao (lista, x);
    if (atu != NULL && atu -> chave == x) {
        if (atu -> ant == NULL) {
            lista -> primeiro = atu -> prox;
            if (atu -> prox != NULL) {
                (atu -> prox) -> ant = NULL;
            }
            else {
                lista -> ultimo = NULL;
            }
        }
        else if (atu -> prox == NULL) {
            (atu -> ant) -> prox = NULL ;
            lista -> ultimo = atu -> ant;
        }
        else {
            (atu -> ant) -> prox = atu -> prox;
            (atu -> prox) -> ant = atu -> ant;
        }
        lista -> quantidade--;
        free (atu);
    }
}

int main () {
    char op;
    int x;
    Lista *lista = criaListaVazia ();
    while (scanf (" %c", &op) != EOF) {  // leitura com um espaco em branco antes de %c
        switch (op) {
            case 'I': scanf ("%d", &x);
                      inserir (lista, x);
                      break;
            case 'E': scanf ("%d", &x);
                      remover (lista, x);
                      break;
            case 'M': imprimir (lista);
                      break;
            case 'R': imprimirReverso (lista);
                      break;
        }
    }
    liberaLista(lista);
    return 0;
}
