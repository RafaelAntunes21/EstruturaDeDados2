#include <stdio.h>

int main() {
    
    int n, i, temp; // variaveis auxiliares

    // Solicita ao usuário o tamanho do vetor.
    printf("Digite o tamanho do vetor (máximo 50): ");
    scanf("%d", &n);

    // Declara um vetor com tamanho máximo de 50.
    int vetor[50];

    // Solicita ao usuário que insira os elementos do vetor.
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Loop para inverter os elementos do vetor.
    for (i = 0; i < n / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = temp;
    }

    // Impressão do vetor invertido.
    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
