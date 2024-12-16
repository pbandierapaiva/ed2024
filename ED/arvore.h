typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} NO;

NO *busca(NO *, int);
NO *pai(NO *, NO *);
NO *criaNo(int );
NO *insereNo(NO *, int  );
NO *proximo(NO *, NO *);
void imprimeERD(NO *);
void imprimeDRE(NO *);
int altura(NO *);
int FB(NO *);
NO *removeNo( NO * );
void removeNoVal(NO **, int );
NO *busca( NO *, int  );
void imprimeNivel(NO *, int , int );
int profundidade(NO *, NO *);

NO *rotacaoDireita( NO * );
NO *rotacaoDuplaDireita( NO * );
NO *rotacaoEsquerda( NO * );
NO *rotacaoDuplaEsquerda( NO * );



