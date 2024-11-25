## Arquivo para compilação de exemplos
all: cadListaLigada

cadListaLigada : cadListaLigada.o util.o cadLL.o
	gcc cadListaLigada.c util.c cadLL.c -o cadListaLigada
cadListaLigada.o : cadListaLigada.c cadastro.h util.h cadLL.h
	gcc -c cadListaLigada.c

cadLL.o : cadLL.c cadastro.h cadLL.h
	gcc -c cadLL.c

util.o : util.c util.h
	gcc -c util.c

clean:
	rm *.o
