#include <stdio.h>
#include <string.h>

#define MAX 1030
#define QUEUE_SIZE 1050000  // 1030*1030

char grid[MAX][MAX];
char visited[MAX][MAX];  // Use char para economizar memória
int n, m;

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Struct para fila otimizada
typedef struct {
    short x, y;  // Use short para economizar memória
} Point;

Point queue[QUEUE_SIZE];

void BFS(int start_x, int start_y) {
    int front = 0, rear = 0;
    
    queue[rear].x = start_x;
    queue[rear].y = start_y;
    rear++;
    visited[start_x][start_y] = 1;
    
    while (front < rear) {
        Point current = queue[front];
        front++;
        
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            // Verificação otimizada
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] == '.') {
                    visited[nx][ny] = 1;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    // Lê a matriz rapidamente
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    
    memset(visited, 0, sizeof(visited));
    
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                components++;
                BFS(i, j);
            }
        }
    }
    
    printf("%d\n", components);
    
    return 0;
}
