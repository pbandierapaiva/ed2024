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
    strcpy(elemento->registro.id, reg.id);
    strcpy(elemento->registro.nome, reg.nome);
    strcpy(elemento->registro.lotacao, reg.lotacao);
    strcpy(elemento->registro.funcao, reg.funcao);
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
        // printf("%s\n", p->registro.nome);
        imprimeReg(p);
        p = p->proximo;
    }
    printf("\n--------------------\nTamanho da lista: %d\n\n", tamanhoLista(cabecaLista));
}

NOcadLL *buscaNo( NOcadLL *r, char *s ) {
    char *res;

    while( r ) {
        res = strstr( r->registro.nome, s);
        if(res) {
            return r;
        }
        r = r->proximo;
    }
    return r;
}

NOcadLL *buscaLista( NOcadLL *r, char *s ) {
    NOcadLL *resultado = NULL;

    while( r ) {
        if( r->registro.nome == strstr( r->registro.nome, s) ){
            insereNo(&resultado, r->registro);
        }
        r = r->proximo;
    }
    return resultado;
}

int tamanhoLista(NOcadLL *p ) {
    int conta=0;

    while(p) {
        conta++;
        p = p->proximo;
    }
    return conta;
}

void imprimeReg( NOcadLL *p ) {
    if(!p) return;
    printf("\nID %s\nNome: %s\nLotação: %s\nFunção: %s\n",
        p->registro.id, p->registro.nome, p->registro.lotacao, p->registro.funcao);
}