#include <stdio.h>
#include <stdlib.h> // Para malloc e free
#include <stdbool.h>

#define TAMANHO 9

// Função para verificar se os números de 1 a 9 estão presentes em um conjunto de 9 elementos.
bool verifica_conjunto(int *conjunto) {
    bool visto[TAMANHO + 1] = {false};
    for (int i = 0; i < TAMANHO; i++) {
        int num = conjunto[i];
        if (num < 1 || num > 9 || visto[num]) {
            return false;
        }
        visto[num] = true;
    }
    return true;
}

// Verifica todas as linhas da matriz
bool verifica_linhas(int sudoku[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        // Aloca dinamicamente o array temporário para a linha
        int *linha = (int *)malloc(TAMANHO * sizeof(int));
        if (linha == NULL) return false; // Trata falha de alocação

        for (int j = 0; j < TAMANHO; j++) {
            linha[j] = sudoku[i][j];
        }
        
        bool resultado = verifica_conjunto(linha);
        free(linha); // Libera a memória alocada

        if (!resultado) {
            return false;
        }
    }
    return true;
}

// Verifica todas as colunas da matriz
bool verifica_colunas(int sudoku[TAMANHO][TAMANHO]) {
    for (int j = 0; j < TAMANHO; j++) {
        // Aloca dinamicamente o array temporário para a coluna
        int *coluna = (int *)malloc(TAMANHO * sizeof(int));
        if (coluna == NULL) return false; // Trata falha de alocação

        for (int i = 0; i < TAMANHO; i++) {
            coluna[i] = sudoku[i][j];
        }
        
        bool resultado = verifica_conjunto(coluna);
        free(coluna); // Libera a memória alocada

        if (!resultado) {
            return false;
        }
    }
    return true;
}

// Verifica todas as sub-regiões 3x3 da matriz
bool verifica_subregioes(int sudoku[TAMANHO][TAMANHO]) {
    for (int caixa_i = 0; caixa_i < TAMANHO; caixa_i += 3) {
        for (int caixa_j = 0; caixa_j < TAMANHO; caixa_j += 3) {
            // Aloca dinamicamente o array temporário para a sub-região
            int *subregiao = (int *)malloc(TAMANHO * sizeof(int));
            if (subregiao == NULL) return false; // Trata falha de alocação

            int contador = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    subregiao[contador++] = sudoku[caixa_i + i][caixa_j + j];
                }
            }
            
            bool resultado = verifica_conjunto(subregiao);
            free(subregiao); // Libera a memória alocada
            
            if (!resultado) {
                return false;
            }
        }
    }
    return true;
}

// Função principal para verificar a matriz Sudoku completa
bool eh_solucao_sudoku(int sudoku[TAMANHO][TAMANHO]) {
    return verifica_linhas(sudoku) && verifica_colunas(sudoku) && verifica_subregioes(sudoku);
}

int main() {
    int n, k;

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        // A matriz principal continua sendo estática, pois o tamanho é fixo (9x9)
        int sudoku[TAMANHO][TAMANHO];

        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        if (eh_solucao_sudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        printf("\n");
    }

    return 0;
}