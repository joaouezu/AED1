#include <stdio.h>
#include <stdlib.h>
/*Inserimos os elementos no vetor um de cada vez, ordenando-os em sua inserção
Retirado também do livro Feofillof*/
void insertionSort(int arr[], int N) {
    int i, j, chave;
    for (i = 1; i < N; i++) {
        chave = arr[i];
        j = i - 1;
        
        // Move elementos maiores que a chave para frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
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
        
        insertionSort(arr, N);
        
        for (k = 0; k < N; k++) {
            printf("%d", arr[k]);
            if (k < N - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
