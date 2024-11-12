// Lista encadeada

#include <stdio.h>
#include <stdlib.h>

struct no {
    // Dado
    int valor;
    // Ponteiro para no
    struct no *proximo;
};

void insereNo( struct no **cabecaLista, int val ) {

    struct no *elemento, *p;

    // aloca espaço para um no
    elemento = malloc( sizeof(struct no) );
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

void insereNoAlt( struct no **cabecaLista, int val ) {
    struct no *elemento;

    // aloca espaço para um no
    elemento = malloc( sizeof(struct no) );
    if(!elemento) {
        printf("Erro de alocação de memória");
        exit(-1);
    }
    elemento->valor = val;
    
    elemento->proximo = *cabecaLista;
    *cabecaLista = elemento;
}

void imprimeLista( struct no *cabecaLista) {
    struct no *p;

    printf("\nElementos da lista:\n");
    p = cabecaLista;
    while(p) {
        printf("%d\n", p->valor);
        p = p->proximo;
    }
}

void main() {
    struct no *lista;
    //inicializa lista vazia
    lista = NULL;

    insereNo( &lista, 1);
    insereNo( &lista, 2);
    insereNo( &lista, 3);
    insereNo( &lista, 4);
    
    imprimeLista(lista);

    insereNoAlt( &lista, 1);
    insereNoAlt( &lista, 2);
    insereNoAlt( &lista, 3);
    insereNoAlt( &lista, 4);
    
    imprimeLista(lista);
}
