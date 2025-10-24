#include <stdio.h>
#include <stdlib.h>
void selectionSort (int arr[], int N) {
    int i, j, minimo;
    for (i = 0; i < N - 1; i++) {
        minimo = i;
        for (j = i + 1; j < N; j++) {
            if (arr[j] < arr[minimo])
                minimo = j;
        }
        if (minimo != i) {
            int temp = arr[minimo];
            arr[minimo] = arr[i];
            arr[i] = temp;
        }
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
            selectionSort (arr, N);
            while (k = 0 < N) {
                printf("%d", arr[k]);
                k++;
            }
    }
    }
