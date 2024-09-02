#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Função para buscar um elemento na lista
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return i; // Retorna a posição do elemento
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para inverter a lista
void inverter() {
    int temp;
    for (int i = 0; i < tamanho / 2; i++) {
        temp = lista[i];
        lista[i] = lista[tamanho - 1 - i];
        lista[tamanho - 1 - i] = temp;
    }
}

// Função para encontrar o valor máximo na lista
int maximo() {
    int max = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > max) {
            max = lista[i];
        }
    }
    return max;
}

// Função para encontrar o valor mínimo na lista
int minimo() {
    int min = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] < min) {
            min = lista[i];
        }
    }
    return min;
}

// Função para ordenar a lista em ordem crescente (usando Bubble Sort)
void ordenar() {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    inserir(1000);
    inserir(200);
    inserir(340);
    imprimir();

    int elemento;
    printf("Digite o elemento que deseja buscar: ");
    scanf("%d", &elemento);

    int pos = buscar(elemento);
    if (pos != -1) {
        printf("Elemento %d encontrado na posição %d\n", elemento, pos);
    } else {
        printf("Elemento %d não encontrado\n", elemento);
    }

    printf("Valor máximo: %d\n", maximo());
    printf("Valor mínimo: %d\n", minimo());

    inverter();
    printf("Lista invertida:\n");
    imprimir();

    ordenar();
    printf("Lista ordenada:\n");
    imprimir();

    remover(1);
    imprimir();

    return 0;
}
