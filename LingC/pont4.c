// Implementação de ponteiros - Centraliza texto

#include <stdio.h>

int tamanhoString( char *s ) {
	int i=0;
	char *p;
	
	p = s;
	
	while( *p!='\0' && *p!='\n' ) {
		i++;
		p++;
		}
	return i;
}

void centraliza(char *ent, char *sai, int t) {
	int espacosantes=0;
	char *pe, *ps;
	
	pe = ent;
	ps = sai;
	
	espacosantes =  ( t - tamanhoString(ent) )/2;
	if(espacosantes<0) {
		printf("Espaço insuficiente\n");
		return;
		}
	printf("espaçoantes= %d\n",espacosantes);
	for(int i=0; i <espacosantes; i++) {
		*ps = ' ';
		ps++;
		}
	
	while( *pe != '\0' && *pe != '\n') {
		*ps = *pe;
		ps++;
		pe++;
		}
		
	for(int i=0; i< (t - espacosantes - tamanhoString(ent)); i++) {
		*ps = ' ';
		ps++;
		}
	*ps = '\0';
	}
	
int main(){
	char entrada[100], saida[100];
	int tam=0;
	
	printf("Entre com string: ");
	fgets( entrada, 100, stdin);
	printf("Tamanho do continente: ");
	scanf("%d", &tam);
	printf("Tamanho do str: %d\n", tamanhoString(entrada));
	
	centraliza(entrada, saida, tam);
	
	printf("X %s X\n", saida);
	}





