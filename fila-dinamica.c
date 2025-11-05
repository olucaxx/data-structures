#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

typedef struct {
    no *inicio; // vai ser atendido (primeiro)
    no *fim; // acabou de chegar (ultimo)
} fila;

fila* criar() {
    fila *f = malloc(sizeof(fila));
    f->fim = NULL;
    f->inicio = NULL;
    return f;
}

void enfilerar(fila *f, int valor) {
    no *novoNo = malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    
    if(f->inicio == NULL) { // lista vazia
        f->fim = novoNo;
        f->inicio = novoNo;
        return;
    }
    f->fim->prox = novoNo; // o prox da fila sera o novo no
    f->fim = novoNo; // o fim agora eh o novo no
}

void desenfilerar(fila *f) {
    no *aux = f->inicio;
    
    if(aux == NULL) {
        printf("fila vazia\n");
        return;
    }
    f->inicio = aux->prox;
    
    free(aux);
    return;
}

void exibir(fila *f) {
    no *aux = f->inicio;
    
    while(aux != NULL) { 
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void destruir(fila *f) {
    no *aux = f->inicio, *aaux; // aux eh o inicio, aaux sera usado depois
    
    while(aux != NULL) {
        aaux = aux; // aaux tera o endereco de aux
        aux = aux->prox; // aux tera o endereco do prox no
        free(aaux); // liberamos aaux, que agora eh dif de aux
    }
    free(f); // liberamos a lista em si
}

void main() {
    fila *f = criar();
    enfilerar(f, 1);
    enfilerar(f, 2);
    enfilerar(f, 3);
    exibir(f);
    desenfilerar(f);
    exibir(f);
    destruir(f);
}