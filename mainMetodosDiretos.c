#include "metodosDiretos.c"

void randomizaArquivo(FILE *arquivoA, FILE *arquivoB, int tamanhoMatriz);


int main(int argc, char *argv[]){

	//int ordem, esc,op = 100;

	int ordem = atoi(argv[1]);

	/*srand(time(NULL));

    FILE *matrizA = fopen("A.txt", "w"),
         *vetorB = fopen("B.txt", "w");

    randomizaArquivo(matrizA, vetorB, ordem);

    fclose(matrizA), fclose(vetorB);*/

	FILE *A = fopen("A.txt", "r"), *B = fopen("B.txt", "r"); // carrega arquivos


	double *vetorSolucao = alocarVetor(ordem);

	eliminacaoGauss(A, B, ordem);
















	fclose(A), fclose(B), free(vetorSolucao);
	

	

	return 0;
}

void randomizaArquivo(FILE *arquivoA, FILE *arquivoB, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivoA, "%lf ", (double)(rand() % 10000));
        }
        fprintf(arquivoA, "\n");
    }

    for (int i = 0; i < tamanhoMatriz; i++)
        fprintf(arquivoB, "%lf\n", (double)(rand() % 10000));
}