
typedef struct no {
    int valor;
    struct no *prox;
} no;

typedef struct {
    no *inicio;
} lista;

lista* cria_lista();
int insere_inicio(lista *l, int valor);
int insere_final(lista *l, int valor);
int remove_inicio(lista *l);
int remove_final(lista *l);
int destruir_lista(lista *l);
void exibir_lista(lista *l);
