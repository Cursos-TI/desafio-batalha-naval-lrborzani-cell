#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Valores utilizados no tabuleiro
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {

    // =====================================================
    // DECLARAÇÃO DO TABULEIRO
    // =====================================================

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {

        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // =====================================================
    // POSICIONAMENTO DOS NAVIOS
    // =====================================================

    // Navio horizontal
    for (int i = 0; i < 3; i++) {

        tabuleiro[2][3 + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < 3; i++) {

        tabuleiro[5 + i][7] = NAVIO;
    }

    // Navio diagonal principal
    for (int i = 0; i < 3; i++) {

        tabuleiro[6 + i][1 + i] = NAVIO;
    }

    // Navio diagonal secundária
    for (int i = 0; i < 3; i++) {

        tabuleiro[1 + i][8 - i] = NAVIO;
    }

    // =====================================================
    // MATRIZES DAS HABILIDADES
    // =====================================================

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa todas as matrizes com 0
    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            cone[linha][coluna] = 0;
            cruz[linha][coluna] = 0;
            octaedro[linha][coluna] = 0;
        }
    }

    // =====================================================
    // CONSTRUÇÃO DA HABILIDADE CONE
    // =====================================================

    /*
        Formato esperado:

            0 0 1 0 0
            0 1 1 1 0
            1 1 1 1 1
            0 0 0 0 0
            0 0 0 0 0
    */

    for (int linha = 0; linha < 3; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            // Define expansão do cone
            if (coluna >= 2 - linha && coluna <= 2 + linha) {

                cone[linha][coluna] = 1;
            }
        }
    }

    // =====================================================
    // CONSTRUÇÃO DA HABILIDADE CRUZ
    // =====================================================

    /*
            0 0 1 0 0
            0 0 1 0 0
            1 1 1 1 1
            0 0 1 0 0
            0 0 1 0 0
    */

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha == 2 || coluna == 2) {

                cruz[linha][coluna] = 1;
            }
        }
    }

    // =====================================================
    // CONSTRUÇÃO DA HABILIDADE OCTAEDRO
    // =====================================================

    /*
            0 0 1 0 0
            0 1 1 1 0
            1 1 1 1 1
            0 1 1 1 0
            0 0 1 0 0
    */

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            // Distância Manhattan
            int distancia =
                (linha > 2 ? linha - 2 : 2 - linha) +
                (coluna > 2 ? coluna - 2 : 2 - coluna);

            if (distancia <= 2) {

                octaedro[linha][coluna] = 1;
            }
        }
    }

    // =====================================================
    // PONTOS DE ORIGEM DAS HABILIDADES
    // =====================================================

    int origemConeLinha = 1;
    int origemConeColuna = 1;

    int origemCruzLinha = 5;
    int origemCruzColuna = 4;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 8;

    // =====================================================
    // SOBREPOSIÇÃO DO CONE NO TABULEIRO
    // =====================================================

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            // Calcula posição real no tabuleiro
            int tabLinha =
                origemConeLinha + linha - 2;

            int tabColuna =
                origemConeColuna + coluna - 2;

            // Verifica limites do tabuleiro
            if (tabLinha >= 0 &&
                tabLinha < TAM_TABULEIRO &&
                tabColuna >= 0 &&
                tabColuna < TAM_TABULEIRO) {

                // Aplica habilidade
                if (cone[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == AGUA) {

                    tabuleiro[tabLinha][tabColuna] = HABILIDADE;
                }
            }
        }
    }

    // =====================================================
    // SOBREPOSIÇÃO DA CRUZ NO TABULEIRO
    // =====================================================

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            int tabLinha =
                origemCruzLinha + linha - 2;

            int tabColuna =
                origemCruzColuna + coluna - 2;

            if (tabLinha >= 0 &&
                tabLinha < TAM_TABULEIRO &&
                tabColuna >= 0 &&
                tabColuna < TAM_TABULEIRO) {

                if (cruz[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == AGUA) {

                    tabuleiro[tabLinha][tabColuna] = HABILIDADE;
                }
            }
        }
    }

    // =====================================================
    // SOBREPOSIÇÃO DO OCTAEDRO NO TABULEIRO
    // =====================================================

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            int tabLinha =
                origemOctaedroLinha + linha - 2;

            int tabColuna =
                origemOctaedroColuna + coluna - 2;

            if (tabLinha >= 0 &&
                tabLinha < TAM_TABULEIRO &&
                tabColuna >= 0 &&
                tabColuna < TAM_TABULEIRO) {

                if (octaedro[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == AGUA) {

                    tabuleiro[tabLinha][tabColuna] = HABILIDADE;
                }
            }
        }
    }

    // =====================================================
    // EXIBIÇÃO DO TABULEIRO
    // =====================================================

    printf("\n========== BATALHA NAVAL ==========\n\n");

    // Cabeçalho das colunas
    printf("   ");

    for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

        printf("%d ", coluna);
    }

    printf("\n");

    // Impressão do tabuleiro
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {

        printf("%d  ", linha);

        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            // Água
            if (tabuleiro[linha][coluna] == AGUA) {

                printf("0 ");
            }

            // Navio
            else if (tabuleiro[linha][coluna] == NAVIO) {

                printf("3 ");
            }

            // Área de habilidade
            else if (tabuleiro[linha][coluna] == HABILIDADE) {

                printf("5 ");
            }
        }

        printf("\n");
    }

    return 0;
}