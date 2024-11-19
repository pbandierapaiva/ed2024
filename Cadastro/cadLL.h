// cadLL.h

typedef struct noReg {
    REGISTRO   registro;
    struct noReg *proximo;
} NOcadLL;

void insereNo( NOcadLL **, REGISTRO  );
void imprimeLista( NOcadLL *);
void imprimeReg( NOcadLL * );
NOcadLL *buscaNo( NOcadLL *, char * );
NOcadLL *buscaLista( NOcadLL *, char * );
int tamanhoLista(NOcadLL * );

