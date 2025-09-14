#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int N, i;

    do {
        scanf("%d", &N);
    } while (N < 2 || N > 999);

    // Aloca o vetor X no heap
    int *X = (int *)malloc(N * sizeof(int));
    if (X == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    int menor;
    int menor_pos;

    for (i = 0; i < N; i++) {
        scanf("%d", (X + i));

        if (i == 0) {
            menor_pos = i;
        } else {
            if (*(X + i) < menor) {
                menor = *(X + i);
                menor_pos = i;
            }
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", menor_pos);

    // Libera a memória alocada
    free(X);

    return 0;
}