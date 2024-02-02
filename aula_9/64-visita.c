//gcc 64-visita.c  -o prog.exe

#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *pai, *esq, *dir;
} Item;

typedef struct tArvore {
    Item *raiz;
    int quantidade;
} Arvore;

// Recebe uma chave x.
// Aloca memoria para um novo item, inicializa campos:
// chave x e ponteiros todos NULL.
// Devolve o ponteiro alocado.
Item *criaItem (int x) {
    Item *novo = malloc (sizeof(Item));
    novo -> chave = x;
    novo -> pai = novo -> esq = novo -> dir = NULL;
    return novo;
}

// Aloca memoria para uma arvore.
// Inicializa arvore vazia: raiz vazia e qtde zero.
// Devolve o ponteiro alocado.
Arvore *criaArvoreVazia () {
    Arvore *arvore = malloc (sizeof (Arvore));
    arvore -> raiz = NULL;
    arvore -> quantidade  = 0;
    return arvore;
}

void liberaPosOrdem (Item *r) {
    if (r != NULL) {
        liberaPosOrdem (r -> esq);
        liberaPosOrdem (r -> dir);
        printf("%d ", r -> chave);
        free(r);
    }
}

void liberaPreOrdem (Item *r) {
    if (r != NULL) {
        printf("%d ", r -> chave);
        liberaPreOrdem (r -> esq);
        liberaPreOrdem (r -> dir);
        free(r);
    }
}
void liberaInOrdem (Item *r) {
    if (r != NULL) {
        liberaInOrdem (r -> esq);
        printf("%d ", r -> chave);
        liberaInOrdem (r -> dir);
        free(r);
    }
}

// Recebe um ponteiro para uma arvore.
// Libera memoria: libera itens da arvore e finalmente a estrutura da arvore.
void liberaArvore1 (Arvore *arvore) {
    liberaPosOrdem(arvore -> raiz);
    free(arvore);
}

void liberaArvore2 (Arvore *arvore) {
    liberaPreOrdem(arvore -> raiz);
    free(arvore);
}

void liberaArvore3 (Arvore *arvore) {
    liberaInOrdem(arvore -> raiz);
    free(arvore);
}

// Recebe um ponteiro para uma arvore.
// Devolve 1 se arvore vazia, 0 caso contrario.
int vazia (Arvore *arv) {
    return arv -> raiz == NULL;
}

void imprimeInOrdem (Item *r) {
    if (r != NULL) {
        imprimeInOrdem(r -> esq);
        printf("%d ", r -> chave);
        imprimeInOrdem(r -> dir);
    }
}

void imprimePreOrdem (Item *r) {
    if (r != NULL) {
        printf("%d ", r -> chave);
        imprimePreOrdem(r -> esq);
        imprimePreOrdem(r -> dir);
    }
}

void imprimePosOrdem (Item *r) {
    if (r != NULL) {
        imprimePosOrdem(r -> esq);
        imprimePosOrdem(r -> dir);
        printf("%d ", r -> chave);
    }
}
// Recebe um ponteiro para uma arvore.
// Imprime o conteudo da arvore "em ordem".
void imprimir (Arvore *arv) {
    if(!vazia (arv)) {
        imprimeInOrdem(arv -> raiz);
        printf("\n");
    }
}

Item *buscaPosicao (Arvore *arv, int x) {
    Item *atu = arv -> raiz, *ant = NULL;
    while(atu != NULL) {
        ant  = atu;
            if(x == atu -> chave ) {
                return atu;
            }
            else if(x < atu -> chave) {
                atu = atu -> esq;
            }
            else {
                atu = atu -> dir;
            }
    }
    return ant;
}


// Recebe um ponteiro para uma arvore e uma chave x.
// Insere uma nova chave na arvore.
// Ignora chaves repetidas.
void inserir (Arvore *arv, int x) {
    Item *novo = criaItem(x);
    if(vazia (arv)) {
        arv -> raiz = novo;
        arv -> quantidade = 1;
    }
    else {
        Item *atu = buscaPosicao (arv, x);
        if (atu -> chave == x) {
            free(novo);
        }
        else {
            if(x < atu -> chave) {
                atu -> esq = novo;
            }
            else {
                atu -> dir = novo;
            }
            novo -> pai = atu;
            arv -> quantidade++;
        }
    }
}

int main () {
    int n, i, x;
    scanf ("%d", &n);
    Arvore *arv = criaArvoreVazia ();
    for (i = 0; i < n; i++) {
        scanf ("%d", &x);
        inserir (arv, x);
    }
    if (!vazia (arv)) {
        printf ("Pre-ordem: ");
        imprimePreOrdem (arv->raiz);
        printf ("\nIn-ordem: ");
        imprimeInOrdem (arv->raiz);
        printf ("\nPos-ordem: ");
        imprimePosOrdem (arv->raiz);
        printf ("\n");
    }
    // liberaArvore1 (arv);
    return 0;
}