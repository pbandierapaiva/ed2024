// Implementação de ponteiros Ex 1

#include <stdio.h>



void LeInteiro( int *p ) {
	
	printf("Entre com a: ");
	scanf("%d", p );

	}
	
	
int main(){
	int a=0;
	
	LeInteiro(&a);
	printf("Valor de a: %d\n", a);
	
	}





