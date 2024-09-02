#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    int data;            // Dado armazenado no nó
    struct Node* next;   // Ponteiro para o próximo nó na fila
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;  // Ponteiro para o primeiro nó da fila
    Node* rear;   // Ponteiro para o último nó da fila
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  // Aloca memória para a fila
    if (q == NULL) {  // Verifica se a alocação de memória falhou
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;  
    }
    q->front = q->rear = NULL;  // Inicializa os ponteiros front e rear como NULL
    return q;  
}

// Função para adicionar um elemento à fila 
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para um novo nó
    if (newNode == NULL) {  // Verifica se a alocação de memória falhou
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;  // Atribui o valor ao novo nó
    newNode->next = NULL;  // Define o próximo nó como NULL, pois este será o último na fila
    if (q->rear == NULL) {  // Se a fila estiver vazia
        q->front = q->rear = newNode;  // O novo nó será o primeiro e o último na fila
    } else {  // Se a fila não estiver vazia
        q->rear->next = newNode;  // O último nó atual aponta para o novo nó
        q->rear = newNode;  // O novo nó torna-se o último na fila
    }
}

// Função para remover um elemento da fila 
int dequeue(Queue* q) {
    if (q->front == NULL) {  // Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1;  // Retorna -1 indicando que a fila está vazia
    }
    Node* temp = q->front;  // Armazena o nó do início da fila
    int data = temp->data;  // Armazena o dado do nó que será removido
    q->front = q->front->next;  // Avança o ponteiro front para o próximo nó
    if (q->front == NULL) {  // Se a fila ficou vazia após a remoção
        q->rear = NULL;  // Rear também deve ser NULL
    }
    free(temp);  // Libera a memória do nó removido
    return data;  
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;  
}

// Função para imprimir os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {  // Verifica se a fila está vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;  // Começa a imprimir a partir do primeiro nó
    printf("Elementos da fila: ");
    while (temp != NULL) {  // Percorre a fila até o último nó
        printf("%d ", temp->data);  // Imprime o dado do nó atual
        temp = temp->next;  // Avança para o próximo nó
    }
    printf("\n");  // Imprime uma nova linha após listar todos os elementos
}

// Função para contar o número de elementos na fila
int countElements(Queue* q) {
    int count = 0;  // Inicializa o contador
    Node* temp = q->front;  // Começa a contar a partir do primeiro nó
    while (temp != NULL) {  // Percorre a fila até o último nó
        count++;  // Incrementa o contador para cada nó
        temp = temp->next;  // Avança para o próximo nó
    }
    return count;  // Retorna o número total de elementos
}

// Função para limpar todos os elementos da fila e liberar a memória
void clearQueue(Queue* q) {
    Node* temp = q->front;  // Começa a limpeza a partir do primeiro nó
    while (temp != NULL) {  // Percorre toda a fila
        Node* next = temp->next;  // Armazena o próximo nó
        free(temp);  // Libera a memória do nó atual
        temp = next;  // Avança para o próximo nó
    }
    q->front = q->rear = NULL;  // Define front e rear como NULL, indicando fila vazia
}

int main() {
    Queue* q = createQueue();  // Cria uma nova fila
    enqueue(q, 1002);  // Adiciona 10 à fila
    enqueue(q, 2032);  // Adiciona 20 à fila
    enqueue(q, 380);  // Adiciona 30 à fila
    printQueue(q);  // Imprime os elementos da fila

    printf("Número de elementos na fila: %d\n", countElements(q));  // Conta e imprime o número de elementos

    printf("Desenfileirado: %d\n", dequeue(q));  // Remove e imprime o primeiro elemento da fila
    printQueue(q);  // Imprime os elementos da fila restantes

    clearQueue(q);  // Limpa a fila e libera a memória
    printQueue(q);  // Tenta imprimir a fila (deve estar vazia)

    free(q);  // Libera a memória alocada para a estrutura da fila
    return 0; 
}
