#include <stdio.h>

int main() {
    // Navios do jogo

    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navio[3] = {3, 3, 3}, 
    navio2[3] = {3, 3, 3}, 
    navioD[3] = {3, 3, 3},
    navioD2[3] = {3, 3, 3};

    // Tabuleiro do jogo
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Adicionando Navios no tabuleiro usando a estrutura for

    for (int l = 0, v = 9; l < 10; l++, v--) 
    {
        // for para o Navio na vertical
        for (int n = 0; n < 4; n++) 
        {
            if (n < 3)continue;
            if (l > 2)break;
                       
            tabuleiro[l][n] = navio[2];
        }        

        // for para o Navio na horizontal
        for (int n2 = 0; n2 < 10; n2++)
        {
            if (l < 6)continue;            
            if (n2 < 7)continue;
            if (l > 6)break;
            tabuleiro[l][n2] = navio2[2];
        }

        // for para o Navio na diagonal direita superior

        for (int d = 9; d > 6; d--) 
        {
            if(d != v)continue;
            tabuleiro[l][d] = navioD[2];
        }

        // for para o Navio na diagonal esquerda inferior
        
        for (int d = 2; d > -1; d--) 
        {
            if(d != v)continue;
            tabuleiro[l][d] = navioD2[2];
        }
        
    }

// Exibindo o tabuleiro

    printf("TABULEIRO DE BATALHA NAVAL: \n");

    // Exibindo as letras
    for(int contar = 0; contar < 10; contar++) 
    {
        printf(" %c", letras[contar]);
    }
    for(int l = 0; l < 10; l++) 
    {

        printf("\n");

        printf("%d ", l+1);

        for(int n = 0; n < 10; n++) 
        {
            printf("%d ", tabuleiro[l][n]);
        }
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
