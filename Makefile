ordem = 1000

all:	
	clear
	gcc -o geraArquivos geraArquivos.c -Wall
	gcc -o main -fopenmp main.c -Wall
	time ./main $(ordem)