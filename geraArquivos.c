#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizaArquivo(FILE *arquivo, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivo, "%lf ", (double)(rand() % 10000));
        }
        fprintf(arquivo, "\n");
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    FILE *matrizA = fopen("A.txt", "w"),
         *vetorB = fopen("B.txt", "w");

    randomizaArquivo(matrizA, atoi(argv[1])),
        randomizaArquivo(vetorB, atoi(argv[1]));

    fclose(matrizA),
        fclose(vetorB);

    return 0;
}