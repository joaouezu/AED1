#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

typedef No* Arvore;

Arvore inserir(Arvore arv, int valor) {
    if (arv == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    
    if (valor < arv->valor) {
        arv->esq = inserir(arv->esq, valor);
    } else {
        arv->dir = inserir(arv->dir, valor);
    }
    
    return arv;
}

// Função para travessia por nível (BFS)
void percurso_por_nivel(Arvore arv) {
    if (arv == NULL) return;
    
    No *fila[1000];
    int frente = 0, tras = 0;
    
    // Enfileira a raiz
    fila[tras] = arv;
    tras++;
    
    int primeiro = 1;
    
    while (frente < tras) {
        No *atual = fila[frente];
        frente++;
        
        // Imprime com espaço apenas se não for o primeiro
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        
        // Enfileira filhos
        if (atual->esq != NULL) {
            fila[tras] = atual->esq;
            tras++;
        }
        if (atual->dir != NULL) {
            fila[tras] = atual->dir;
            tras++;
        }
    }
    printf("\n");
}
void liberar_arvore(Arvore arv) {
    if (arv == NULL) return;
    liberar_arvore(arv->esq);
    liberar_arvore(arv->dir);
    free(arv);
}

int main() {
    int C, caso = 1;
    scanf("%d", &C);
    
    while (C--) {
        int N;
        scanf("%d", &N);
        
        Arvore arv = NULL;
        
        // Insere todos os elementos
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            arv = inserir(arv, valor);
        }
        
        printf("Case %d:\n", caso++);
        percurso_por_nivel(arv);
        printf("\n");
        
        liberar_arvore(arv);
    }
    
    return 0;
}
