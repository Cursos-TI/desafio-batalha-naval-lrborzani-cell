#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    // =========================================
    // DECLARAÇÃO DO TABULEIRO
    // =========================================

    // Matriz 10x10 representando o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com água (0)
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {

        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // =========================================
    // COORDENADAS INICIAIS DOS NAVIOS
    // =========================================

    // Navio horizontal
    int linhaH = 1;
    int colunaH = 2;

    // Navio vertical
    int linhaV = 4;
    int colunaV = 7;

    // Navio diagonal principal (\)
    int linhaDP = 6;
    int colunaDP = 1;

    // Navio diagonal secundária (/)
    int linhaDS = 1;
    int colunaDS = 9;

    // Variável de controle
    int valido = 1;

    // =========================================
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // =========================================

    // Verifica se o navio cabe horizontalmente
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {

        printf("Erro: navio horizontal fora do tabuleiro.\n");
        valido = 0;
    }

    // =========================================
    // VALIDAÇÃO DO NAVIO VERTICAL
    // =========================================

    // Verifica se o navio cabe verticalmente
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {

        printf("Erro: navio vertical fora do tabuleiro.\n");
        valido = 0;
    }

    // =========================================
    // VALIDAÇÃO DA DIAGONAL PRINCIPAL (\)
    // =========================================

    // Linha e coluna aumentam juntas
    if ((linhaDP + TAM_NAVIO > TAM_TABULEIRO) ||
        (colunaDP + TAM_NAVIO > TAM_TABULEIRO)) {

        printf("Erro: navio diagonal principal fora do tabuleiro.\n");
        valido = 0;
    }

    // =========================================
    // VALIDAÇÃO DA DIAGONAL SECUNDÁRIA (/)
    // =========================================

    // Linha aumenta e coluna diminui
    if ((linhaDS + TAM_NAVIO > TAM_TABULEIRO) ||
        (colunaDS - (TAM_NAVIO - 1) < 0)) {

        printf("Erro: navio diagonal secundária fora do tabuleiro.\n");
        valido = 0;
    }

    // =========================================
    // POSICIONAMENTO DO NAVIO HORIZONTAL
    // =========================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaH][colunaH + i] != AGUA) {

                printf("Erro: sobreposição no navio horizontal.\n");
                valido = 0;
                break;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (int i = 0; i < TAM_NAVIO; i++) {

                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // =========================================
    // POSICIONAMENTO DO NAVIO VERTICAL
    // =========================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaV + i][colunaV] != AGUA) {

                printf("Erro: sobreposição no navio vertical.\n");
                valido = 0;
                break;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (int i = 0; i < TAM_NAVIO; i++) {

                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // =========================================
    // POSICIONAMENTO DA DIAGONAL PRINCIPAL (\)
    // =========================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaDP + i][colunaDP + i] != AGUA) {

                printf("Erro: sobreposição na diagonal principal.\n");
                valido = 0;
                break;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (int i = 0; i < TAM_NAVIO; i++) {

                tabuleiro[linhaDP + i][colunaDP + i] = NAVIO;
            }
        }
    }

    // =========================================
    // POSICIONAMENTO DA DIAGONAL SECUNDÁRIA (/)
    // =========================================

    if (valido) {

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {

            if (tabuleiro[linhaDS + i][colunaDS - i] != AGUA) {

                printf("Erro: sobreposição na diagonal secundária.\n");
                valido = 0;
                break;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (int i = 0; i < TAM_NAVIO; i++) {

                tabuleiro[linhaDS + i][colunaDS - i] = NAVIO;
            }
        }
    }

    // =========================================
    // EXIBIÇÃO DO TABULEIRO
    // =========================================

    if (valido) {

        printf("\n========== TABULEIRO BATALHA NAVAL ==========\n\n");

        // Exibe números das colunas
        printf("   ");

        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            printf("%d ", coluna);
        }

        printf("\n");

        // Exibe o tabuleiro
        for (int linha = 0; linha < TAM_TABULEIRO; linha++) {

            // Número da linha
            printf("%d  ", linha);

            for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

                printf("%d ", tabuleiro[linha][coluna]);
            }

            printf("\n");
        }
    }

    return 0;
}