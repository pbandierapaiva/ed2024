#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 20

void strip(char *st) {
	for(int i=0;i<TAM;i++) 
		if(st[i]=='\n')
			st[i]='\0';
	}

void capitaliza(char *st) {
	st[0] = toupper(st[0]);
	}

int main() {
	char nome[TAM], snome[TAM];
	char nomecompleto[2*TAM+1];
	
	printf("Entre com seu nome: ");
	fgets(nome, TAM, stdin);
	strip(nome);
	capitaliza(nome);
	
	printf("Entre com seu sobrenome: ");
	fgets(snome, TAM, stdin);	
	strip(snome);
	capitaliza(snome);
			
	strcpy( nomecompleto, nome );
	strcat( nomecompleto, " " );
	strcat( nomecompleto, snome);
	
	printf("Nome completo: %s\n", nomecompleto);
	
	

	
	return 0;
}
