
#include <stdio.h>

int main() {

	int intA;
	unsigned int b;
	char c;
	int vetorInt[20];
	
	typedef struct  {
		int x;
		int y;
		} COORDENADA;
		
	COORDENADA vcoord;

	printf("Tamanho do char:     %ld\n", sizeof(char));
	printf("Tamanho do int:      %ld\n", sizeof(intA));
	printf("Tamanho do long int: %ld\n", sizeof(long int));
	printf("Tamanho do float:    %ld\n", sizeof(float));
	printf("Tamanho do double:   %ld\n", sizeof(double));
	printf("Tamanho do vetor com 20 inteiros: %ld\n", sizeof(vetorInt));	
	printf("Tamanho do tipo COORDENADA: %ld\n", sizeof( vcoord ));	
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









