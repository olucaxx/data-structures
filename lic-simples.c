#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

typedef struct {
    no *inicio;
} lista;

lista* criar() {
    lista *l = malloc(sizeof(lista));
    l->inicio = NULL;
    return l;
}

void inserirInicio(lista *l, int v) {
    no *n = malloc(sizeof(no));
    n->valor = v;
    
    if(l->inicio == NULL) {
        l->inicio = n;
        n->prox = n;
        return;
    }
    
    no *aux = l->inicio;
    while(aux->prox != l->inicio) aux = aux->prox;
    
    n->prox = l->inicio;
    aux->prox = n;
    l->inicio = n;
}

void inserirFim(lista *l, int v) {
    no *n = malloc(sizeof(no));
    n->valor = v;

    if(l->inicio == NULL) {
        l->inicio = n;
        n->prox = n;
        return;
    }

    no *aux = l->inicio;
    while(aux->prox != l->inicio) aux = aux->prox;
    
    aux->prox = n;
    n->prox = l->inicio;
}

void removerInicio(lista *l) {
    if(l->inicio == NULL) return;

    if(l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return;
    }

    no *aux = l->inicio;
    while(aux->prox != l->inicio) aux = aux->prox;

    no *temp = l->inicio;
    l->inicio = temp->prox;
    aux->prox = l->inicio;

    free(temp);
}

void removerFim(lista *l) {
    if(l->inicio == NULL) return;

    if(l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return;
    }

    no *aux = l->inicio;
    no *ant = NULL;

    while(aux->prox != l->inicio) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = l->inicio;
    free(aux);
}

void exibir(lista *l) {
    if(l->inicio == NULL) {
        printf("lista vazia\n");
        return;
    }

    no *aux = l->inicio;
    do {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    } while(aux != l->inicio);
    printf("(inicio)\n");
}

void atualizar(lista *l, int antigo, int novo) {
    if(l->inicio == NULL) return;

    no *aux = l->inicio;
    do {
        if(aux->valor == antigo) {
            aux->valor = novo;
            // return; // retirar o comentário define se será todos ou apenas o primeiro elemento
        }
        aux = aux->prox;
    } while(aux != l->inicio);
}

void destruir(lista *l) {
    if(l->inicio == NULL) {
        free(l);
        return;
    }

    no *aux = l->inicio;
    no *prox;

    do {
        prox = aux->prox;
        free(aux);
        aux = prox;
    } while(aux != l->inicio);

    free(l);
}

void main() {
    lista *l = criar();

    inserirInicio(l, 3);
    inserirInicio(l, 2);
    inserirFim(l, 4);
    inserirFim(l, 4);

    exibir(l);

    removerInicio(l);
    exibir(l);

    atualizar(l, 4, 11);
    exibir(l);

    removerFim(l);
    exibir(l);

    destruir(l);
}
