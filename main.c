#include "metodos.c"

int main(int argc, char *argv[])
{
	int ordem = atoi(argv[1]);

	FILE *A = fopen("A.txt", "r"); // carrega arquivo com matriz A

	double *b = alocarVetor(ordem);

	double *vetorSolucao = alocarVetor(ordem);

	printf("\nDigite o vetor de termos independentes:\n");

	for (int i = 0; i < ordem; ++i)
	{
		printf("b[%d] = ", i);
		scanf("%lf", &b[i]);
	}

	eliminacaoGauss(A, b, ordem);

	fclose(A);
	free(b);
	free(vetorSolucao);

	return 0;
}
