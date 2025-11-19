#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct{
    no *inicio;
}lista;

lista *criar(){
    lista *l;

    l = malloc(sizeof(lista));
    l->inicio = NULL;
    return l;
}

void exibir(lista *l){
    if(l->inicio == NULL){
      printf("Lista Vazia \n");
    }else{
        no *aux;

        aux = l->inicio;
        do{
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }while(aux != l->inicio);
        printf("(inicio)\n");
    }
}

void inserirInicio(lista *l, int v){
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

void inserirFim(lista *l, int v){
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

void removerInicio(lista *l){
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

void removerFim(lista *l){
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

void atualizar(lista *l, int antigo, int novo){
    if(l->inicio == NULL) return;

    no *aux = l->inicio;
    do {
        if(aux->valor == antigo) {
            aux->valor = novo;
            return; // comentar isso faz alterar todos os elementos correspondentes
        }
        aux = aux->prox;
    } while(aux != l->inicio);
    
    printf("Valor não encontrado.\n");
}

void destruir(lista *l){
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

void main(){
    setlocale(LC_ALL, "Portuguese");

    lista *l;
    int op, valor, valor_novo;

    l = criar();

    do{
        printf("[1] - Inserir no inicio: \n");
        printf("[2] - Inserir no fim: \n");
        printf("[3] - Remover no inicio: \n");
        printf("[4] - Remover no fim: \n");
        printf("[5] - Exibir a lista: \n");
        printf("[6] - Procurar e substituir um valor especifico: \n");
        printf("[0] - Sair: \n");
        scanf("%i", &op);
        switch(op){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%i", &valor);
                inserirInicio(l, valor);
                exibir(l);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%i", &valor);
                inserirFim(l, valor);
                exibir(l);
                break;
            case 3:
                removerInicio(l);
                exibir(l);
                break;
            case 4:
                removerFim(l);
                exibir(l);
                break;
            case 5:
                exibir(l);
                break;
            case 6:
                printf("Digite o valor o valor que quer substituir: ");
                scanf("%i", &valor);
                printf("Digite o valor o valor que vai substitui-lo: ");
                scanf("%i", &valor_novo);
                atualizar(l, valor, valor_novo);
                exibir(l);
                break;
            case 0:
                destruir(l);
                printf("Programa Finalizado\n");
                break;
            default:
                printf("Opcao invalida, tente novamente\n");
        }
    system("pause");
    system("cls");
    }while(op != 0);
}