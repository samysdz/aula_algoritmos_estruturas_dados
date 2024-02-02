//gcc 62-heapSort.c  -o prog.exe

#include <stdio.h>
#include <stdlib.h>

typedef struct tHeap {
    int *v;
    int t;
    int q;
} Heap;

Heap * criaHeapVazio (int tam) {
    Heap *h = malloc (sizeof (Heap));
    h -> t = tam;
    h -> v = malloc (sizeof (int) * tam);
    h -> q = 0;
    return h;
}

void liberaHeap (Heap *h) {
    free (h -> v);
    free (h);
}

int pai (int i) {
    return (i-1)/2;
}

int filhoEsq (int i) {
    return 2 * i + 1;
}

int filhoDir (int i) {
    return 2 * i + 2;
}

int ultimoPai (Heap *h) {
    int n = h -> q;
    return n/2 - 1;
}

void troca (int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void peneirar (Heap *h, int pai) {
    int e= filhoEsq (pai), d = filhoDir (pai);
    int n = h -> q, maiorFilho = e;
    if (e < n) {
        if (d < n && h -> v[d] > h -> v[e]) {
            maiorFilho = d;
        }
        if (h -> v[maiorFilho] > h -> v[pai]) {
            troca (h -> v, maiorFilho, pai);
            peneirar (h, maiorFilho);
        }
    }
}

void constroiHeap (Heap *h) {
    int i;
    for (i = ultimoPai(h); i >= 0; i--) {
        peneirar (h, i);
    }
}

void imprime (int *v, int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d ", v[i]);
    }
    if (n > 0) {
        printf ("%d\n", v[n-1]);
    }
}

void heapSort (Heap *h) {
    int i, n = h -> q;
    constroiHeap(h);
    imprime (h -> v, n);
    for (i = h -> q - 1; i >= 1; i--) {
        troca (h -> v, 0, i);
        h -> q--;
        peneirar(h, 0);
        imprime(h -> v, n);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    while (n != 0) {
        Heap *h = criaHeapVazio  (n);
        for (i = 0;  i < n; i++) {
            scanf ("%d", &h -> v[i]);
        }
        h -> q = n;
        constroiHeap(h);
        heapSort(h);
        liberaHeap(h);
        return 0;
    }
}