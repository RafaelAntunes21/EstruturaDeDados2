#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista duplamente ligada
typedef struct Node {
    int data;           // Armazena o valor do nó
    struct Node* next;  // Ponteiro para o próximo nó
    struct Node* prev;  // Ponteiro para o nó anterior
} Node;

Node* head = NULL; // Ponteiro para o primeiro nó da lista (inicializado como nulo)

// Função para inserir um novo nó no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    newNode->data = value; // Atribui o valor ao novo nó
    newNode->next = head;  // O próximo nó do novo nó é o atual primeiro nó da lista
    newNode->prev = NULL;  // O nó anterior do novo nó é NULL, pois ele será o primeiro nó
    if (head != NULL)      // Se a lista não está vazia
        head->prev = newNode; // Atualiza o nó anterior do antigo primeiro nó
    head = newNode; // Atualiza o ponteiro head para o novo nó
}

// Função para deletar um nó específico da lista
void deleteNode(Node* node) {
    if (node == head)        // Se o nó a ser deletado é o primeiro nó
        head = node->next;   // Atualiza o head para o próximo nó
    if (node->next != NULL)  // Se o nó a ser deletado não é o último
        node->next->prev = node->prev; // Atualiza o nó anterior do próximo nó
    if (node->prev != NULL)  // Se o nó a ser deletado não é o primeiro
        node->prev->next = node->next; // Atualiza o próximo nó do nó anterior
    free(node); // Libera a memória alocada para o nó deletado
}

// Função para imprimir todos os elementos da lista
void printList() {
    if (head == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n"); 
        return; 
    }
    Node* temp = head; // Começa do primeiro nó
    printf("Elementos da lista: ");
    while (temp != NULL) { // Percorre a lista até o final
        printf("%d ", temp->data); // Imprime o valor do nó atual
        temp = temp->next; // Move para o próximo nó
    }
    printf("\n"); // Imprime uma nova linha após listar todos os elementos
}

// Função para buscar um valor na lista
void buscarValor(int valor) {
    Node* temp = head; // Começa do primeiro nó
    while (temp != NULL) { // Percorre a lista até o final
        if (temp->data == valor) { // Se o valor for encontrado
            printf("Valor %d encontrado.\n", valor); // Informa que o valor foi encontrado
            printf("Detalhes do nó:\n");

            // Exibe o valor anterior, se existir
            if (temp->prev != NULL)
                printf("Valor anterior: %d\n", temp->prev->data);
            else
                printf("Valor anterior: NULL\n");

            // Exibe o valor atual
            printf("Valor atual: %d\n", temp->data);

            // Exibe o próximo valor, se existir
            if (temp->next != NULL)
                printf("Próximo valor: %d\n", temp->next->data);
            else
                printf("Próximo valor: NULL\n");

            return; // Sai da função após encontrar o valor
        }
        temp = temp->next; // Move para o próximo nó
    }
    printf("Valor %d não encontrado na lista.\n", valor); // Informa que o valor não foi encontrado
}

int main() {
    int valor, opcao; // Variáveis para armazenar a escolha do usuário e o valor a ser inserido ou buscado

    while (1) { // Loop infinito até o usuário escolher sair
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir valor na lista\n");
        printf("2. Imprimir lista\n");
        printf("3. Buscar valor na lista\n");
        printf("4. Sair\n\n");
        scanf("%d", &opcao); // Lê a escolha do usuário

        switch (opcao) { // Executa a operação escolhida
            case 1: // Inserir valor
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor); // Lê o valor a ser inserido
                insertFront(valor); // Chama a função para inserir o valor na frente da lista
                break;
            case 2: // Imprimir lista
                printList(); // Chama a função para imprimir a lista
                break;
            case 3: // Buscar valor na lista
                printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor); // Lê o valor a ser buscado
                buscarValor(valor); // Chama a função para buscar o valor na lista
                break;
            case 4: // Sair
                return 0; // Encerra o programa
            default: 
                printf("Opção inválida.\n");
        }
    }

    return 0; 
}
