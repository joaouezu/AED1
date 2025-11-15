#include <stdio.h>
#include <stdlib.h>

// Usei a funcao qsort do C, que ordena um vetor conforme uma funcao dada de comparacao
int comparaDecrescente (const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    return val_b - val_a; 
}
int comparaArrays(int arr[], int arr_compare[], int tamanho) {
    int i, contador = 0;
    for(i = 0; i < tamanho; i++) {
        if(arr[i] == arr_compare[i])
            contador++;
    }
    return contador;
}

int main () {
    int i, j, N, M;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &M);
        int arr[M], arr_compare[M];
        for (j = 0; j < M; j++) {
            scanf("%d", &arr[j]);
            arr_compare[j] = arr[j];
        }
        qsort (arr, M, sizeof(int), comparaDecrescente);
        int retorno = comparaArrays(arr, arr_compare, M);
        printf("%d\n", retorno);
    }
}
