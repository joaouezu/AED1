#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 9

// Função para verificar se os números de 1 a 9 estão presentes em um conjunto de 9 elementos.
// Usa um array booleano para rastrear a presença de cada número.
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
        int linha[TAMANHO];
        for (int j = 0; j < TAMANHO; j++) {
            linha[j] = sudoku[i][j];
        }
        if (!verifica_conjunto(linha)) {
            return false;
        }
    }
    return true;
}

// Verifica todas as colunas da matriz
bool verifica_colunas(int sudoku[TAMANHO][TAMANHO]) {
    for (int j = 0; j < TAMANHO; j++) {
        int coluna[TAMANHO];
        for (int i = 0; i < TAMANHO; i++) {
            coluna[i] = sudoku[i][j];
        }
        if (!verifica_conjunto(coluna)) {
            return false;
        }
    }
    return true;
}

// Verifica todas as sub-regiões 3x3 da matriz
bool verifica_subregioes(int sudoku[TAMANHO][TAMANHO]) {
    for (int caixa_i = 0; caixa_i < TAMANHO; caixa_i += 3) {
        for (int caixa_j = 0; caixa_j < TAMANHO; caixa_j += 3) {
            int subregiao[TAMANHO];
            int contador = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    subregiao[contador++] = sudoku[caixa_i + i][caixa_j + j];
                }
            }
            if (!verifica_conjunto(subregiao)) {
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

    // Leia o número de instâncias
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        int sudoku[TAMANHO][TAMANHO];

        // Leia a matriz para a instância atual
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Imprima o cabeçalho da instância
        printf("Instancia %d\n", k);

        // Verifique se a matriz é uma solução e imprima o resultado
        if (eh_solucao_sudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // Imprima uma linha em branco após cada instância
        printf("\n");
    }

    return 0;
}
