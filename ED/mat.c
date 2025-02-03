// Exemplo de matriz com dimensões pré-definidas


#include <stdio.h>
#include <stdlib.h>


int main() {
    int i=0,j=0,k=0, cont=0;
    int mat[3][3][3];

    for(i=0;i<3;i++) {
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                mat[i][j][k] = cont;
                cont++;
            }
        }
    }

    for(i=0;i<3;i++) {
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                printf("%d\t", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n-----\n");
    }

}