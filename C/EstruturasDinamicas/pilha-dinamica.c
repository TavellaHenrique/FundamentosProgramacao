#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa um elemento da pilha
// Cada elemento possui um valor e aponta para o próximo elemento (que seria um elemento "abaixo", em uma pilha convencional)
struct Pilha {
    int valor;
    struct Pilha *prox;
};
// A pilha inicia sem nenhum elemento
struct Pilha *topo = NULL;

// Lista o valor de cada elemento, do topo à "base"
void listar() {
    if (topo == NULL) {
        printf("\nA pilha está vazia.");
        return;
    }

    // Percorre cada elemento, exibindo seu valor
    for (struct Pilha *elemento = topo; elemento != NULL; elemento = elemento->prox) {
        printf("\nValor: %d", elemento->valor);
    }
}

// Insere um elemento no topo da pilha
void inserir() {
    // Recebe o valor do elemento
    int valor = 0;
    printf("\nDigite um número inteiro: ");
    scanf("%d", &valor);

    // Aloca memória para o novo elemento
    struct Pilha *elemento = (struct Pilha *) malloc(sizeof(struct Pilha));

    // Define o valor do novo elemento
    elemento->valor = valor;
    
    // Faz o novo elemento apontar para NULL, se for o único da pilha, ou para o topo atual.
    if (topo == NULL) elemento->prox = NULL;
    else elemento->prox = topo;

    // Define o novo elemento como topo da pilha
    // Com esse processo, o topo passa a apontar para o elemento "abaixo"
    topo = elemento;

    printf("\nO elemento foi adicionado ao topo da pilha.");
}

void remover() {
    if (topo == NULL) {
        printf("\nA pilha está vazia, não é possível remover.");
        return;
    }

    // Cria um ponteiro que aponta para o atual topo
    struct Pilha *elemento = topo;
    // Define o topo como o próximo elemento da lista
    topo = topo->prox;

    // Libera a memória utilizada pelo antigo topo
    free(elemento);

    printf("\nO elemento do topo da pilha foi removido.");
}

int main() {
    setlocale(LC_ALL, "pt-br");

    int op = 0;

    while (op != 4) {
        printf("\n\n|-- Pilha Dinâmica --|");
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