// Le arquivo de cadastro de servidores da UNIFESP
// Cria lista ligada com dados básicos dos servidores e
// localização do registro no CSV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"
#include "util.h"
#include "cadLL.h"

int main() {
	FILE *arquivo;
	char linhaLida[TAM_LINHA_MAX];
    REGISTRO reg;
	int conta=0;

    NOcadLL *raiz=NULL;

    arquivo = fopen("/home/pub/ed/UNIFESP.csv","r");
	if( !arquivo ) {
		printf("Erro de abertura de arquivo.\n\n");
		return -1;
		}

    
    while( fgets( linhaLida, TAM_LINHA_MAX, arquivo) ) { 
		// if(!conta%1000)
			printf("\r%d",conta++);
		// conta++;	

     	pegaCampo(linhaLida, Id_SERVIDOR_PORTAL, reg.id);
		pegaCampo(linhaLida, NOME, reg.nome);
		pegaCampo(linhaLida, UORG_LOTACAO, reg.lotacao);
		pegaCampo(linhaLida, FUNCAO, reg.funcao);       

        insereNo( &raiz, reg);
		}

	imprimeLista(raiz);
    fclose(arquivo);
	return 0;
}
