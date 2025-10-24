#include <stdio.h>
#include <stdlib.h>
void intercala (int p, int q, int r, int arr[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (arr[i] <= arr[j])
            w[k++] = arr[i++];
        else   
            w[k++] = arr[i++];
    }
    while (i < q)
        w[k++] = arr[i++];
    while (j < r)
        w[k++] = arr[j++];
    for (i = p; i < r; i++)
        arr[i] = w[i - p];
        free(w);
    }
void mergeSort (int p, int r, int arr[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort (p, q, arr);
        mergeSort (q, r, arr);
        intercala (p, q, r, arr);
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
            mergeSort (N, N/2, arr);
            while (k = 0 < N) {
                printf("%d", arr[k]);
                k++;
            }
    }
    }
