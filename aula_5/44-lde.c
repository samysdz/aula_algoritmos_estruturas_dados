//gcc 44-lde.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tItem {
    int chave;
    struct tItem *prox;  // ponteiro para proximo da lista
} Item;

typedef struct tLista {
    Item *inicio;     // ponteiro para o inicio da lista
    int quantidade;   // qtde de elementos na lista
} Lista;

// Aloca memoria para criar uma lista inicialmente vazia.
// Devolve o ponteiro para a lista alocada, com os campos inicializados:
// inicio vazio e quantidade zero.
Lista * criaListaVazia () {
    Lista *lista = malloc (sizeof (Lista));
    lista  -> inicio = NULL;
    lista -> quantidade = 0;
    return lista;
}

// Recebe um inteiro x.
// Aloca memoria para criar um novo item.
// Inicializa o valor da chave com x e o ponteiro prox com vazio.
Item * criaItem (int x) {
    Item *item = malloc (sizeof (item));
    item -> chave = x;
    item -> prox = NULL;
    return item;
}

// Deve-se liberar primeiro a cadeia de itens.
// Depois, no final, liberar o ponteiro da lista.
void liberaLista (Lista *lista) {
    Item *atu = lista -> inicio, *ant = NULL;
    while (atu != NULL) {
        ant = atu;
        atu = atu -> prox;
        free (ant);
    }
    free (lista);
}

// Recebe um ponteiro para uma lista.
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (Lista *lista) {
    return lista -> inicio == NULL;
}

// Imprime o conteudo da lista.
void imprimir (Lista *lista) {
    Item *atu = lista -> inicio;
    while (atu != NULL && atu -> prox != NULL) {
        printf("%d ", atu -> chave);
        atu = atu -> prox;
    }
    if (atu != NULL) {
        printf("%d\n", atu -> chave);
    }
}

// Recebe o ponteiro da lista e uma chave x.
// Devolve 1 se a lista contem a chave x, ou 0 caso contrario.
int buscar (Lista *lista, int x) {
    Item *atu = lista -> inicio;
    while (atu != NULL && x > atu -> chave) {
        atu= atu -> prox;
    }
    if (atu == NULL) {
        return 0;
    }
    return atu -> chave == x;
}

// Recebe um ponteiro para uma lista e uma chave x.
// Insere x na lista, caso ja nao exista.
// Ignora insercao de chaves repetidas.
// Deve tratar os 4 casos:
// (1) insercao em uma lista vazia;
// Se a lista nao estiver vazia, deve-se buscar a posicao de insercao.
// (2) insercao no fim da lista;
// (3) insercao no inicio da lista;
// (4) insercao no meio da lista.
void inserir (Lista *lista, int x) {
    Item *novo = criaItem(x);
    if (vazia (lista)) {
        lista -> inicio = novo;
        lista -> quantidade = 1;
    }
    else {
        Item *atu = lista -> inicio, *ant = NULL;
        while (atu != NULL && x > atu -> chave) {
            ant = atu;
            atu = atu -> prox;
        }
        if (atu != NULL && atu -> chave == x) {
            free (novo);
        }
        else {
            if (atu == NULL) {
                ant -> prox = novo;
            }
            else if (ant == NULL) {
                lista -> inicio = novo;
                novo -> prox = atu;
            }
            else {
                ant -> prox = novo;
                novo -> prox = atu;
            }
            lista -> quantidade++;
        }
    }
}

// Recebe um ponteiro para uma lista e uma chave x.
// Se a lista nao estiver vazia, remove x da lista, caso exista.
// Deve tratar os 3 casos:
// (1) remocao do inicio da lista;
// (2) remocao do fim da lista;
// (3) remocao do meio da lista.
void remover (Lista *lista, int x) {
    Item *atu = lista -> inicio, *ant = NULL;
    while (atu != NULL && x > atu -> chave) {
        ant = atu;
        atu = atu -> prox;
    }
    if (atu != NULL && atu -> chave == x) {
        if (ant == NULL) {
            lista -> inicio = atu -> prox;
        }
        else if (atu -> prox == NULL) {
            ant -> prox = NULL;
        }
        else {
            ant -> prox = atu -> prox;
        }
        free (atu);
        lista -> quantidade--;
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
            case 'R': scanf ("%d", &x);
                      remover (lista, x);
                      break;
            case 'B': scanf ("%d", &x);
                      if (buscar (lista, x)) {
                          printf ("SIM\n");
                      }
                      else {
                          printf ("NAO\n");
                      }
                      break;
            case 'L': imprimir (lista);
                      break;
        }
    }
    return 0;
}
