#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *esq;
    struct no *dir;
} No;

typedef No* Arvore;

// Flag GLOBAL para controle de saída: crucial para evitar espaço extra.
int g_primeira_impressao;

// Função para criar um novo nó
Arvore criar_no(char valor) {
    Arvore novo = (Arvore)malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para inserir na ABB (ignora duplicatas)
Arvore inserir(Arvore raiz, char valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    // Se valor == raiz->valor, o valor é ignorado (duplicata).
    
    return raiz;
}

// Função para buscar na ABB (O(log n))
int buscar(Arvore raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    
    if (valor == raiz->valor) {
        return 1;
    } else if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

// Lógica de impressão unificada para garantir o espaço correto
void imprime_no(char c) {
    if (g_primeira_impressao == 0) {
        printf(" ");
    }
    printf("%c", c);
    g_primeira_impressao = 0;
}

// Travessias CORRIGIDAS para usar a lógica de espaço
void prefixo(Arvore raiz) {
    if (raiz != NULL) {
        imprime_no(raiz->valor);
        prefixo(raiz->esq);
        prefixo(raiz->dir);
    }
}

void infixo(Arvore raiz) {
    if (raiz != NULL) {
        infixo(raiz->esq);
        imprime_no(raiz->valor);
        infixo(raiz->dir);
    }
}

void posfixo(Arvore raiz) {
    if (raiz != NULL) {
        posfixo(raiz->esq);
        posfixo(raiz->dir);
        imprime_no(raiz->valor);
    }
}

// Liberar memória
void liberar_arvore(Arvore raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    Arvore raiz = NULL;
    // Comando[10] é suficiente para "INFIXA"
    char comando[10], valor;
    
    // Leitura contínua até EOF
    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            // Leitura CRÍTICA: " %c" consome o whitespace
            if (scanf(" %c", &valor) != 1) continue; 
            raiz = inserir(raiz, valor);
        }
        else if (strcmp(comando, "P") == 0) {
            // Leitura CRÍTICA: " %c" consome o whitespace
            if (scanf(" %c", &valor) != 1) continue;
            if (buscar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            g_primeira_impressao = 1; // Reseta a flag antes da travessia
            infixo(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            g_primeira_impressao = 1; // Reseta a flag antes da travessia
            prefixo(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            g_primeira_impressao = 1; // Reseta a flag antes da travessia
            posfixo(raiz);
            printf("\n");
        }
    }
    
    liberar_arvore(raiz);
    return 0;
}
