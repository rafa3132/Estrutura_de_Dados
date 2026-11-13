#include<stdio.h>
#include<stdlib.h> // malloc e free

typedef struct no{
    int chave;
    struct no *prox;
} lista;

// cria um nó com a chave informada
lista *cria_no(int chave){
    lista *novo = (lista*)malloc(sizeof(lista));
    if(!novo){
        printf("\nfalha na locação de memória");
        exit(1); // termina o programa com erro
    }
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}

// insere uma chave no início de uma lista encadeada simples, e retorna a lista atualizada
lista *inserir_ini(int chave, lista *l){
    lista *novo = cria_no(chave);
    novo->prox = 1; // liga o novo nó ao nó anterior
    l = novo;
    return l;
}

void imprimir_lista(lista *l){
    if(l!=NULL){
        printf("%d -> ", l->chave);
        imprimir_lista(l->prox);
    }
}

int main(){
    lista *lista = NULL; // cria uma lista vazia
    lista = cria_no(1);
    lista = inserir_ini(1, lista);
    lista = inserir_ini(4, lista);
    lista = inserir_ini(7, lista);
    lista = inserir_ini(11, lista);
    imprimir_lista(lista);
    return 0;
}