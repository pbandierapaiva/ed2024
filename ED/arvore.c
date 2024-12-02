// arvore.c - implementação de árvore binária

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} NO;

void insereNo(NO **raiz, int val) {
    NO *novoNo;

    if(*raiz==NULL) {  //árvore vazia
        novoNo = malloc( sizeof(NO));
        if(!novoNo) {
            printf("Erro de alocação de memória.\n");
            exit(-1);
        }
        novoNo->valor = val;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        *raiz = novoNo;
        return;
    }
    if(val > (*raiz)->valor)     // maior
        insereNo(  &((*raiz)->dir), val);
    else   // menor ou igual
        insereNo(  &((*raiz)->esq), val);
}

void imprimeERD(NO *raiz) {
    if(raiz==NULL) return;   
    imprimeERD( raiz->esq );
    printf("%d\n",raiz->valor);
    imprimeERD( raiz->dir );
}

void imprimeDRE(NO *raiz) {
    if(raiz==NULL) return;   
    imprimeDRE( raiz->dir );
    printf("%d\n",raiz->valor);
    imprimeDRE( raiz->esq );
}

int main() {
    NO *raiz = NULL;  // árvore vazia

    insereNo(&raiz, 5);
    insereNo(&raiz, 7);
    insereNo(&raiz, 9);
    insereNo(&raiz, 12);
    insereNo(&raiz, 2);
    insereNo(&raiz, 1);
    insereNo(&raiz, 14);
    insereNo(&raiz, 8);
    insereNo(&raiz, 3);
    insereNo(&raiz, 4);
    insereNo(&raiz, 11);
    insereNo(&raiz, 5);

    imprimeERD(raiz);
    imprimeDRE(raiz);
}
