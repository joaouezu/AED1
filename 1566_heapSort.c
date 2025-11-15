#include <stdio.h>
#include <stdlib.h>
/*Implementação retirada do  livro do Feofillof
Explicação do heapSort em minhas palavras: Usamos o funcionamento 
de um heap para ordenar o vetor, com push e pop no heap recursivamente*/

// Ajusta para arrays 0-based
void insereHeap(int m, int arr[]) {
    int f = m;
    while (f > 0 && arr[(f-1)/2] < arr[f]) {
        int t = arr[(f-1)/2];
        arr[(f-1)/2] = arr[f];
        arr[f] = t;
        f = (f-1)/2;
    }
}

void sacodeHeap(int m, int arr[]) {
    int t, f = 1;
    while (f <= m) {
        if (f < m && arr[f] < arr[f+1])
            f++;
        if (arr[(f-1)/2] >= arr[f])
            break;
        t = arr[(f-1)/2];
        arr[(f-1)/2] = arr[f];
        arr[f] = t;
        f = 2*f + 1;
    }
}

void heapSort(int N, int arr[]) {
    int m;
    // Constrói o heap
    for (m = 1; m < N; m++)
        insereHeap(m, arr);
    
    // Extrai elementos do heap
    for (m = N-1; m > 0; m--) {
        int t = arr[0];
        arr[0] = arr[m];
        arr[m] = t;
        sacodeHeap(m - 1, arr);
    }
}

int main() {
    int NC, i, j, k;
    
    do {
        scanf("%d", &NC);
    } while(NC < 0 || NC > 100);
    
    for (i = 0; i < NC; i++) {
        int N;
        scanf("%d", &N);
        int arr[N];
        
        for (j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
        }
        
        heapSort(N, arr);
        
        for (k = 0; k < N; k++) {
            printf("%d", arr[k]);
            if (k < N - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
