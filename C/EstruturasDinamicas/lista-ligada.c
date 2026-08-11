#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa um elemento de uma Lista Ligada (ou "Linked List")
struct Lista {
    int valor;
    struct Lista *prox;
};
struct Lista *inicio = NULL, *fim = NULL;

void listar() {
}

void inserir() {
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
            default: printf("\nOpção inválida");
        }
    }

    return 1;
}