// Exemplo de matriz esparsa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tempNo {
    int valor;
    int coluna;
    struct tempNo *prox;
} NO;

typedef NO* PONT;

typedef struct {
    PONT *vetLin;
    int linhas;
    int colunas;
} MATRIZ;

void inicializa( MATRIZ *m, int lin, int col ){

    m->linhas = lin;
    m->colunas= col;
    m->vetLin = malloc( sizeof(PONT)*lin );
    if( ! m->vetLin ) {
        printf("Erro de alocação de memória.\n");
        exit(-1);
    }
    for(int i=0; i<lin; i++) 
        m->vetLin[i]=NULL;
}

bool coloca( MATRIZ *m, int l, int c, int val ) {
    PONT paux, pant;
    PONT novoNo=NULL;
    
    if( l<0 || c<0 || l >= m->linhas || c >= m->colunas)
        return false;

    pant = NULL;
    paux = m->vetLin[l];
    
    while( paux!=NULL && paux->coluna < c  ) {  //linha tem dados?
        pant = paux;
        paux = paux->prox;
        continue;
    }
    if( paux != NULL &&  paux->coluna == c ) {   // já existe valor nessa posição
        if(val==0) {
            if(pant==NULL) 
                m->vetLin[l] = paux->prox;
            else
                pant->prox = paux->prox;
            free(paux);
        }
        else
            paux->valor = val;
    }
    else {
        if(val!=0) {
            novoNo = malloc( sizeof(NO) );
            novoNo->valor = val;
            novoNo->coluna= c;
            novoNo->prox = paux;

            if(pant==NULL) m->vetLin[l] = novoNo;
            else pant->prox = novoNo;
        }
    }
    return true;
}


int busca( MATRIZ *m, int l, int c ) {
    PONT p;

    if( l<0 || c<0 || l >= m->linhas || c >= m->colunas)
        return 0;

    p = m->vetLin[l];
    while( p!=NULL && p->coluna < c){
        p = p->prox;
    }
    if(p!=NULL && p->coluna == c )
            return p->valor;
    return 0;
}

int main(){

    MATRIZ mat;

    inicializa(&mat,1000000,1000000);

    coloca(&mat, 100000, 1000, 5);

    coloca(&mat, 100010, 2000, 15);
    coloca(&mat, 100020, 3000, 25);
    coloca(&mat, 300000, 4000, 35);

    printf("%d\n%d\n%d",
        busca(&mat,100010, 2000),
        busca(&mat,300000, 4000),
        busca(&mat,100110, 2000)
        );
}
