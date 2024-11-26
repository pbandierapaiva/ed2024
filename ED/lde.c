// lde.c Implementação de Lista duplamente encadeada

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} LDE;

void insereNo(LDE **raiz, int val) {
    LDE *novoNo;

    novoNo = malloc(sizeof(LDE));
    if( !novoNo ) {
        printf("ERRO de alocação de memória");
        exit(-1);
    }
    novoNo->valor = val;
    novoNo->ant = NULL;
    novoNo->prox = *raiz;
    if(*raiz)    // Lista não vazia?
        (*raiz)->ant = novoNo;
    *raiz = novoNo;
}

LDE *busca(LDE *raiz, int val) {
    LDE *p;

    p=raiz;
    while(p){
        if(p->valor == val)
            return p;
        p= p->prox;
    }
    return NULL;
}

void removeNo(LDE **raiz, LDE *no) {
    if( no->ant==NULL )    //primeiro da lista
        *raiz = no->prox;
    else
        no->ant->prox = no->prox;
    if( no->prox )
        no->prox->ant = no->ant;
    free(no);    
}
void removeNoValor(LDE **raiz, int val) {
    LDE *p;

    p = busca(*raiz, val);
    if(p)
        removeNo( raiz, p);
}
void imprimeLista( LDE *cabecaLista) {
    LDE *p;

    printf("\nElementos da lista:\n");
    p = cabecaLista;
    while(p) {
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

int main(){

    LDE *lista;

    lista=NULL;

    insereNo(&lista, 1);
    insereNo(&lista, 2);
    insereNo(&lista, 3);
    insereNo(&lista, 4);
    insereNo(&lista, 5);
    insereNo(&lista, 6);

    imprimeLista(lista);

    removeNoValor(&lista, 4);
    removeNoValor(&lista, 1);
    removeNoValor(&lista, 6);
    insereNo(&lista, 7);

    imprimeLista(lista);
}

