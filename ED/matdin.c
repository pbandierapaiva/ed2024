// Exemplo de matriz com dimensõesalocadas dinamicamente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSEQ 100000

#define MATCH 2
#define GAP_PENALTY -1

int pega(int *mat, int nlin, int ncol, int l, int c) {
    if( l>= nlin || c>=ncol ) {
        printf("Erro - fora de escopo (%d,%d)\n",nlin,ncol);
        exit(-1);
    }
    if( l<0 || c<0 ){
        return 0;
    }
    return mat[ l*ncol + c ];
}

void coloca(int *mat, int nlin, int ncol, int l, int c, int num) {
    if( l>= nlin || c>=ncol || l<0 || c<0 ) {
        printf("Erro - fora de escopo (%d,%d)\n",nlin,ncol);
        exit(-1);
    }
    mat[ l*ncol + c ] = num;
}

void imprime(int *mat, char *a, char *b) {
    int nlin, ncol;
    nlin = strlen(a);
    ncol = strlen(b);

    for(char *p=b; *p!='\0'; p++) {
        printf("\t%c", *p);
    }
    printf("\n");

    for(int i=0; i<nlin; i++){
        printf("%c\t", a[i]);
        for(int j=0; j<ncol; j++) {
            printf("%d\t", pega(mat,nlin,ncol, i, j) );
        }
        printf("\n");
    }
    printf("\n\n");
}


int main() {
    int lin,col;
    int i,j;
    char entrada[10];
    int *matriz=NULL;
    char seqA[MAXSEQ], seqB[MAXSEQ];
    int v1, v2, v3, res;

    printf("Entre com seqA: \n");
    fgets(seqA, MAXSEQ, stdin);
    seqA[strlen(seqA)-1] = '\0';
    printf("Entre com seqB: \n");
    fgets(seqB, MAXSEQ, stdin);
    seqB[strlen(seqB)-1] = '\0';
   
    lin = strlen(seqA);
    col = strlen(seqB);
    printf("Criando matriz %d X %d\n", lin, col);

    matriz = malloc( sizeof(int) * lin * col);

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            coloca(matriz, lin, col, i, j, 0);
        }
    }

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            // acerto/erro
            if( seqA[i]==seqB[j] )
                v1=2;
            else
                v1=0;
            v1 += pega( matriz, lin, col, i-1, j-1 ) ;  // H(i-1, j-1)
            // deleção
            v2 = pega( matriz, lin, col, i-1, j ) + GAP_PENALTY ; // H(i-1, j)
            //inserção
            v3 = pega( matriz, lin, col, i, j-1 ) + GAP_PENALTY ; // H(i, j-1)

            if(v1>v2 && v1>v3){
                res = v1;
            }
            else {
                if(v2>v3)
                    res = v2;
                else
                    res = v3;
            }
            if(res<0) res=0;

            coloca(matriz, lin, col, i, j, res);
        }
    }

    imprime(matriz, seqA, seqB);
    
}

