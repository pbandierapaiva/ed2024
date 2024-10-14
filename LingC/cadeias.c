#include <stdio.h>

#define TAM 10

int main() {

	char texto[TAM];
	char outrot[] = "Outro String";
	
	printf("Entre com cadeia de caracteres: ");
	fgets( texto, TAM, stdin);
	printf("Texto entrado: %s \nOutro texto: %s\n", texto, outrot);
	
	return 0;
}
