#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    int info;
} TNo;

typedef TNo *No;

typedef struct fila {
    No ini;
    No fim;
} Fila;

Fila* insere(Fila* f, int x) {
    No novo = malloc(sizeof(TNo));
    if (!novo) return f;
    
    novo->info = x;
    novo->prox = NULL;
    
    if (f->ini == NULL) {
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return f;
}

Fila* remove_fila(Fila* f, int* x) {
    if (f->ini == NULL) return f;
    
    *x = f->ini->info;
    No lixo = f->ini;
    f->ini = f->ini->prox;
    
    if (f->ini == NULL)
        f->fim = NULL;
    
    free(lixo);
    return f;
}

void libera_fila(Fila* f) {
    No atual = f->ini;
    while (atual != NULL) {
        No temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        if (n == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }
        
        Fila *f = malloc(sizeof(Fila));
        if (!f) return 1;
        f->ini = f->fim = NULL;
        
        int discartes[50], valor_carta, j = 0;
        
        // Preenche a fila
        for(int i = 1; i <= n; i++) {
            f = insere(f, i);
        }
        
        // Processa as cartas
        while (f->ini != f->fim) {
            f = remove_fila(f, &valor_carta);
            discartes[j++] = valor_carta;
            
            f = remove_fila(f, &valor_carta);
            f = insere(f, valor_carta);
        }
        
        // Imprime resultado
        printf("Discarded cards: ");
        for (int i = 0; i < j; i++) {
            printf("%d", discartes[i]);
            if (i < j - 1)
                printf(", ");
        }
        printf("\nRemaining card: %d\n", f->ini->info);
        
        libera_fila(f);
    }
    
    return 0;
}
