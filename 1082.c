#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int grafo[MAX][MAX];
int visitado[MAX];
int componente[MAX];
int ordenados[MAX];
int n, m;

// DFS iterativa para evitar stack overflow
void DFS(int inicio) {
    int pilha[MAX];
    int topo = 0;
    
    pilha[topo++] = inicio;
    visitado[inicio] = 1;
    
    while (topo > 0) {
        int v = pilha[--topo];
        componente[v] = 1;
        
        for (int i = 0; i < n; i++) {
            if (grafo[v][i] && !visitado[i]) {
                visitado[i] = 1;
                pilha[topo++] = i;
            }
        }
    }
}

int main() {
    int T, caso = 1;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &n, &m);
        
        // Inicializa
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));
        
        // Lê arestas
        for (int i = 0; i < m; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            int ui = u - 'a';
            int vi = v - 'a';
            grafo[ui][vi] = grafo[vi][ui] = 1;
        }
        
        printf("Case #%d:\n", caso++);
        
        int total_componentes = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visitado[i]) {
                memset(componente, 0, sizeof(componente));
                
                DFS(i);
                
                // Coleta e ordena os vértices do componente
                int tam = 0;
                for (int j = 0; j < n; j++) {
                    if (componente[j]) {
                        ordenados[tam++] = j;
                    }
                }
                
                // Ordena (como são poucos, bubble sort é suficiente)
                for (int j = 0; j < tam; j++) {
                    for (int k = j + 1; k < tam; k++) {
                        if (ordenados[j] > ordenados[k]) {
                            int temp = ordenados[j];
                            ordenados[j] = ordenados[k];
                            ordenados[k] = temp;
                        }
                    }
                }
                
                // Imprime
                for (int j = 0; j < tam; j++) {
                    printf("%c,", ordenados[j] + 'a');
                }
                printf("\n");
                
                total_componentes++;
            }
        }
        
        printf("%d connected components\n\n", total_componentes);
    }
    
    return 0;
}
