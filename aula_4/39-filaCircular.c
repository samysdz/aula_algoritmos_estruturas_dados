//gcc 39-filaCircular.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tFilaCircular {
    int *itens;       // ponteiro (vetor) de inteiros
    int inicio, fim;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} FilaCircular;
// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
FilaCircular * criaFilaCircularVazia (int tamanho) {
    FilaCircular *fila = malloc (sizeof (FilaCircular));
    fila -> tamanho = tamanho;
    fila -> itens = malloc (sizeof(int) * tamanho);
    fila -> inicio = fila -> fim = 0;
    return fila;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaFilaCircular (FilaCircular *fila) {
    free (fila -> itens);
    free (fila);
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (FilaCircular *fila) {
    return (fila -> fim + 1) % fila -> tamanho == fila -> inicio;
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (FilaCircular *fila) {
    return fila -> inicio == fila -> fim;
}

void enfileirar (FilaCircular *fila, int x) {
    if (!cheia (fila)) {
        fila -> itens[fila -> fim] = x;
        fila -> fim = (fila -> fim + 1) % fila -> tamanho;
    }
}
int desenfileirar (FilaCircular *fila) {
    if (!vazia (fila)) {
        int x = fila -> itens[fila -> inicio];
        fila -> inicio = (fila -> inicio + 1) % fila -> tamanho;
        return x;
    }
    return -1;
}

void imprimir (FilaCircular *fila) {
    if (!vazia (fila)) {
        int i;
        printf ("[");
        for (i = fila -> inicio; i != fila -> fim; i = (i+1) % fila -> tamanho) {
            printf ("%d ", fila -> itens[i]);
        }   
        printf ("]\n");
    }
    else {
        printf ("[fila vazia]\n");
    }
}

int main () {
    char op;
    int n, x;
    scanf ("%d", &n); //quantidade e operacoes na lista
    FilaCircular *fila = criaFilaCircularVazia(n);
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
    liberaFilaCircular (fila);
    return 0;
}