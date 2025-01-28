

def leCSV():
    arvore = No()

    arq = open("/home/paiva/Downloads/Unifesp-24r.csv","r")
    # arq = open("/home/pub/ed/Cadastro.csv")
    linha = arq.readline()

    i=0
    while(linha):
        campos = linha.strip().split(";")
        id = campos[0][1:-1]
        nome = campos[1][1:-1]
        lotacao = campos[16][1:-1]
        cargo = campos[4][1:-1]
        func = campos[11][1:-1]

        arvore.insere( Registro(id, nome, lotacao, cargo, func))
        linha = arq.readline()
        i+=1

    return arvore

class Registro:
    def __init__(self, pId, pNome, pLotacao, pCargo, pFuncao):
        self.id = pId
        self.nome = pNome
        self.lotacao = pLotacao
        self.cargo = pCargo
        self.funcao = pFuncao
    def __gt__(self, d):
        return self.nome > d.nome
    def __eq__(self, d):
        return self.nome == d.nome
    def __lt__(self, d):
        return self.nome < d.nome
    def __str__(self):
        return self.nome +"\n"+self.lotacao +"\n"+self.cargo+"\n"+self.funcao
   

class No:
    def __init__(self, pDado=None):
        if type(pDado)==Registro:
            self.dado = pDado
        else:
            self.dado=None
        self.esq = None
        self.dir = None

    def insere(self, pDado):
        if type(pDado)!=Registro:
            raise TypeError("Somente insira dados do tipo Registro")
        if type(self.dado)!=Registro:
            self.dado = pDado
            return
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
        else:
            return

        ## Mantém árvore AVL
        fb = self.FB()
        if fb>1:
            if  self.dir.FB() >= 0:
                self.rotacaoEsquerda()
            else:
                self.rotacaoDuplaEsquerda()
        if fb<-1:
            if  self.esq.FB() <= 0:
                self.rotacaoDireita()
            else:
                self.rotacaoDuplaDireita()
   
    def imprimeERD(self):
        if self.esq:
            self.esq.imprimeERD()
        print( self.dado )
        if self.dir:
            self.dir.imprimeERD()
    
    def buscaNome(self, pNome):
        if self.dado.nome == pNome:
            print(self.dado)
            return True
        encontrou = False
        if self.esq:
            encontrou = self.esq.buscaNome(pNome)
            if encontrou: return True
        if self.dir:
            encontrou = self.dir.buscaNome(pNome)
            if encontrou: return True
   
    def altura(self):
        hEsq = hDir=0
        if type(self.dado)!=Registro:
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
        if type(self.dado)!=Registro:
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
        if self.esq==None:
            return
        self.esq.rotacaoEsquerda()
        self.rotacaoDireita()
    
    def rotacaoDuplaEsquerda(self):
        if self.dir==None:
            return
        self.dir.rotacaoDireita()
        self.rotacaoEsquerda()   

    def ehAVL(self):
        fb = self.FB()
        if(fb>1 or fb<-1):
            return False
        avl = True
        if self.esq:
            avl = self.esq.ehAVL()
        if self.dir and avl:
            avl = self.dir.ehAVL()
        return avl

arvCad = leCSV()

# arvCad.imprimeERD()
print("Altura da árvore: ", arvCad.altura() )
print("É AVL") if  arvCad.ehAVL() else  print("Não é AVL")     

arvCad.buscaNome("PAULO BANDIERA PAIVA")






