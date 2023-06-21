all:	
	clear
	gcc -o geraArquivos geraArquivos.c
	./geraArquivos 10
	clear
	gcc -o main main.c -Wall
	./main 10