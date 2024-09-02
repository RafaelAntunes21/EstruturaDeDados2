#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3 // Define o tamanho máximo inicial da pilha

int *pilha; // Ponteiro para a pilha, permitindo expansão dinâmica
int topo = -1; 
int capacidade = MAX_SIZE; // Capacidade inicial da pilha

// Função para adicionar um elemento ao topo da pilha
void push(int elemento) {
    if (topo < capacidade - 1) { // Verifica se há espaço na pilha
        pilha[++topo] = elemento; // Incrementa o topo e insere o elemento
    } else {
        printf("Pilha cheia! Expansão aplicada.\n");
        capacidade *= 2; // Duplica a capacidade da pilha
        pilha = realloc(pilha, capacidade * sizeof(int)); // Realoca a pilha com o novo tamanho
        if (pilha == NULL) { // Verifica se a realocação foi bem-sucedida
            printf("Erro ao expandir a pilha.\n");
            exit(1); 
        }
        pilha[++topo] = elemento; // Insere o elemento após a expansão
    }
}

// Função para remover o elemento do topo da pilha
int pop() {
    if (topo == -1) { // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1; // Retorna -1 indicando que a pilha está vazia
    } else {
        return pilha[topo--]; // Retorna o elemento do topo e decrementa o topo
    }
}

// Função para obter o elemento do topo da pilha sem removê-lo
int top() {
    if (topo == -1) { // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1; // Retorna -1 indicando que a pilha está vazia
    } else {
        return pilha[topo]; // Retorna o elemento do topo
    }
}

// Função para imprimir todos os elementos da pilha
void imprimir() {
    if (topo == -1) { // Verifica se a pilha está vazia
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) { // Percorre a pilha do topo para a base
        printf("%d ", pilha[i]); // Imprime cada elemento da pilha
    }
    printf("\n"); // Imprime uma nova linha após listar todos os elementos
}

// Função para verificar se a pilha está vazia
int isEmpty() {
    return topo == -1; // Retorna 1 se a pilha estiver vazia, caso contrário, retorna 0
}

int main() {
    pilha = (int*)malloc(capacidade * sizeof(int)); // Aloca memória para a pilha inicial
    if (pilha == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a pilha.\n");
        return 1; // Sai do programa em caso de falha
    }

    push(10); // Adiciona o elemento 10 à pilha
    push(320); // Adiciona o elemento 320 à pilha
    push(4); // Adiciona o elemento 4 à pilha
    push(52); // Adiciona o elemento 52 à pilha
    push(80); // Adiciona o elemento 80 à pilha

    imprimir(); // Imprime o conteúdo da pilha

    printf("Elemento no topo: %d\n", top()); // Imprime o elemento do topo
    printf("Elemento removido: %d\n", pop()); // Remove o elemento do topo e imprime-o
    imprimir(); // Imprime o conteúdo da pilha após a remoção

    // Verifica se a pilha está vazia
    if (isEmpty()) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    free(pilha); // Libera a memória alocada para a pilha
    return 0;
}
