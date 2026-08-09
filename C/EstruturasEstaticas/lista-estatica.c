#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Constante que determina o tamanho máximo da lista
#define MAX 5

// Estrutura que representa uma lista
// Os elementos podem ser adicionados ao final da lista ou removidos de qualquer posição
struct Lista {
    char valores[MAX];
    int inicio, tamanho;
};
struct Lista lista;

// Lista todos os valores da lista
void listar() {
    if (lista.tamanho == 0) {
        printf("\nA lista está vazia.");
        return;
    }

    for (int i = 0; i < lista.tamanho; i++) {
        printf("\nPosição: %d | Valor: %c", i, lista.valores[i]);
    }
}

// Insere um elemento ao final da lista
void inserir() {
    if (lista.tamanho == MAX) {
        printf("\nA lista está cheia, não é possível inserir.");
        return;
    }

    char letra;
    printf("\nInsira uma letra: ");
    scanf(" %c", &letra);

    lista.valores[lista.tamanho] = letra;
    lista.tamanho++;

    printf("\nO elemento foi inserido ao final da lista.");
}

// Remove um valor de acordo com a posição escolhida
void remover() {
    if (lista.tamanho == 0) {
        printf("\nA lista está vazia, não é possível remover.");
        return;
    }

    int posicao;
    printf("\nInforme a posição do elemento que será removido: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= lista.tamanho) {
        printf("\nEssa posição não corresponde a nenhum elemento na lista.");
        return;
    }

    for (int i = posicao; i < (lista.tamanho - 1); i++) {
        lista.valores[i] = lista.valores[i+1];
    }

    lista.tamanho--;

    printf("\nO elemento foi removido.");
}

int main() {
    setlocale(LC_ALL, "pt-br");

    // A lista começa vazia
    lista.inicio = lista.tamanho = 0;

    // Opção do menu escolhida pelo usuário
    int op = 0;

    while (op != 4) {
        printf("\n\n|-- Lista estática --|");
        printf("\n1. Listar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Sair");

        printf("\nOpção: ");
        scanf(" %d", &op);

        switch (op) {
            case 1: listar(); break;
            case 2: inserir(); break;
            case 3: remover(); break;
            case 4: break;
            default: printf("\nOpção inválida.");
        }
    }
}