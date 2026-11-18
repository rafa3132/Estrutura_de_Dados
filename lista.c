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
    novo->prox = l; // liga o novo nó ao nó anterior
    l = novo;
    return l;
}

// imprime os dados da estrutura no formatro x -> y
void imprimir_lista(lista *l){
    if(l!=NULL){
        printf("%d -> ", l->chave);
        imprimir_lista(l->prox);
    }
}

lista *buscar(lista *l, int chave){
    lista *aux = l;
    if(aux && aux->chave != chave){
        aux = buscar(aux->prox, chave);
    }
    return aux;
}

int obterTamanho(lista *l){
    int contador = 0;
    lista *lista = l;
    while(lista){
        contador++;
        lista = lista->prox;
    }
    return contador;
}

int obterTamanhoRec(lista *l){
    if(l==NULL){
        return 0;
    } else {
        return 1 + obterTamanhoRec(l->prox);
    }
}

lista *retornaMeio(lista *l){
    lista *aux1 = l, *aux2 = l;
    while(aux2->prox){
        aux1 = aux1->prox;
        aux2 = aux2->prox->prox;
    } 
    return aux1;
}

int main(){
    lista *lista = NULL, *busca; // cria uma lista vazia
    lista = cria_no(1);
    lista = inserir_ini(4, lista);
    lista = inserir_ini(7, lista);
    lista = inserir_ini(11, lista);
    lista = inserir_ini(25, lista);
    lista = inserir_ini(50, lista);
    imprimir_lista(lista);

    busca = buscar(lista, 4 );
    printf("\nBusca: %d\n", busca->chave);

    printf("Quantidade: %d\n", obterTamanho(lista));

    printf("QuantidadeRec: %d\n", obterTamanhoRec(lista));

    printf("Meio da lista: %d", retornaMeio(lista)->chave);
    return 0;
}