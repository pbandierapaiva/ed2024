// Implementação de binnomial

#include <stdio.h>

int fat(int);
int binomial(int, int);

int main() {
	int a,b;
	
	printf("Entre com valores de M e P para binomial: ");
	scanf("%d %d", &a, &b);
	
	printf("M: %d\nP: %d\n\n", a,b);
	
	printf("O valor do binomial é: %d\n", binomial(a,b) );
	
	return 0;

}


int fat( int x ){
	if(x<=1) return 1;
	return x * fat(x-1);
	}

int binomial(int m, int p){
	if(m>=0 && p>=0 && p<=m)
		return fat(m) / ( fat(p) * fat(m-p) ) ;
	return 0;
	}
	
	
	
	
	
	
	
