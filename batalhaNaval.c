#include <stdio.h>

int main() {

    // Navios do jogo

    #define linha 3
    #define coluna 5

    #define linhatabu 10
    #define colunatabu 10

    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navio[3] = {3, 3, 3}, 
    navio2[3] = {3, 3, 3}, 
    navioD[3] = {3, 3, 3},
    navioD2[3] = {3, 3, 3};

    int cone[linha][coluna], 
    cruz[linha][coluna], 
    octaedro[linha][coluna]; 

    // Tabuleiro do jogo preenchido com valor 0 através do for
    int tabuleiro[linhatabu][colunatabu];

    for (int l = 0; l < linhatabu; l++) 
    {
        for (int c = 0; c < colunatabu; c++) 
        {
            tabuleiro[l][c] = 0;
        }
    }

    // Inicializando as matrizes de habilidade

    for (int l = 0; l < linha; l++) {
        for (int c = 0; c < coluna; c++) {
            cone[l][c] = 0;
            cruz[l][c] = 0;
            octaedro[l][c] = 0;
        }
    }

    // Adicionando Navios no tabuleiro usando a estrutura for

    for (int l = 0, v = 9; l < 10; l++, v--) 
    {
        // for para o Navio na vertical
        for (int n = 0; n < 3; n++) 
        {      
            tabuleiro[n][3] = 3;
        }        

        // for para o Navio na horizontal
        for (int n2 = 0; n2 < 3; n2++)
        {
            tabuleiro[6][n2+7] = 3;
        }

        // for para o Navio na diagonal direita superior

        for (int d = 9; d >= 7; d--)
        {
             tabuleiro[9-d][d] = 3;
        }

        // for para o Navio na diagonal esquerda inferior
        
        for (int d = 9; d > 6; d--) 
        {
            tabuleiro[d][9-d] = 3;
        }
        
    }

    // criando as habilidades

    for (int l = 2; l >= 0; l--) 
    {
    // habilidade do cone        
        for (int c = 4; c >= 0; c--) 
        {
            if (l == 2) 
            {
                cone[l][c] = 1;
            }
                else if (l == 1) 
                {
                    if(c == 0 || c == 4)continue;
                    cone[l][c] = 1;
                }
                else if (l == 0)
                {
                    if(c < 2 || c > 2)continue;
                    cone[l][c] = 1;

                } 
        }
        // habilidade da cruz
        for (int c = 0; c < coluna; c++) 
        {
            if (l == 0 || l == 2) 
            {
                if (c < 2 || c > 2)continue;
                cruz[l][c] = 6;
            }
                else if (l == 1) 
                {
                    cruz[l][c] = 6;
                }
        }

        // habilidade do octaedro
        for (int c = 0; c < coluna; c++) 
        {
            if (l == 0 || l == 2) 
            {
                if(c < 2 || c > 2)continue;
                octaedro[l][c] = 7;
            }
                else 
                {
                    if(c < 1 || c > 7) continue;
                    octaedro[l][c] = 7;                    
                }
        }

    }
        // adicionando as habilidades ao tabuleiro
     for (int l = 0; l < linha; l++) 
    {

            for(int n = 0; n < coluna; n++) 
            {
                int limiteL = l;
                int limiteC = n;

                if (cone[l][n] == 1) 
                {
                    if (limiteL < linhatabu && limiteL >= 0 && limiteC >= 0 && limiteC < colunatabu) {
                        if (tabuleiro[l][n] == 0) {

                            tabuleiro[l][n] = 1;
                        }
                    }
                }

                if (cruz[l][n] == 6) 
                {
                    if (limiteL < linhatabu && limiteL >= 0 && limiteC >= 0 && limiteC < colunatabu) {
                        if (tabuleiro[l+7][n] == 0) {

                            tabuleiro[l+7][n] = 6;
                        }
                    }
                }

                if (octaedro[l][n] == 7) 
                {
                    if (limiteL < linhatabu && limiteL >= 0 && limiteC >= 0 && limiteC < colunatabu) {

                        if (tabuleiro[l+5][n+5] == 0) {

                        tabuleiro[l+5][n+5] = 7;
                        }
                    }
                }
            }      
    }  

// Exibindo o tabuleiro

    printf("TABULEIRO DE BATALHA NAVAL: \n");

    // Exibindo as letras
    for(int contar = 0; contar < 10; contar++) 
    {
        printf(" %c", letras[contar]);
    }
    printf("\n");

    for(int l = 0; l < 10; l++) 
    {
    // Exibindo os números de 0 a 9
        printf("%d  ", l);

    // Exibindo a tabela 
        for(int n = 0; n < 10; n++) 
        {
         printf("%d ", tabuleiro[l][n]);
        }

        printf("\n");    
    }

    return 0;

}
