#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Nesse programa, iremos analisar entradas e saidas de elementos
 e compará-los a estruturas de dados(stacks, filas, filas de prioridade)*/

// TAD para filas e pilhas e filasP
typedef struct no {
    struct no* prox;
    int valor;
} TNo;

typedef TNo *No;

typedef struct fila {
    No inicio;
    No fim;
} Fila;

// Estrutura para fila de prioridade (implementação simples)
typedef struct {
    int dados[1000];
    int tamanho;
} FilaPrioridade;

// Funcoes pilha
No push(No topo, int valor) {
    No novo = malloc(sizeof(TNo));
    novo->valor = valor;
    novo->prox = topo;
    return novo;
}

No pop(No topo, int *valor_removido) {
    if (topo == NULL) return NULL;
    
    *valor_removido = topo->valor;
    No temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

int top(No topo) {
    if (topo == NULL) return -1;
    return topo->valor;
}

// Funcoes fila
Fila* inicializa_fila() {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void enqueue(Fila *f, int valor) {
    No novo = malloc(sizeof(TNo));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue(Fila *f) {
    if (f->inicio == NULL) return -1;
    
    int valor = f->inicio->valor;
    No temp = f->inicio;
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    return valor;
}

int front(Fila *f) {
    if (f->inicio == NULL) return -1;
    return f->inicio->valor;
}

// Funcoes fila de prioridade
void fp_inserir(FilaPrioridade *fp, int valor) {
    fp->dados[fp->tamanho++] = valor;
    
    // Ordena de forma decrescente (maior no início)
    for (int i = fp->tamanho - 1; i > 0; i--) {
        if (fp->dados[i] > fp->dados[i-1]) {
            int temp = fp->dados[i];
            fp->dados[i] = fp->dados[i-1];
            fp->dados[i-1] = temp;
        } else {
            break;
        }
    }
}

int fp_remover(FilaPrioridade *fp) {
    if (fp->tamanho == 0) return -1;
    
    int valor = fp->dados[0];
    
    // Remove o primeiro elemento (maior)
    for (int i = 0; i < fp->tamanho - 1; i++) {
        fp->dados[i] = fp->dados[i+1];
    }
    fp->tamanho--;
    
    return valor;
}

int fp_top(FilaPrioridade *fp) {
    if (fp->tamanho == 0) return -1;
    return fp->dados[0];
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        // Inicializa as três estruturas
        No pilha = NULL;
        Fila *fila = inicializa_fila();
        FilaPrioridade fp = { .tamanho = 0 };
        
        bool eh_pilha = true, eh_fila = true, eh_fp = true;
        
        for (int i = 0; i < n; i++) {
            int operacao, valor;
            scanf("%d %d", &operacao, &valor);
            
            if (operacao == 1) {
                // Operação de inserção
                if (eh_pilha) pilha = push(pilha, valor);
                if (eh_fila) enqueue(fila, valor);
                if (eh_fp) fp_inserir(&fp, valor);
            } else {
                // Operação de remoção
                if (eh_pilha) {
                    if (pilha == NULL || top(pilha) != valor) {
                        eh_pilha = false;
                    } else {
                        int removido;
                        pilha = pop(pilha, &removido);
                    }
                }
                
                if (eh_fila) {
                    if (fila->inicio == NULL || front(fila) != valor) {
                        eh_fila = false;
                    } else {
                        dequeue(fila);
                    }
                }
                
                if (eh_fp) {
                    if (fp.tamanho == 0 || fp_top(&fp) != valor) {
                        eh_fp = false;
                    } else {
                        fp_remover(&fp);
                    }
                }
            }
        }
        
        // Determina o resultado
        int count = eh_pilha + eh_fila + eh_fp;
        
        if (count == 0) {
            printf("impossible\n");
        } else if (count > 1) {
            printf("not sure\n");
        } else {
            if (eh_pilha) printf("stack\n");
            else if (eh_fila) printf("queue\n");
            else printf("priority queue\n");
        }
        
        // Libera memória
        while (pilha != NULL) {
            int temp;
            pilha = pop(pilha, &temp);
        }
        
        while (fila->inicio != NULL) {
            dequeue(fila);
        }
        free(fila);
    }
    
    return 0;
}
