// Le arquivo de cadastro de servidores da UNIFESP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

#define TAM_LINHA_MAX 1000

#define PEDACO	100

void pegaCampo(char *, int , char *);


int main() {
	FILE *arquivo;
	char buffer[TAM_LINHA_MAX];
	int conta=0, alocado=0;
	
	// definido em cadastro.h	
	REGISTRO reg;
	
	REGISTRO *vetreg;

	
	arquivo = fopen("/homepub/pub/ed/UNIFESP.csv","r");
	if( !arquivo ) {
		printf("Erro de abertura de arquivo.\n\n");
		return -1;
		}
		
	alocado = PEDACO;
	vetreg = malloc( alocado * sizeof(REGISTRO) );
	if(!vetreg) {
		printf("Erro de alocação de memória.\n\n");
		return -1;
		}
	
	
	
	while( fgets( buffer, TAM_LINHA_MAX, arquivo) ) {
		if( conta >= alocado ) {
			alocado = alocado + PEDACO;
			vetreg = realloc( vetreg, alocado * sizeof(REGISTRO) );
			printf("Realocando %d REGISTROs\n", alocado);	
			}
		
		pegaCampo(buffer, Id_SERVIDOR_PORTAL, vetreg[conta].id);
		pegaCampo(buffer, NOME, vetreg[conta].nome);
		pegaCampo(buffer, UORG_LOTACAO, vetreg[conta].lotacao);
		pegaCampo(buffer, FUNCAO, vetreg[conta].funcao);
		
		conta++;
		}



	fclose(arquivo);
	return 0;
}
