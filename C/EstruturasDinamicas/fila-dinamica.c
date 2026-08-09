#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura de um elemento da Fila Dinâmica
// Cada elemento possui um valor e um ponteiro que aponta para o próximo elemento
struct Fila {
    int valor;
    struct Fila *prox;
};
// Ponteiros do tipo Fila para início e fim da fila
struct Fila *inicio = NULL, *fim = NULL;

// Lista todos os elementos
void listar() {

    if (inicio == NULL) {
        printf("\nA lista está vazia.");
        return;
    }

    // Declara um ponteiro para percorrer a lista
    struct Fila *elemento;

    for (elemento = inicio; elemento != NULL; elemento = elemento->prox) {
        printf("\nValor: %d", elemento->valor);
    }
}

// Insere um elemento ao final da fila
void inserir() {

    int valor = 0;
    printf("\nDigite um número inteiro: ");
    scanf("%d", &valor);

    // Cria um novo elemento, aloca memória e define seu valor
    struct Fila *elemento = (struct Fila *) malloc(sizeof(struct Fila));
    elemento->valor = valor;
    elemento->prox = NULL; // Como é colocado no fim da fila, não aponta para ninguém

    // Se a fila estiver vazia, este será o primeiro e o último elemento
    if (inicio == NULL) inicio = fim = elemento;
    else {
        // O último elemento deve apontar para o novo elemento
        fim->prox = elemento;
        // O novo elemento torna-se o fim da fila
        fim = elemento;
    }

    printf("\nO elemento foi adicionado ao final da fila.");
}

void remover() {

    if (inicio == NULL) {
        printf("\nA lista está vazia, não é possível remover.");
        return;
    }

    // Cria um ponteiro que aponta para o atual início da fila, muda o início e libera a memória do antigo
    struct Fila *elemento = inicio;
    inicio = inicio->prox;
    free(elemento);

    printf("\nO primeiro elemento da fila foi removido.");
}

int main() {
    setlocale(LC_ALL, "pt-br");

    int op;
    while (op != 4) {
        printf("\n\n|-- Fila Dinâmica --|");
        printf("\n1. Listar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Sair");

        printf("\nOpção: ");
        scanf("%d", &op);

        switch(op) {
            case 1: listar(); break;
            case 2: inserir(); break;
            case 3: remover(); break;
            case 4: break;
            default: printf("\nOpção inválida");
        }
    }

    return 1;
}