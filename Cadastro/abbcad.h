// abbcad.h
// Árvore Binária de Busca para Cadastro

#include "cadastro.h"


typedef struct no {
    REGISTRO reg;
    struct no *esq;
    struct no *dir;
} NO_CAD;

void imprimeOrdenado(NO_CAD *);
NO_CAD *insereNo(NO_CAD *, REGISTRO );
NO_CAD *criaNo(REGISTRO);
void buscaABB(NO_CAD *, char *);

