#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

typedef struct {
    no *topo;
} pilha;

pilha* criar() {
    pilha *p = malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

void colocar(pilha *p, int valor) {
    no *novoNo = malloc(sizeof(pilha)), *aux;
    novoNo->valor = valor;
    
    if(p->topo == NULL) { // pilha vazia
        novoNo->prox = NULL;
        p->topo = novoNo;
        return;
    }
    
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

void retirar(pilha *p) {
    no *aux = p->topo;
    
    if(aux == NULL) { // lista vazia
        printf("lista vazia!");
        return; 
    }
    
    p->topo = aux->prox;
    free(aux); // libera a memoria do antigo topo
    return;
}

void exibir(pilha *p) {
    no *aux = p->topo;

    while(aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void destruir(pilha *p) {
    no *aux = p->topo, *aaux; // aux sera o topo atual
    
    while(aux != NULL) {
        aaux = aux; // armazemamos o endereco de aux em aaux
        aux = aux->prox; // aux apontara para o prox
        free(aaux); // liberamos aaux, que aponta para o antigo end de aux
    }
    free(p); // liberamos a pilha
}

void main() {
    pilha *p = criar();
    colocar(p, 1);
    colocar(p, 2);
    colocar(p, 3);
    exibir(p);
    retirar(p);
    exibir(p);
    destruir(p);
}