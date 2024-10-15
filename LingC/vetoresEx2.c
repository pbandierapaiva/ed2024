/* Trabalhando com vetores, Exercício 2
*/

#include <stdio.h>

#define MAX 100

int main() {
	int n, m;
	int i, j, k;
	int vetN[MAX], vetM[MAX], vetRes[MAX*2];	

	printf("Entre com N: ");
	scanf("%d", &n);
	printf("Entre com M: ");
	scanf("%d", &m);
	if( m>100 || n>100 ) {
		printf("Limite máximo de tamanho: %d\n", MAX);
		printf("Execução terminada.\n\n");
		return -1;
		}
	printf("Lendo dois vetores de tamanho %d e %d\n",n,m);
	
	// Leitura de dados de vetores
	for(i=0; i<n; i++) {
		printf("N %d> ",i);
		scanf("%d", &vetN[i]);
		if(i>0) {
			if( vetN[i]<=vetN[i-1] ){
				printf("Entrada de dados tem que ser ordenada.\n\n");
				return -1;
				}
			}
		}
	for(i=0; i<m; i++) {
		printf("M %d> ",i);
		scanf("%d", &vetM[i]);
		if(i>0) {
			if( vetM[i]<=vetM[i-1] ){
				printf("Entrada de dados tem que ser ordenada.\n\n");
				return -1;
				}
			}
		}

	i = 0; //índice do vetor Resultante
	j = 0; // N
	k = 0; // M

	while( j<n || k<m ){
		if( j==n ) { //chegou no fim de vetN
			while(k<m){
				vetRes[i] = vetM[k];
				i++; k++;
				}
			break;
			}
		if( k==m ) { //chegou no fim de vetM
			while(j<n){
				vetRes[i] = vetN[j];
				i++; j++;
				}
			break;
			}
		if( vetN[j] == vetM[k] ) {
			vetRes[i] = vetN[j];
			i++; j++; k++;
			}
		else {
			if( vetN[j] > vetM[k] ) {
				vetRes[i] = vetM[k];
				i++; k++;
				}
			else {
				vetRes[i] = vetN[j]; // vetN[j] < vetM[k]
				i++; j++;
				}		
			}
		}

	for(j=0; j<i; j++) {
		printf("%d\n", vetRes[j]);
		}
	

	return 0;
}	



