#include <stdio.h>

int main() {
    
    int n, i, j, soma = 0; // variáveis auxiliares

    // Solicita ao usuário o tamanho da matriz.
    printf("Digite o tamanho da matriz quadrada (máximo 10) : ");
    scanf("%d", &n);

    // Declara uma matriz com tamanho máximo 10x10.
    int matriz[10][10];

    // Solicita ao usuário os elementos da matriz.
    printf("Insira os elementos da matriz %dx%d:\n", n, n);
    
    // preenchimento da matriz nxn
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            
            // Soma os elementos da diagonal principal.
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    // Imprime a matriz criada.
    printf("\nMatriz criada:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");  // Nova linha para cada linha da matriz.
    }

    // Exibe a soma da diagonal principal.
    printf("\nSoma dos elementos da diagonal principal: %d\n", soma);

    return 0;
}
