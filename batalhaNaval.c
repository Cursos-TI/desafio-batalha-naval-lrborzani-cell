#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    // ================================
    // DECLARAÇÃO DO TABULEIRO
    // ================================

    // Matriz 10x10 representando o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // ================================
    // DECLARAÇÃO DOS NAVIOS
    // ================================

    // Vetores representando os navios
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaH = 2;
    int colunaH = 4;

    int linhaV = 5;
    int colunaV = 1;

    // Variável de controle para validação
    int valido = 1;

    // ================================
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // ================================

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        valido = 0;
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
    }

    // ================================
    // VALIDAÇÃO DO NAVIO VERTICAL
    // ================================

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        valido = 0;
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
    }

    // ================================
    // POSICIONAMENTO DO NAVIO HORIZONTAL
    // ================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                valido = 0;
                printf("Erro: sobreposição no navio horizontal.\n");
                break;
            }
        }

        // Posiciona o navio no tabuleiro
        if (valido) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // ================================
    // POSICIONAMENTO DO NAVIO VERTICAL
    // ================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                valido = 0;
                printf("Erro: sobreposição no navio vertical.\n");
                break;
            }
        }

        // Posiciona o navio no tabuleiro
        if (valido) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // ================================
    // EXIBIÇÃO DO TABULEIRO
    // ================================

    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {

        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}