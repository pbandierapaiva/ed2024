// Implementação de soma de matrizes

#include <stdio.h>

#define MAXLIN 100
#define MAXCOL 100



int main(){
	int a[MAXLIN][MAXCOL], b[MAXLIN][MAXCOL], soma[MAXLIN][MAXCOL];
	int nlin, ncol;
	int i,j;

	printf("Entre com número de linhas e colunas: ");
	scanf("%d %d", &nlin, &ncol);
	if( nlin > MAXLIN  || ncol > MAXCOL ){
		printf("Valores entrados superiores aos limites %d e %d\n",MAXLIN,MAXCOL);
		return -1;
		}
	
	printf("Entre com valores da matriz A:\n");
	for(i=0; i<nlin; i++) {
		for(j=0; j<ncol; j++){
			printf("%d, %d > ",i,j);
			scanf("%d", &( a[i][j] ) );
		}
	}
	printf("Entre com valores da matriz B:\n");
	for(i=0; i<nlin; i++) {
		for(j=0; j<ncol; j++){
			printf("%d, %d > ",i,j);
			scanf("%d", &( b[i][j] ) );
		}
	}	


	// executando a soma
	for(i=0; i<nlin; i++) {
		for(j=0; j<ncol; j++){
			soma[i][j] = a[i][j] + b[i][j];
		}
	}	
	

	printf("Imprimindo matriz soma\n");
	for(i=0; i<nlin; i++) {
		printf("\n");
		for(j=0; j<ncol; j++){
			printf("%d\t",soma[i][j]);
		}
	}
	printf("\n");

	return 0;	
}


