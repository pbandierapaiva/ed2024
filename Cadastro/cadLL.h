// cadLL.h

typedef struct noReg {
    REGISTRO   registro;
    struct noReg *proximo;
} NOcadLL;

void insereNo( NOcadLL **, REGISTRO  );
void imprimeReg( NOcadLL * );
NOcadLL *buscaNo( NOcadLL *, char * );
NOcadLL *buscaLista( NOcadLL *, char * );
int tamanhoLista(NOcadLL * );

void imprimeLista( NOcadLL *);
void imprimeListaInvertida( NOcadLL *);

