// cadLL.h

typedef struct noReg {
    REGISTRO   registro;
    struct noReg *proximo;
} NOcadLL;

void insereNo( NOcadLL **, REGISTRO  );
void imprimeLista( NOcadLL *);
