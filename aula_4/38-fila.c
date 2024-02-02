//gcc 38-fila.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tFFila {
    int *itens;       // ponteiro (vetor) de inteiros
    int inicio, fim;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} Fila;
// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Fila * criaFilaVazia (int tamanho) {
    Fila *fila = malloc (sizeof (fila));
    fila -> tamanho = tamanho;
    fila -> itens = malloc (sizeof(int) * tamanho);
    fila -> inicio = fila -> fim = -1;
    return fila;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaFila (Fila *fila) {
    free (fila -> itens);
    free (fila);
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (Fila *fila) {
    return fila -> fim == fila -> tamanho -1;
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (Fila *fila) {
    return fila -> inicio == -1;;
}

void enfileirar (Fila *fila, int x) {
    if (!cheia (fila)) {
        if (vazia (fila)) {
            fila -> inicio++;
        }
        fila -> fim++;
        fila -> itens[fila->fim] = x;
    }
}
int desenfileirar (Fila *fila) {
    if (!vazia (fila)) {
        int x = fila -> itens[fila -> inicio];
        fila -> inicio++;
        if (fila -> inicio > fila -> fim) {
            fila -> inicio = fila -> fim = -1;
        }
        return x;
    }
    return -1;
}

void imprimir (Fila *fila) {
    if (!vazia (fila)) {
        int i;
        printf ("[");
        for (i = fila -> inicio; i < fila -> fim; i++) {
            printf ("%d ", fila -> itens[i]);
        }   
        printf ("%d\n", fila -> itens[fila -> fim]);
    }
    else {
        printf ("[fila vazia]\n");
    }
}

int main () {
    char op;
    int n, x;
    scanf ("%d", &n); //quantidade e operacoes na lista
    Fila *fila = criaFilaVazia(n);
    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E' : scanf ("%d", &x);
                       enfileirar (fila, x);
                       break;
            case 'D' : x = desenfileirar (fila);
                       if (x >= 0) {
                           printf ("%d\n", x);
                       }
                       break;
            case 'P' : imprimir (fila);
                       break;
        }
        // printf ("[%c %d]\n", op, x);
    }
    liberaFila (fila);
    return 0;
}