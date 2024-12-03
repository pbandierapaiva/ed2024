// arvore.c - implementação de árvore binária

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
    struct no *pai;
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
        novoNo->pai = (NO *)raiz;
        *raiz = novoNo;
        return;
    }
    if(val > (*raiz)->valor)     // maior
        insereNo(  &((*raiz)->dir), val);
    else   // menor ou igual
        insereNo(  &((*raiz)->esq), val);
}

NO *proximo(NO *no) {
    if(no->dir != NULL) {
        NO *y = no->dir;
        while( y->esq != NULL )
            y = y->esq;
        return y;
    }
    while(no->pai != NULL && no->pai->dir == no )
        no = no->pai;
    return no->pai;
}

void imprimeERD(NO *raiz) {
    if(raiz!=NULL) {
        imprimeERD( raiz->esq );
        printf("%d\n",raiz->valor);
        imprimeERD( raiz->dir );
    }
}

void imprimeDRE(NO *raiz) {
    if(raiz!=NULL) {  
        imprimeDRE( raiz->dir );
        printf("%d\n",raiz->valor);
        imprimeDRE( raiz->esq );
    }
}

int altura(NO *no) {
    int aEsq, aDir;

    if( no==NULL )
        return -1;    
    aEsq = altura(no->esq);
    aDir = altura(no->dir);

    if(aEsq>aDir) 
        return aEsq+1;
    else
        return aDir+1;
}

NO *busca( NO *no, int val ){
    if( no==NULL || no->valor == val ) 
        return no;
    if( no->valor > val )
        return busca( no->esq, val );
    else   
        return busca( no->dir, val );
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
    // imprimeDRE(raiz);

    printf("\nAltura da árvore: %d\n\n", altura(raiz));
}
