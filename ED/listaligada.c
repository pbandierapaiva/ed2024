// Lista ligada usando 'typedef':   typedef struct no NO;

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    // Dado
    int valor;
    // Ponteiro para no
    struct no *proximo;
} NO;

// Insere nó no FIM da lista
void insereNo( NO **cabecaLista, int val ) {

    NO *elemento, *p;

    // aloca espaço para um no
    elemento = malloc( sizeof(NO) );
    if(!elemento) {
        printf("Erro de alocação de memória");
        exit(-1);
    }

    elemento->valor = val;
    elemento->proximo = NULL;

    //insere elemento ao final da lista
    p = *cabecaLista;
    if(p==NULL) {    //lista vazia
        *cabecaLista = elemento;
        return;
    }
    while( p->proximo!=NULL ){  // não está no final da lista?
        p = p->proximo;
    }
    p->proximo = elemento;
}

// Insere nó no início da lista
void insereNoAlt( NO **cabecaLista, int val ) {
    NO *elemento;

    // aloca espaço para um no
    elemento = malloc( sizeof(NO) );
    if(!elemento) {
        printf("Erro de alocação de memória");
        exit(-1);
    }
    elemento->valor = val;
    
    elemento->proximo = *cabecaLista;
    *cabecaLista = elemento;
}

NO *buscaNo( NO *cabecaLista, int val ) {
    NO *p;

    p = cabecaLista;
    while(p) {
        if(p->valor == val)
            return p;
        p = p->proximo;
    }
    return p; // retorna NULL
}

void imprimeLista( NO *cabecaLista) {
    NO *p;

    printf("\nElementos da lista:\n");
    p = cabecaLista;
    while(p) {
        printf("%d\n", p->valor);
        p = p->proximo;
    }
}

void apagaNo( NO **cabeca, NO *apagar) {
    NO *p, **pPai;

    pPai = cabeca;
    p = *cabeca;
    while( p ) {
        if( p == apagar ) {
            *pPai = p->proximo;
            free(p);
            return;
        }
        pPai = &(p->proximo);
        p = p->proximo;
    }
}

void apagaNoValor( NO **cabeca, int valorApagar) {
    NO *p;

    p = buscaNo(*cabeca, valorApagar);
    if(!p) // Não encontrou
        return;
    apagaNo(cabeca, p);
}

void main() {
    NO *lista;
    //inicializa lista vazia
    lista = NULL;

    insereNo( &lista, 1);
    insereNo( &lista, 2);
    insereNo( &lista, 3);
    insereNo( &lista, 4);
    
    insereNoAlt( &lista, 5);
    insereNoAlt( &lista, 6);
    insereNoAlt( &lista, 7);
    insereNoAlt( &lista, 8);
    
    imprimeLista(lista);

    // Teste do buscaNo
    NO *p=NULL;
    p = buscaNo(lista, 6);
    if(p) {
        printf("Encontrou nó 6\nDELETANDO...\n");
        apagaNo(&lista, p);
    }
    else
        printf("Não encontrou nó 6\n");

    apagaNoValor(&lista,5);
    apagaNoValor(&lista,3);
    apagaNoValor(&lista,1);

    imprimeLista(lista);
    
}
