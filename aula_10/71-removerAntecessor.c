//gcc 71-removerAntecessor.c  -o prog.exe

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
        // printf(" %d", r -> chave);
        free(r);
    }
}
// Recebe um ponteiro para uma arvore.
// Libera memoria: libera itens da arvore e finalmente a estrutura da arvore.
void liberaArvore (Arvore *arvore) {
    liberaPosOrdem(arvore -> raiz);
    free(arvore);
}

// Recebe um ponteiro para uma arvore.
// Devolve 1 se arvore vazia, 0 caso contrario.
int vazia (Arvore *arv) {
    return arv -> raiz == NULL;
}


int imprimePreOrdem (Item *r) {
    if (r != NULL) {
        printf("%d ", r -> chave);
        imprimePreOrdem(r -> esq);
        imprimePreOrdem(r -> dir);
    }
}
// Recebe um ponteiro para uma arvore.
// Imprime o conteudo da arvore "em ordem".
void imprimir (Arvore *arv) {
    if(!vazia (arv)) {
        imprimePreOrdem(arv -> raiz);
        printf("\n");
    }
}

Item *buscaPosicao (Arvore *arv, int x) {
    Item *atu = arv -> raiz, *ant = NULL;
    while(atu != NULL) {
        ant = atu;
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


int isFolha (Item *i) {
    return i != NULL && i -> esq == NULL && i -> dir == NULL;
}
int isRaiz (Item *i) {
    return i != NULL && i -> pai == NULL;
}
int isFilhoEsquerdo (Item *i) {
    return !isRaiz (i) && (i -> pai) -> esq == i;
}
int isFilhoDireito (Item *i) {
    return !isRaiz (i) && (i -> pai) -> dir == i;
}
int temApenas1Filho (Item *i) {
    return !isFolha (i) && (i -> esq == NULL || i -> dir == NULL);
}

Item *minimoRecursivo (Item *i) {
    if(i != NULL) {
        if (i -> esq) {
            minimoRecursivo(i -> esq);
        }
        else {
            return i;
        }
    }
}

Item *maximoRecursivo (Item *i) {
    if(i != NULL) {
        if (i -> dir) {
            maximoRecursivo(i -> dir);
        }
        else {
            return i;
        }
    }
}

Item *sucessor (Item *i) {
    if( i-> dir) {
        return minimoRecursivo(i -> dir);
    }
    else {
        return NULL;
    }
}

Item *antecessor (Item *i) {
    if( i-> esq) {
        return maximoRecursivo(i -> esq);
    }
    else {
        return NULL;
    }
}

void ajustaPonteiros (Arvore *arv, Item *atu, Item *neto) {
    if (isFilhoEsquerdo (atu)) {
        (atu ->  pai) -> esq = neto;
    }
    else if (isFilhoDireito (atu)) {
        (atu -> pai) -> dir = neto;
    }
    else {
        arv -> raiz = neto;
    }
    if (neto != NULL) {
        neto -> pai = atu -> pai;
    }
}

void remover (Arvore *arv, int x) {
    if (!vazia (arv)) {
        Item *atu = buscaPosicao (arv, x);
        if (atu -> chave ==x) {
            if (isFolha (atu)) {
                ajustaPonteiros (arv, atu, NULL);;
            }
            else if (temApenas1Filho (atu)) {
                Item *neto = atu -> esq;
                if(neto == NULL) {
                    neto = atu -> dir;
                }
                ajustaPonteiros (arv, atu, neto);
            }
            else {
                Item *suc = antecessor (atu);
                Item *neto = suc -> esq;
                ajustaPonteiros (arv, suc, neto);
                suc -> esq = atu -> esq;
                suc -> dir = atu -> dir;
                if (suc -> esq != NULL) {
                    (suc -> esq) -> pai = suc;
                }
                if (suc -> dir != NULL) {
                    (suc -> dir) -> pai = suc;
                }
                ajustaPonteiros (arv, atu, suc);
            }
            arv -> quantidade--;
            free (atu);
        }
    }
}




int main () {
    int n, m, i, x;
    scanf ("%d", &n);
    Arvore *arv = criaArvoreVazia ();
    for (i = 0; i < n; i++) {
        scanf ("%d", &x);
        inserir (arv, x);
    }
    scanf ("%d", &m);
    for (i = 0; i < m; i++) {
        scanf ("%d", &x);
        remover (arv, x);
    }
    imprimir (arv);
    liberaArvore(arv);
    return 0;
}
