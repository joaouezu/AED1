#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    struct no* prox;
    int info;
}TNo;
typedef TNo *No;
No push (No lst, int x) {
    No novo = malloc(sizeof(TNo));
    novo->info = x;
    novo->prox = lst->prox;
    lst->prox = novo;
    return lst;
}
int main () {
    int T, i, j;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        int bolinhas, linhas;
        scanf("%d %d", &bolinhas, &linhas);
        No lista[bolinhas];
        for (j = 0; j < bolinhas; j++) {
            No lst = malloc(sizeof(TNo));
            lst->prox = NULL;
            int indo, levando;
            scanf("%d %d", &indo &levando);
            if(levando == j)
            lst = push(lst, 1);
        }
    }
}
