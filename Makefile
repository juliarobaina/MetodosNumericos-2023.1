all:	
	gcc -o geraArquivos geraArquivos.c
	./geraArquivos 10
	gcc -o main main.c -Wall
	clear
	./main 10