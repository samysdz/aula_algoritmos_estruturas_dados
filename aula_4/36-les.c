//gcc 36-les.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tLista {
    int *itens;       // ponteiro (vetor) de inteiros
    int quantidade;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} Lista;
// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Lista * criaListaVazia (int tamanho) {
    Lista *lista = malloc (sizeof (Lista));
    lista -> tamanho = tamanho;
    lista -> itens = malloc (sizeof(int) * tamanho);
    lista -> quantidade = 0;
    return lista;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaLista (Lista *lista) {
    free (lista -> itens);
    free (lista);
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (Lista *lista) {
    return lista -> quantidade == lista -> tamanho;
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (Lista *lista) {
    return lista -> quantidade == 0;
}
int buscaPosicao (Lista *lista, int x) {
    int i;
    for (i = 0; i < lista -> quantidade && x > lista -> itens [i]; i++);
    return i;
}

void imprime (Lista *lista) {
    int i;
    for (i = 0; i < lista -> quantidade; i++) {
        printf ("%d\n", lista -> itens[i]);
    }
} 
// Insere uma chave x na lista, caso ja nao exista na lista.
// (Ou seja, nao pode inserir chaves repetidas na lista.)
void inserir (Lista *lista, int x) {
    if (vazia (lista)) {
        lista -> itens[0] = x;
        lista -> quantidade = 1;
    }
    else {
        int i = buscaPosicao (lista, x);
        if (lista -> itens[i] != x) {
            int j;
            for (j = lista -> quantidade - 1; j >= i; j--) {
                lista -> itens [j+1] = lista -> itens[j];
            }
            lista -> itens [i] = x;
            lista -> quantidade ++;
        }

    }
}
// Remove uma chave x da lista, caso exista.
void remover (Lista *lista, int x) {
    if (!vazia (lista)) {
        int i = buscaPosicao (lista, x);
        if (lista -> itens[i] == x) {
            int j;
            for (j = i + 1; j <= lista -> quantidade - 1; j++) {
                lista -> itens[j-1] = lista -> itens[j];
            }
            lista -> quantidade --;
        }
    }
}

int main () {
    int q, i, x;
    scanf ("%d", &q); //quantidade e operacoes na lista
    Lista *lista = criaListaVazia(q);
    char op;
    for (i = 0; i < q; i++) {
        scanf (" %c", &op);  // ler com espaco na frente para dar certo!
        switch (op) {
            case 'I' : scanf ("%d", &x);
                       inserir (lista, x);
                       break;
            case 'E' : scanf ("%d", &x);
                       remover (lista, x);
                       break;
            case 'P' : imprime (lista);
                       break;

        }
        
        // printf ("[%c %d]\n", op, x);
    }
    imprime (lista);
    return 0;
}