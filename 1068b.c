    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    typedef struct no {
        char valor;
        struct no *prox;
    }TNo;
    typedef TNo *No;
    int push (No lst, char info) {
        No novo = malloc(sizeof(TNo));
        novo->valor = info;
        novo->prox = lst->prox;
        lst->prox = novo;
        return 1;
    }
    int pop (No lst) {
        if (lst->prox == NULL) {
            return 0;
        }
        No lixo = lst->prox;
        lst->prox = lixo->prox;
        free (lixo);
        return 1;
    }
    void liberar(No lst) {
        No aux = lst->prox;
        while (aux != NULL) {
            No auxprox = aux->prox;
            free(aux);
            aux = auxprox;
        }
    }
    int main () {
        int i;
        char string[100];
        No lst = malloc(sizeof(TNo));
        lst->prox = NULL;
        while((fgets(string, 100, stdin)) != NULL) {
            int balanceado = 1;
        for (i = 0; string[i] != '\0'; i++) {
            if (string[i] == '(')
                balanceado = push (lst, string[i]);
            if (string[i] == ')') {
                balanceado = pop (lst);
                if(balanceado == 0)
                    break;
            }
        }
    
        if (balanceado == 1 && lst->prox == NULL)
            printf("correct\n");
        else 
            printf("incorrect\n");
        string[0] = '\0';
    }
        return 0;

        
    }
