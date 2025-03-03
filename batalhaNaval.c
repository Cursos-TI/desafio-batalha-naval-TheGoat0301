#include <stdio.h>

// Definição das dimensões do tabuleiro
#define TAMANHO_TABULEIRO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade especial em forma de cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Resetar o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definir áreas afetadas em forma de cone
    if (x >= 2 && y >= 2 && x < TAMANHO_TABULEIRO && y < TAMANHO_TABULEIRO) {
        tabuleiro[x][y] = 1;
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x - 1][y - 1] = 1;
        tabuleiro[x - 1][y + 1] = 1;
        tabuleiro[x - 2][y] = 1;
    }
}

// Função para aplicar habilidade especial em forma de octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Resetar o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definir áreas afetadas em forma de octaedro
    if (x >= 1 && y >= 1 && x < TAMANHO_TABULEIRO - 1 && y < TAMANHO_TABULEIRO - 1) {
        tabuleiro[x][y] = 1;
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y + 1] = 1;
    }
}

// Função para aplicar habilidade especial em forma de cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Resetar o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definir áreas afetadas em forma de cruz
    if (x >= 2 && y >= 2 && x < TAMANHO_TABULEIRO - 2 && y < TAMANHO_TABULEIRO - 2) {
        tabuleiro[x][y] = 1;
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x - 2][y] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x + 2][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y - 2] = 1;
        tabuleiro[x][y + 1] = 1;
        tabuleiro[x][y + 2] = 1;
    }
}

int main() {
    // Criação do tabuleiro de jogo
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Aplicação das habilidades especiais
    aplicarHabilidadeCone(tabuleiro, 3, 3);
    printf("Habilidade em Cone:\n");
    exibirTabuleiro(tabuleiro);

    aplicarHabilidadeOctaedro(tabuleiro, 5, 5);
    printf("\nHabilidade em Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    aplicarHabilidadeCruz(tabuleiro, 6, 6);
    printf("\nHabilidade em Cruz:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
