#include <stdio.h>

#define TAM 10

int main() {

	char texto[TAM];

	int c, i=0;
	
	
	printf("Entre com cadeia de caracteres: ");
	
	while(i < TAM-1) {
		c = getchar();
		if( c=='\n' )
			break;
		texto[ i ] = c;
		i++;
		}
	texto[ i ] = '\0';
	
	printf("Texto entrado: %s \n", texto);
	
	return 0;
}
