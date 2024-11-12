// Lista encadeada usando 'typedef':   typedef struct no NO;

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    // Dado
    int valor;
    // Ponteiro para no
    struct no *proximo;
} NO;

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

void main() {
    NO *lista;
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

    // Teste do buscaNo
    NO *p=NULL;
    p = buscaNo(lista, 3);
    if(p)
        printf("Encontrou nó 3\n");
    else
        printf("Não encontrou nó 3\n");
    p = buscaNo(lista, 5);
    if(p)
        printf("Encontrou nó 5\n");
    else
        printf("Não encontrou nó 5\n");
}
