// Programa que aloca dinamicamente um vetor de tamanho definido pelo usuário

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	float *vetor;
	float *p;
	
	
	printf("Entre com quantidade de valores: ");
	scanf("%d", &n);
	
	vetor = malloc( n * sizeof(float) );
	if( !vetor ) {   // vetor = 0 alocação dinâmica falhou
		printf("Erro de alocação de memória\n\n");
		exit(-1);
		}
	
	//// Lendo diretamente no ponteiro vetor	
	for( int i=0; i<n; i++) {
		printf("%d > ", i);
		scanf("%f", &vetor[i] );
		}		
	
	//// Utilizando ponteiro p:	
	// p = vetor;
	// for( int i=0; i<n; i++) {
	// 	scanf("%f", p);
	// 	p++;
	// 	}

	//// Imprimindo diretamente do ponteiro vetor
	
	for( int i=0; i<n; i++) 
		printf("%f\n", vetor[i] );
	
	//// Utilizando ponteiro p:
	
	// p = vetor;
	// for( int i=0; i<n; i++, p++)
	//	printf("%f\n", *p );
	
	free(vetor);
}













	
