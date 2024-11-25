// Fila usando lista ligada
#include <stdio.h>

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

int removeNo( NO **cabecaLista ) {
    NO *elemento;
    int val;

    elemento = *cabecaLista;
    if( elemento==NULL ) {
        printf("\nFila vazia\n");
        return -1;
    }

    *cabecaLista = elemento->proximo;
    val = elemento->valor;
    free(elemento);
    return val;
}

int main(){
    NO *fila = NULL;
    int valor;

    printf("Entre com valores inteiros positivos, 0 encerra:\n");

    while(1) {
        scanf("%d", &valor);
        if( valor <=0 )
            break;
        insereNo(&fila, valor);
    }

    while(1) {
        valor = removeNo(&fila);
        if( valor<=0 ) break;
        printf("%d\n", valor);
    } 
}