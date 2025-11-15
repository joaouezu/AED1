#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esq;
    struct no *dir;
    int info;
} TNo;

typedef TNo *No;

No insere_ABB(No arv, int x) {
    if (arv == NULL) {
        No novo = malloc(sizeof(TNo));
        if (novo == NULL) {
            printf("Erro de alocação!\n");
            return NULL;
        }
        novo->info = x;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }
    
    if (x < arv->info) {
        arv->esq = insere_ABB(arv->esq, x);
    } else {
        arv->dir = insere_ABB(arv->dir, x);
    }
    return arv;
}

void imprime(No arv) {
    if (arv == NULL) return;
    
    imprime(arv->esq);
    printf("%d ", arv->info);
    imprime(arv->dir);
}

void libera_arvore(No arv) {
    if (arv == NULL) return;
    libera_arvore(arv->esq);
    libera_arvore(arv->dir);
    free(arv);
}

int main() {
    No arv = NULL;
    int NC, i;
    
    do {
        scanf("%d", &NC);
    } while(NC < 0 || NC > 100);
    
    for (i = 0; i < NC; i++) {
        int N;
        scanf("%d", &N);
        arv = insere_ABB(arv, N);
    }
    
    imprime(arv);
    printf("\n");  // Quebra de linha no final
    
    libera_arvore(arv);  // Libera toda a árvore
    
    return 0;
}
