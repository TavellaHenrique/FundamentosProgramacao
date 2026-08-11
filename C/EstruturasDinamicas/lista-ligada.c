#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa um elemento de uma Lista Ligada (ou "Linked List")
struct Lista {
    int valor;
    struct Lista *prox;
};
struct Lista *inicio = NULL, *fim = NULL;

// Lista o valor de cada elemento na lista
void listar() {
    if (inicio == NULL) {
        printf("\nA lista está vazia.");
        return;
    }

    for (struct Lista *elemento = inicio; elemento != NULL; elemento = elemento->prox) {
        printf("\nValor: %d", elemento->valor);
    }
}

// Insere um elemento ao final da lista
void inserir() {
    // Recebe valor do novo elemento
    int valor = 0;
    printf("\nDigite um número inteiro: ");
    scanf("%d", &valor);

    // Aloca memória para o novo elemento
    struct Lista *elemento = (struct Lista *) malloc(sizeof(struct Lista));

    // Define o valor do novo elemento
    elemento->valor = valor;

    // Como será inserido no final da lista, não tem próximo elemento
    elemento->prox = NULL;

    // Se a lista estiver vazia, este será o primeiro e último elemento
    if (inicio == NULL) inicio = fim = elemento;
    else {
        // Se a lista possui ao menos um elemento:
        // O atual último elemento aponta para o novo
        fim->prox = elemento;
        // O novo elemento se torna o fim da lista
        fim = elemento;
    }

    printf("\nO elemento foi adicionado ao fim da lista.");
}

void remover() {
}

int main() {
    setlocale(LC_ALL, "pt-br");

    int op = 0;

    while (op != 4) {
        printf("\n\n|-- Lista Ligada --|");
        printf("\n1. Listar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Sair");

        printf("\nOpção: ");
        scanf("%d", &op);

        switch (op) {
            case 1: listar(); break;
            case 2: inserir(); break;
            case 3: remover(); break;
            case 4: break;
            default: printf("\nOpção inválida.");
        }
    }

    return 1;
}