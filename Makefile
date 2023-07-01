ordem = 10

all:	
	clear
	gcc -o geraArquivos geraArquivos.c -Wall
	./geraArquivos $(ordem)
	gcc -o main -fopenmp main.c -Wall
	./main $(ordem)


