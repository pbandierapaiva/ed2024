// Implementação de ponteiros Ex 1

#include <stdio.h>

	
int main(){
	char s[100];
	char *p;
	
	printf("Entre com string: ");
	fgets( s, 100, stdin);
	
	p = s;
	
	while( *p!='\0' ){
		if(*p==' ')
			printf("\n");
		else
			printf("%c", *p);
		p++;
		}
	}





