// cadLL.c Implementação de lista ligada 
// para armazenar dados do cadastro
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "cadastro.h"
#include "cadLL.h"

void insereNo( NOcadLL **cabecaLista, REGISTRO reg ) {

    NOcadLL *elemento, *p;

    // aloca espaço para um no
    elemento = malloc( sizeof(NOcadLL) );
    if(!elemento) {
        printf("Erro de alocação de memória");
        exit(-1);
    }

    // Não dá para copiar o registro inteiro, tem que ser por partes
    // elemento->registro = reg;
    strcpy(reg.id, elemento->registro.id);
    strcpy(reg.nome, elemento->registro.nome);
    strcpy(reg.lotacao, elemento->registro.lotacao);
    strcpy(reg.funcao, elemento->registro.funcao);
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

void imprimeLista( NOcadLL *cabecaLista) {
    NOcadLL *p;

    printf("\nElementos da lista:\n");
    p = cabecaLista;
    while(p) {
        printf("%s\n", p->registro.nome);
        p = p->proximo;
    }
}
