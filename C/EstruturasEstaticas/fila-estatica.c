#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Constante que estabelece o tamanho do vetor
#define MAX 5

// Estrutura que representa uma Fila
// O elemento que foi inserido primeiro será removido primeiro ("First in, first out")
struct Fila {
    char valores[MAX];
    int inicio, fim;
};
struct Fila fila;

// Lista todos os valores e suas posições na fila
void listar() {

    if (fila.fim == 0) {
        printf("\nFila vazia.");
        return;
    }

    for (int i = 0; i < fila.fim; i++) {
        printf("\nPosição: %d | Valor: %c", i, fila.valores[i]);
    }
}

// Insere um valor na fila
void inserir() {
    if (fila.fim == MAX) {
        printf("\nNão é possível inserir, a fila está cheia.");
        return;
    }
    
    char letra;
    printf("\nDigite uma letra: ");
    scanf(" %c", &letra);

    fila.valores[fila.fim] = letra;
    fila.fim++;
    
    printf("\nElemento inserido no final da lista.");
}

// Remove o primeiro valor da lista
void remover() {
    if (fila.fim == 0) {
        printf("\nNão é possível remover, a fila está vazia.");
        return;
    }

    // Repete uma vez para cada elemento do início da fila até o penúltimo elemento
    for (int i = fila.inicio; i < (fila.fim - 1); i++) {
        // O elemento assume o valor do próximo elemento
        fila.valores[i] = fila.valores[i+1];
    }

    // Atualiza o fim da fila
    fila.fim--;

    printf("Elemento removido do início da lista.");
}

int main() {
    setlocale(LC_ALL, "pt-br");

    // A lista começa vazia
    fila.inicio = fila.fim = 0;

    // Opção do menu escolhida pelo usuário
    int op;

    while (op != 4) {
        printf("\n\n|-- Fila estática --|");
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