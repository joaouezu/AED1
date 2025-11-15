#include <stdio.h>
#include <stdlib.h>
/*Como funciona insertionSort explicado em inhas palavras: basicamente teremos o vetor principal dividido
em dois, o da esquerda com apenas o primeiro indice do vetor original e o da direita com o restante, a cada
iteração, os valores da direita sao comparados com os da esquerda, movendo cada valor a saus respectivos espacos*/
/*Esse algoritmo funciona com a repartição recursiva do vetor em vetores menores, reordenando esses vetores e recompondo-os*/
insertionSort (int arr[], int N) {
    int i, key, j;
    for (i = 1; i < N; i++) { //loop externo passando pelo array a partir do 2o campo, o 1o campo ja esta ordenado
        key = arr[i];
        j = i - 1; //ultimo indice do vetor ordenado
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main () {
    int NC, i, j, k;
    do{
        scanf("%d", &NC);
    } while(NC < 0 || NC > 100);
    for (i = 0; i < NC; i++) {
        int N;
        scanf("%d", &N);
        int arr[N];
        for (j = 0; j < N; j++) {
            scanf("%d", &arr[i]);
        }
            insertionSort (arr, N);
            while (k = 0 < N) {
                printf("%d", arr[k]);
                k++;
            }
    }
    }
    //complexidade: O(1) se já ordenado, O(N)se estiver em parte ordenado, O(n²) no pior caso, o vetor se passara n x n vezes
