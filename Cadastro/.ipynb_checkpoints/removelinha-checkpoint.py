#!/usr/bin/python

nLinhaApagar = 300;

arq = open("/home/paiva/Cadastro.csv")
sai = open("/home/paiva/CadModPy.csv", "w");

linhas = arq.readlines()

del linhas[nLinhaApagar]

sai.writelines(linhas)

arq.close()
sai.close()


