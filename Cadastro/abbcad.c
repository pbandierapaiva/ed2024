// Le arquivo de cadastro de servidores da UNIFESP
// Insere em ABB 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abbcad.h"
#include "util.h"

NO_CAD *criaNo(REGISTRO r) {
    NO_CAD *novoNo;

    novoNo = malloc( sizeof(NO_CAD));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);
    }
    
    // Para fazer novoNo->reg = r
	// strcpy( novoNo->reg.id, r.id );
	// strcpy( novoNo->reg.nome, r.nome );
	// strcpy( novoNo->reg.lotacao, r.lotacao );
    // strcpy( novoNo->reg.funcao, r.funcao );
	// strcpy( novoNo->reg.cargo, r.cargo );
    memcpy(&(novoNo->reg), &r, sizeof(REGISTRO));

    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}


NO_CAD *insereNo(NO_CAD *raiz, REGISTRO r ) {
    int cmp;

    if( raiz==NULL) {
       return criaNo(r);
    }
    
    cmp = strcmp(r.nome, raiz->reg.nome);
    if( cmp>0 )       // r.nome > raiz->reg.nome
        raiz->dir = insereNo( raiz->dir, r);
    else if (cmp<0) {
        raiz->esq = insereNo( raiz->esq, r);
    }
    
    return raiz;  
}

void imprimeOrdenado(NO_CAD *raiz) {
    if(raiz!=NULL) {
        imprimeOrdenado( raiz->esq );
        printf("%s\n",raiz->reg.nome);
        imprimeOrdenado( raiz->dir );
    }
}

void buscaABB(NO_CAD *raiz, char *sbusca) {
    if(raiz!=NULL) {
        //if( strcmp( raiz->reg.nome, sbusca ) == 0 ) {   //SÃO IGUAIS
        if( strstr( raiz->reg.nome, sbusca ) ) {   //SÃO similares
            printf("\n%s\n%s\n%s\n%s\n\n", raiz->reg.nome, raiz->reg.lotacao, 
                raiz->reg.cargo, raiz->reg.funcao);
        }
        buscaABB( raiz->esq, sbusca);
        buscaABB( raiz->dir, sbusca);
    }
}

int main() {
	FILE *arquivo;
	char linhaLida[TAM_LINHA_MAX];

	NO_CAD *raiz=NULL;
	// definido em cadastro.h	
	REGISTRO reg;

    char strbusca[100];

	arquivo = fopen("/home/paiva/Downloads/Unifesp-24r.csv","r");
	if( !arquivo ) {
		printf("Erro de abertura de arquivo.\n\n");
		return -1;
		}
		
	while( fgets( linhaLida, TAM_LINHA_MAX, arquivo) ) {      
		pegaCampo(linhaLida, Id_SERVIDOR_PORTAL, reg.id);
		pegaCampo(linhaLida, NOME, reg.nome);
		pegaCampo(linhaLida, UORG_LOTACAO, reg.lotacao);
		pegaCampo(linhaLida, FUNCAO, reg.funcao);
		pegaCampo(linhaLida, DESCRICAO_CARGO, reg.cargo);
		
        raiz = insereNo( raiz, reg);
		}

	fclose(arquivo);

    //imprimeOrdenado(raiz);

    printf("\nEntre com nome completo: ");
    fgets( strbusca, 100, stdin);
    strbusca[ strlen(strbusca)-1 ] = '\0';

    buscaABB(raiz,strbusca);

	return 0;
}
