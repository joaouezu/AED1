#include <stdio.h>

int main() {
    int N, i;

    do {
        scanf("%d", &N);
    } while (N < 2 || N > 999);

    int X[N];
    int menor;
    int menor_pos;

    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        
        if (i == 0) {
            menor = X[i];
            menor_pos = i;
        } else {
            if (X[i] < menor) {
                menor = X[i];
                menor_pos = i;
            }
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", menor_pos);

    return 0;
}