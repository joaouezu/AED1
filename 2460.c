#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    struct no *prox;
    int info;
} TNo;
typedef TNo *No;
No Inserir (No head, int valor, No *tail) {
    No novo = malloc(sizeof(TNo));
    novo->info = valor;
    if (head->prox == NULL) {
        head->prox = novo;
        *tail = novo;
    }else {
        (*tail)->prox = novo;
        *tail = novo;
    }
    return head;
}
No BuscaERemove (No head, int arr[], int tamanho) {
    if (head->prox == NULL)
        return head;
    int i;
    for (i = 0; i < tamanho; i++) {
        No aux;
        for (aux = head; aux->prox != NULL; aux = aux->prox) {
            if (aux->prox->info == arr[i]) {
                No lixo = aux->prox;
                aux->prox = lixo->prox;
                free(lixo);
                break;
            }
        }
    }
    return head;
}
void ImprimeLista (No head) {
    No aux = head->prox;
    int primeiro = 1;

    while (aux != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", aux->info);
        primeiro = 0;
        aux = aux->prox;
    }
    printf("\n"); 
}
void Liberar (No head) {
    No atual = head;
    No proximo = NULL;
    
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main () {
    No head = malloc(sizeof(TNo));
    head->prox = NULL;
    No tail = NULL;
    int N, M, i, valor;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &valor);
        head = Inserir(head, valor, &tail);
    }
    scanf("%d", &M);
    int arr[M];
    for (i = 0; i < M; i++) 
        scanf("%d", &arr[i]);
    head = BuscaERemove(head, arr, M);
    ImprimeLista(head);
    Liberar(head);
    
    return 0;

}
