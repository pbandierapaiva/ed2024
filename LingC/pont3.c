// Implementação de ponteiros Ex 3

#include <stdio.h>

	
int main(){
	int s[100];
	int *p;
	char *cp;
	
	s[0] = 0;
	s[1] = 2000;
	s[2] = 3000;
	
	p = s;
	
	cp = (char *) p;
	
	printf("Endereço do vetor 's': %ld\n", (long) p );
	printf("Conteúdo: %d\n", *p);	

	p++;
	printf("Endereço do vetor 's[1]': %ld\n", (long) p );
	printf("Conteúdo: %d\n", *p);

	p++;
	printf("Endereço do vetor 's[2]': %ld\n", (long) p );
	printf("Conteúdo: %d\n", *p);
	
	printf("Endereço contido no cp: %ld  Valor: %u \n", (long) cp,  *cp ); 
	cp++;
	printf("Endereço contido no cp: %ld  Valor: %u \n", (long) cp,  *cp ); 	
	cp++;
	printf("Endereço contido no cp: %ld  Valor: %u \n", (long) cp,  *cp ); 	
	cp++;
	printf("Endereço contido no cp: %ld  Valor: %u \n", (long) cp,  *cp ); 	
	}





