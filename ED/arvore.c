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

NO *busca(NO *, int);

NO *criaNo(int val, NO *pai) {
    NO *novoNo;

    novoNo = malloc( sizeof(NO));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);
    }
    novoNo->valor = val;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->pai = pai;
    return novoNo;
}

NO *insereNo(NO *raiz, int val ) {

    if( raiz==NULL) {
       return criaNo(val, NULL);
    }

    if( val > raiz->valor )  {   // maior
        if(raiz->dir==NULL)
            raiz->dir = criaNo(val, raiz);
        else
            insereNo(raiz->dir, val);
    }
    else {
        if(raiz->esq==NULL)
            raiz->esq  = criaNo(val, raiz);
        else
            insereNo(raiz->esq, val);
    }
    return raiz;
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

NO *removeNo( NO *raiz ) {
    NO *p, *q;

    if( raiz->esq==NULL) q=raiz->dir;
    else {
        p = raiz;
        q = raiz->esq;
        while( q->dir!=NULL ){
            p = q;
            q = q->dir;
        }
        if( p!= raiz) {
            p->dir = q->esq;
            q->esq = raiz->esq;
        }
        q->dir = raiz->dir;
    }
    free(raiz);
    return q;
}

void removeNoVal(NO **raiz, int valor) {
    NO *s, *t;
    
    s = busca(*raiz, valor);
    
    if( s==*raiz ){
        *raiz = removeNo(s);
    }
    else {
        t = s->pai;
        if( s ==  t->esq){
            t->esq = removeNo(t->esq);
        }
        else   {
            t->dir  = removeNo(t->dir);
        }
    }
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
    NO *s,*t;

    raiz = insereNo(raiz, 6);
    raiz = insereNo(raiz, 7);
    raiz = insereNo(raiz, 9);
    raiz = insereNo(raiz, 12);
    raiz = insereNo(raiz, 2);
    raiz = insereNo(raiz, 1); 
    raiz = insereNo(raiz, 14);
    raiz = insereNo(raiz, 8);
    raiz = insereNo(raiz, 3);
    raiz = insereNo(raiz, 4);
    raiz = insereNo(raiz, 11);
    raiz = insereNo(raiz, 5);

    // removeNoVal(&raiz, 5);
    // removeNoVal(&raiz, 8);

    imprimeERD(raiz);
    // imprimeDRE(raiz);

    printf("\nAltura da árvore: %d\n\n", altura(raiz));
}
