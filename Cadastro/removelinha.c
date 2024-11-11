#include <stdio.h>

int main() {
    FILE *arquivo, *saida;
    int nLinha=0;
    int lido;
    
    int nLinhaApagar = 300;

    arquivo = fopen("/home/paiva/Cadastro.csv", "r");
    saida = fopen("/home/paiva/CadModC.csv", "w");

    while( !feof(arquivo) ) {
        if( nLinha == nLinhaApagar ){ //linha a apagar
            do {
                lido = fgetc( arquivo );
            } while(lido!='\n' && !feof(arquivo) );
        }
        do {
                lido = fgetc( arquivo );
                fputc( lido, saida);
            } while(lido!='\n' && !feof(arquivo) );
        nLinha++;
    }
    fclose(arquivo);
    fclose(saida);
}