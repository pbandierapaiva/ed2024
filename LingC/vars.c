
#include <stdio.h>

int main() {

	int intA;
	unsigned int b;
	char c;

	printf("Tamanho do char:     %ld\n", sizeof(char));
	printf("Tamanho do int:      %ld\n", sizeof(intA));
	printf("Tamanho do long int: %ld\n", sizeof(long int));
	printf("Tamanho do float:    %ld\n", sizeof(float));
	printf("Tamanho do double:   %ld\n", sizeof(double));
	
	printf("--------------------------\n\n");
	
	b = -2;
	// c = 260; //ERRADO!!
	// c = e;   // ERRADO - não existe 'e' definido
	

	
	printf("A variável \"unsigned int\" b vale: %u\n", b);
	printf("A variável \"char\" c vale: %d\n", c);	
	
	printf("--------------------------\n\n");
	printf("Exemplo de \"for\": \n");
	
	for(int i=0; i<10 ; i++)          // for(range(10))
		printf("no loop %d\n", i);
	
		
}









