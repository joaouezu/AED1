#include <stdio.h>
#include <stdlib.h>
void insereHeap (int m, int arr[]) {
    int f = m + 1;
    while (f > 1 && arr[f/2] < arr[f]) {
        int t = arr[f/2];arr[f/2] = arr[f];arr[f] = t;
        f = f/2;
    }
}
void sacodeHeap (int m, int arr[]) {
    int t, f = 2;
    while (f <= m) {
        if (f < m && arr[f] < arr[f+1])
            f++;
        if (arr[f/2] >= arr[f])
            break;
        t = arr[f/2]; arr[f/2] = arr[f]; arr[f] = t;
        f *= 2;
    }
}
void heapSort (int N, int arr[]) {
    int m;
    for (m = 1; m < N; m++)
        insereHeap(m, arr);
    for (m = N; m > 1; m--) {
        int t = arr[1]; arr[1] = arr[m]; arr[m] = t;
        sacodeHeap(m - 1, arr);
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
            heapSort (N, arr);
            while (k = 0 < N) {
                printf("%d", arr[k]);
                k++;
            }
    }
    }
