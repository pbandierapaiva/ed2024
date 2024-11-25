// PILHA usando lista ligada
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    // Dado
    int valor;
    // Ponteiro para no
    struct no *proximo;
} NO;

// Insere nó no início da lista
void push( NO **cabecaLista, int val ) {
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

int pop( NO **cabecaLista ) {
    int val;
    NO *elemento;

    if(*cabecaLista==NULL){
        printf("\nPilha vazia\n");
        return -1;
    }
    elemento = *cabecaLista;
    *cabecaLista = elemento->proximo;
    val = elemento->valor;
    free(elemento);
    return val;
}

int main() {
    NO *pilha=NULL; 
    int valor;
    char acao[10];
    int continua=1;

    while(continua) {
        printf("Entre com opção p(U)sh, p(O)p, (F)im (U/O/F) ");
        scanf("%s", acao);
        switch( toupper( acao[0] )  ) {
            case 'U':  //PUSH
                printf("Entre Valor: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 'O':  //POP
                valor = pop(&pilha);
                if(valor>=0) 
                    printf("%d", valor);
                break;
            default:
                continua = 0;
        }
    }

}

