#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 501
#define INF INT_MAX

int grafo[MAX][MAX];
int n, e;

// Aplica a regra especial: se há arestas bidirecionais, zera ambas
void aplicar_regra_especial() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (grafo[i][j] != INF && grafo[j][i] != INF) {
                grafo[i][j] = 0;
                grafo[j][i] = 0;
            }
        }
    }
}

// Dijkstra para um par origem-destino
int dijkstra(int origem, int destino) {
    int dist[MAX];
    int visitado[MAX];
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    
    dist[origem] = 0;
    
    for (int count = 0; count < n; count++) {
        // Encontra vértice com menor distância não visitado
        int u = -1;
        int min_dist = INF;
        
        for (int i = 1; i <= n; i++) {
            if (!visitado[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        
        if (u == -1 || u == destino) break;
        if (min_dist == INF) break;
        
        visitado[u] = 1;
        
        // Atualiza distâncias dos vizinhos
        for (int v = 1; v <= n; v++) {
            if (grafo[u][v] != INF && !visitado[v]) {
                int nova_dist = dist[u] + grafo[u][v];
                if (nova_dist < dist[v]) {
                    dist[v] = nova_dist;
                }
            }
        }
    }
    
    return dist[destino];
}

int main() {
    while (1) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0) break;
        
        // Inicializa grafo
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grafo[i][j] = INF;
            }
        }
        
        // Lê as arestas
        for (int i = 0; i < e; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            
            if (grafo[x][y] > h) {
                grafo[x][y] = h;
            }
        }
        
        // Aplica regra especial
        aplicar_regra_especial();
        
        // Processa consultas
        int k;
        scanf("%d", &k);
        
        for (int i = 0; i < k; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);
            
            int resultado = dijkstra(origem, destino);
            
            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
