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

// Busca um valor na lista e remove a primeira ocorrência encontrada
void remover() {

    if (inicio == NULL) {
        printf("\nA lista está vazia, não é possível remover.");
        return;
    }

    // Define o valor que será buscado
    int alvo;
    printf("\nDigite o valor que será removido: ");
    scanf("%d", &alvo);

    // Percorre cada elemento da lista
    // (Em cada execução, atualiza o elemento atual para o próximo e guarda uma referência ao anterior)
    // (A execução é interrompida caso o elemento seja encontrado ou todos os elementos sejam percorridos)
    struct Lista *elemento = inicio, *anterior = NULL;
    while (elemento != NULL && elemento->valor != alvo) {
        anterior = elemento;
        elemento = elemento->prox;
    }
    
    // Se o último elemento percorrido for NULL, o valor alvo não foi encontrado
    if (elemento == NULL) {
        printf("\nO valor não corresponde a nenhum elemento na lista, nenhum elemento foi removido.");
        return;
    }

    // Se o elemento anterior for NULL, o elemento foi encontrado e era o primeiro da lista
    if (anterior == NULL) {
        // Faz o início apontar para o próximo elemento
        inicio = elemento->prox;
    }
    // Se havia um elemento anterior:
    else {
        // Faz o elemento anterior apontar o próximo do alvo como próximo
        anterior->prox = elemento->prox;
    }

    free(elemento);
    printf("\nO elemento foi removido da lista.");
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