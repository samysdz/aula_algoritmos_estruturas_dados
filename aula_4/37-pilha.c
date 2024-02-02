//gcc 37-pilha.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>


typedef struct tLista {
    int *itens;       // ponteiro (vetor) de inteiros
    int topo;   // qtde de elementos inseridos na lista
    int tamanho;      // tamanho maximo alocado 
} Pilha;
// Recebe o tamanho alocado para o vetor.
// Devolve um ponteiro para Lista.
Pilha * criaPilhaVazia (int tamanho) {
    Pilha *pilha = malloc (sizeof (Pilha));
    pilha -> tamanho = tamanho;
    pilha -> itens = malloc (sizeof(int) * tamanho);
    pilha -> topo = -1;
    return pilha;
}
// Libera memoria: liberar lista->itens primeiro, depois a lista.
void liberaPilha (Pilha *pilha) {
    free (pilha -> itens);
    free (pilha);
}
// Devolve 1 se lista cheia, 0 caso contrario.
int cheia (Pilha *pilha) {
    return pilha -> topo == pilha -> tamanho - 1;
}
// Devolve 1 se lista vazia, 0 caso contrario.
int vazia (Pilha *pilha) {
    return pilha -> topo == -1;
}

void empilha (Pilha *pilha, int x) {
    if (!cheia (pilha)) {
        pilha -> topo++;
        pilha -> itens[pilha -> topo] = x;
    }
}

int desempilha (Pilha *pilha) {
    if (!vazia (pilha)) {
        int x = pilha -> itens[pilha -> topo];
        pilha -> topo--;
        return x;
    }
    return -1;
}

void imprimePilhaTopo (Pilha *pilha) {
    int i;
    for (i = pilha -> topo; i >= 0; i--) {
        printf ("%d\n", pilha -> itens[i]);
    }
}

void imprimePilhaBase (Pilha *pilha) {
    int i;
    for (i = 0; i <= pilha -> topo; i++) {
        printf ("%d\n", pilha -> itens[i]);
    }
} 

int main () {
    char op;
    int n, x;
    scanf ("%d", &n); //quantidade e operacoes na lista
    Pilha *pilha = criaPilhaVazia(n);
    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'E' : scanf ("%d", &x);
                       empilha (pilha, x);
                       break;
            case 'D' : x = desempilha (pilha);
                       break;
            case 'T' : imprimePilhaTopo (pilha);
                       break;
            case 'B' : imprimePilhaBase (pilha);
                       break;
        }
        // printf ("[%c %d]\n", op, x);
    }
    liberaPilha (pilha);
    return 0;
}