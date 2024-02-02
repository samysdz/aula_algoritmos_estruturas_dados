//gcc 69-antecessor.c  -o prog.exe

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
        printf("libera: %d\n", r -> chave);
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

int imprimeInOrdem (Item *r) {
    if (r != NULL) {
        imprimeInOrdem(r -> esq);
        printf("%d ", r -> chave);
        imprimeInOrdem(r -> dir);
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

// Item *sucessor (Arvore *arv, int ) {
//     if ( !vazia (arv)) {
//         Ittem *atu = buscaPosicao(arv, x);
//         if (atu != NULL && atu -> chave == x) {
//             Item *ant =NULL;
//             atu = atu -> dir;
//             while(atu != NULL) {
//                 ant = atu;
//                 atu = atu -> esq;
//             }
//             return ant;
//         }
//     }
//     return NULL;
// }

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


int main () {
    int n, i, x;
    scanf ("%d", &n);
    Arvore *arv = criaArvoreVazia ();
    for (i = 0; i < n; i++) {
        scanf ("%d", &x);
        inserir (arv, x);
    }
    while (scanf ("%d", &x) != EOF) {
        Item *it = buscaPosicao (arv, x);
        if (it != NULL && it->chave == x) {
            Item *suc = antecessor (it);
            if (suc != NULL) {
                printf ("Antecessor de %d: %d\n", x, suc->chave);
            }
            else {
                printf ("Nao ha antecessor para a chave pesquisada.\n");
            }
        }
        else {
            printf ("Chave nao encontrada.\n");
        }
    }
    liberaArvore (arv);
    return 0;
}
