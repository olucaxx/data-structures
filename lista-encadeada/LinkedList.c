#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* create() {
    LinkedList *l;

    l = malloc(sizeof(LinkedList));
    l->head = NULL; // lista vazia, apontamos para nada

    return l;
}

int appendFirst(LinkedList *l, int value) {
    Node *newNode;

    newNode = malloc(sizeof(Node));
    newNode->value = value; // atribumos o valor do novo no

    newNode->next = l->head; // o novo no vai apontar para o head atual da lista
    l->head = newNode; // agora, o head da lista sera esse no
    return 0;
}

int appendLast(LinkedList *l, int value) {
    Node *newNode;

    newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL; // apontamos para NULL, indicando o fim da lista

    if (l->head == NULL) { // caso a lista esteja vazia
        l->head = newNode;
        return 0;
    }

    Node *lastNode; // variavel auxiliar para iteramos a lista
    lastNode = l->head;

    while(lastNode->next != NULL) lastNode = lastNode->next; // vamos indo de prox em prox ate achar o null

    lastNode->next = newNode; // agora o ultimo no vai apontar para o novo no, que aponta para null
    return 0;
}

int popFirst(LinkedList *l) {
    Node *firstNode;

    if (l->head == NULL) return -1; // lista vazia

    firstNode = l->head; // o primeiro no eh igual ao head da lista
    l->head = firstNode->next; // o novo head da lista sera o no que o primeiro_no aponta
    free(firstNode); // liberamos o primeiro_no
    return 0;
}

int popLast(LinkedList *l) {
    Node *lastNode;

    if (l->head == NULL) return -1; // lista vazia

    lastNode = l->head;

    if (lastNode->next == NULL) { // temos apenas um elemento
        l->head = NULL; // apenas indicamos o head como null
        free(lastNode); // liberamos o no
        return 0;
    }

    while(lastNode->next->next != NULL) { // vemos se o no da frente do atual eh null, estamos um atras do que procuramos
        lastNode = lastNode->next;
    }

    free(lastNode->next); // vamos liberar o prox, pois ele que aponta para null
    lastNode->next = NULL; // colocamos o atual como o ultimo, apontando para null
    return 0;
}

int destroy(LinkedList *l) {
    Node *aux;

    while(l->head != NULL) {
        aux = l->head;
        l->head = aux->next;
        free(aux);
    }
    free(l);
    return 0;
}

void print(LinkedList *l) {
    Node *currentNode;
    currentNode = l->head;

    while(currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    }

    printf("NULL\n");
}

int length(LinkedList *l) {
    Node *currentNode;
    int counter = 0;
    currentNode = l->head;

    while(currentNode != NULL) { // igual a logica de imprimir a lista
        counter++; // vai aumentando o contador ate achar null
        currentNode = currentNode->next;
    }

    return counter;
}

int insertvalue(LinkedList *l, int index, int value) {
    Node *currentNode, *newNode, *aux;
    int currentIndex;

    if(index > length(l)) return -1; // ja valida a insercao em uma posicao inexistente, piora um pouco o tempo de exec

    newNode = malloc(sizeof(Node)); // alocamos um espaco na memoria para o novo no
    newNode->value = value; // armazenamos nosso novo valor
    currentNode = l->head; // vamos referenciar o primeiro elemento com o no atual
    currentIndex = 0; // posicao zero, inicio

    index -= 1; // vamos reduzir o index em 1 pois estamos atras de selecionar o no que aponta para a pos desejada
    while(currentIndex < index) { // se zero for o index ele nem roda o while
        currentIndex++;
        currentNode = currentNode->next;
    }

    aux = currentNode->next;
    currentNode->next = newNode;
    newNode->next = aux;

    return 0;
}

int removeValue(LinkedList *l, int index) {
    Node *currentNode,*aux;
    int currentIndex;

    if(index >= length(l) | length < 0) return -1; // ja valida a remocao de uma pos invalida

    currentNode = l->head; // comecamos do inicio ne
    currentIndex = 0; // posicao zero, inicio

    if(index == 0) { // caso seja o primeiro elemento
        l->head = currentNode->next; // temos que alterar para onde a head aponta
        free(currentNode);
        return 0;
    }

    index -= 1; // vamos reduzir o index em 1 pois estamos atras de selecionar o no que aponta para a pos desejada
    while(currentIndex < index) { // se zero for o index ele nem roda o while
        currentIndex++;
        currentNode = currentNode->next;
    }

    aux = currentNode->next; // armazenamos o valor do prox
    currentNode->next = currentNode->next->next; // fazemos o atual apontar para onde o prox apontava
    free(aux); // liberamos a memoria do antigo no

    return 0;
}
