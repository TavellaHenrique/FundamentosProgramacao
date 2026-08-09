#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Constante que define o tamanho da Pilha (Stack)
#define MAX 5

// Estrutura que representa a pilha
// O último elemento a ser inserido será o primeiro a ser removido ("Last in, first out")
struct Pilha {
    char valores[MAX];
    int topo, inicio;
};
struct Pilha pilha;

// Lista todos os elementos da lista, do mais recente ao mais antigo (do topo ao início)
void listar() {

    if (pilha.topo == 0) {
        printf("\nA pilha está vazia.");
        return;
    }

    for (int i = pilha.topo - 1; i >= 0; i--) {
        printf("\nValor: %c", pilha.valores[i]);
        if (i == (pilha.topo -1)) {
            printf(" -> topo");
        }
    }
}

// Insere um elemento no topo da pilha
void inserir() {

    if (pilha.topo == MAX) {
        printf("\nA pilha está cheia, não é possível inserir.");
        return;
    }

    char letra;
    printf("\nInsira uma letra: ");
    scanf(" %c", &letra);

    pilha.valores[pilha.topo] = letra;
    pilha.topo++;

    printf("\nO elemento foi inserido no topo da pilha.");
}

// Remove o valor no topo da pilha, se houver
void remover() {

    if (pilha.topo == 0) {
        printf("\nA pilha está vazia, não é possível remover.");
        return;
    }

    pilha.topo--;

    printf("\nO elemento foi removido do topo da pilha.");
}

int main() {

    setlocale(LC_ALL, "pt-br");

    // A pilha começa vazia
    pilha.topo = pilha.inicio = 0;
    
    // Opção do menu escolhida pelo usuário
    int op = 0;

    while (op != 4) {
        printf("\n\n|-- Pilha estática --|");
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
            default: printf("\nOpção inválida.");
        }
    }

    return 1;
}