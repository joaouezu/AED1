#include <stdio.h>
#include <stdlib.h>

#define MAX 40000
#define MAX_EDGES 50000

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX_EDGES];
int pai[MAX];
int tamanho[MAX];

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    Aresta *arestaA = (Aresta*)a;
    Aresta *arestaB = (Aresta*)b;
    return arestaA->peso - arestaB->peso;
}

// Funções Union-Find (DSU)
void inicializar_union_find(int n) {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        tamanho[i] = 1;
    }
}

int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]); // Path compression
    }
    return pai[x];
}

int unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    
    if (raizX == raizY) return 0; // Já estão no mesmo conjunto
    
    // Union by size
    if (tamanho[raizX] < tamanho[raizY]) {
        pai[raizX] = raizY;
        tamanho[raizY] += tamanho[raizX];
    } else {
        pai[raizY] = raizX;
        tamanho[raizX] += tamanho[raizY];
    }
    
    return 1; // União realizada
}

// Algoritmo de Kruskal
long long kruskal(int n, int m) {
    // Ordena arestas por peso
    qsort(arestas, m, sizeof(Aresta), comparar);
    
    inicializar_union_find(n);
    
    long long custo_total = 0;
    int arestas_selecionadas = 0;
    
    for (int i = 0; i < m && arestas_selecionadas < n - 1; i++) {
        if (unir(arestas[i].u, arestas[i].v)) {
            custo_total += arestas[i].peso;
            arestas_selecionadas++;
        }
    }
    
    return custo_total;
}

int main() {
    int n, m;
    
    while (1) {
        scanf("%d %d", &n, &m);
        
        if (n == 0 && m == 0) break;
        
        // Lê as arestas
        for (int i = 0; i < m; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            arestas[i].u = u;
            arestas[i].v = v;
            arestas[i].peso = peso;
        }
        
        long long resultado = kruskal(n, m);
        printf("%lld\n", resultado);
    }
    
    return 0;
}
