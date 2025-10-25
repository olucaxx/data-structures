#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

lista* cria_lista() {
    lista *l;

    l = malloc(sizeof(lista));
    l->inicio = NULL; // lista vazia, apontamos para nada

    return l;
}

int insere_inicio(lista *l, int valor) {
    no *novo_no;
    novo_no = malloc(sizeof(no));
    novo_no->valor = valor; // atribumos o valor do novo_no

    novo_no->prox = l->inicio; // o novo_no vai apontar para o head atual da lista
    l->inicio = novo_no; // agora, o head da lista sera esse novo_no
    return 0;
}

int insere_final(lista *l, int valor) {
    no *novo_no;
    novo_no = malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->prox = NULL; // apontamos para NULL, indicando o fim da lista

    if (l->inicio == NULL) { // caso a lista esteja vazia
        l->inicio = novo_no;
        return 0;
    }

    no *ultimo_no; // variavel auxiliar para iteramos a lista
    ultimo_no = l->inicio;

    while(ultimo_no->prox != NULL) ultimo_no = ultimo_no->prox; // vamos indo de prox em prox ate achar o null

    ultimo_no->prox = novo_no; // agora o ultimo_no vai apontar para o novo_no, que aponta para null
    return 0;
}

int remove_inicio(lista *l) {
    no *primeiro_no;

    if (l->inicio == NULL) return -1; // lista vazia

    primeiro_no = l->inicio; // o primeiro no eh igual ao head da lista
    l->inicio = primeiro_no->prox; // o novo head da lista sera o no que o primeiro_no aponta
    free(primeiro_no); // liberamos o primeiro_no
    return 0;
}

int remove_final(lista *l) {
    no *ultimo_no;

    if (l->inicio == NULL) return -1; // lista vazia

    ultimo_no = l->inicio;

    if (ultimo_no->prox == NULL) { // temos apenas um elemento
        l->inicio = NULL; // apenas indicamos o head como null
        free(ultimo_no); // liberamos o no
        return 0;
    }

    while(ultimo_no->prox->prox != NULL) { // vemos se o no da frente do atual eh null, estamos um atras do que procuramos
        ultimo_no = ultimo_no->prox;
    }

    free(ultimo_no->prox); // vamos liberar o prox, pois ele que aponta para null
    ultimo_no->prox = NULL; // colocamos o atual como o ultimo, apontando para null
    return 0;
}

int destruir_lista(lista *l) {
    no *aux;

    while(l->inicio != NULL) {
        aux = l->inicio;
        l->inicio = aux->prox;
        free(aux);
    }
    free(l);
    return 0;
}

void exibir_lista(lista *l) {
    no *no_atual;

    if (l->inicio == NULL) {
        printf("Lista vazia!");
        return;
    }

    no_atual = l->inicio;

    while(no_atual != NULL) {
        printf("%d -> ", no_atual->valor);
        no_atual = no_atual->prox;
    }
    printf("NULL");
}
