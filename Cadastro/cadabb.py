

def leCSV():
    arq = open("/home/paiva/Downloads/Unifesp-24r.csv","r")

    linha = arq.readline()

    while(linha):
        campos = linha.strip().split(";")
        id = campos[0][1:-1]
        nome = campos[1][1:-1]
        lotacao = campos[16][1:-1]
        cargo = campos[4][1:-1]
        func = campos[11][1:-1]




        linha = arq.readline()



class No:
    def __init__(self, pDado=None):
        self.dado = pDado
        self.esq = None
        self.dir = None

    def insere(self, pDado):
        if self.dado==None:
            self.dado = pDado
        if self.dado > pDado:
            if self.esq: # Não é nulo
                self.esq.insere(pDado)
            else:
                self.esq = No(pDado)
        elif self.dado < pDado:
            if self.dir:
                self.dir.insere(pDado)
            else:
                self.dir = No(pDado)
    
    def imprimeERD(self):
        if self.esq:
            self.esq.imprimeERD()
        print( self.dado )
        if self.dir:
            self.dir.imprimeERD()
    
    def altura(self):
        hEsq = hDir=0
        if self.dado==None:
            return 0
        if self.esq:
            hEsq = self.esq.altura()
        if self.dir:
            hDir = self.dir.altura()
        if hEsq > hDir:
            return hEsq+1
        else:
            return hDir+1

    def FB(self):
        if self.dado==None:
            return 0
    
        if self.dir!=None:
            aDir = self.dir.altura()
        else:
            aDir = 0
        if self.esq!=None:
            aEsq = self.esq.altura()
        else:
            aEsq = 0
        return aDir - aEsq

    def rotacaoDireita(self):

        aux = self.dado
        self.dado = self.esq.dado
        self.esq.dado = aux

        ta = self.esq.esq
        tb = self.esq.dir
        tc = self.dir
        q = self.esq

        self.dir = q
        self.esq = ta
        q.esq = tb
        q.dir = tc

    def rotacaoEsquerda(self):

        aux = self.dado
        self.dado = self.dir.dado
        self.dir.dado = aux

        tc = self.dir.dir
        tb = self.dir.esq
        ta = self.esq
        q = self.dir

        self.esq = q
        self.dir = tc
        q.esq = ta
        q.dir = tb

    def rotacaoDuplaDireita(self):
        self.esq.rotacaoEsquerda()
        self.rotacaoDireita()
    
    def rotacaoDuplaEsquerda(self):
        self.dir.rotacaoDireita()
        self.rotacaoEsquerda()        

arvore = No()
arvore.insere(6)
arvore.insere(4)
arvore.insere(9)
arvore.insere(3)
arvore.insere(5)

print("FB antes: ",arvore.FB())
arvore.rotacaoDuplaDireita()
print("FB depois: ",arvore.FB())

# arvore.imprimeERD()
print("Altura da árvore: ", arvore.altura() )


    







