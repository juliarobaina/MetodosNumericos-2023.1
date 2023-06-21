#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *alocarVetor(int tam)
{

    double *novo = (double *)calloc(tam, sizeof(double));

    return novo;
}

double **alocarMatriz(int ordem)
{

    double **novo = (double **)calloc(ordem, sizeof(double *));

    for (int i = 0; i < ordem; i++)
    {
        novo[i] = alocarVetor(ordem);
    }

    return novo;
}

void liberarMatriz(double **matriz, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void eliminacaoGauss(FILE *matriz, double *vetorB, int ordem)
{

    double **A = malloc(ordem * sizeof(double *));

    for (int i = 0; i < ordem; i++)
    {
        *(A + i) = malloc(ordem * sizeof(double));
        for (int j = 0; j < ordem; j++)
        {
            fscanf(matriz, "%lf", &A[i][j]);
        }
    }

    // eliminação de Gauss com Pivoteamento Total

    // ETAPA DE ESCALONAMENTO
    for (int k = 0; k < ordem - 1; k++)
    {
        /*RODA N - 1 VEZES POR QUE EU NÃO PRECISO
        ESCALONAR ATÉ A ÚLTIMA COLUNA PARA TER UMA
        MATRIZ TRIANGULAR SUPERIOR. OS 0'S VÃO ATÉ A PENÚLTIMA COLUNA. N É O TAMANHO HUMANO; N - 1 TAMANHO DA MÁQUINA;
        < N - 1 -> PERCORRA ATÉ A PENÚLTIMA LINHA*/

        // Se A[k][k] é zero, então a matriz dos coeficiente é singular
        // det A = 0
        if (A[k][k] == 0)
        {
            printf("A matriz dos coeficientes é singular\n");
            return;
        }
        else
        {
            // realiza o escalonamento
            for (int m = k + 1; m < ordem; m++)
            {
                // Esse loop defini o multiplicador da linha
                double F = -A[m][k] / A[k][k];
                A[m][k] = 0; // evita uma iteração
                vetorB[m] = vetorB[m] + F * vetorB[k];
                for (int l = k + 1; l < ordem; l++)
                {
                    // Atualização da linha, matriz[k][l] é o elemento da linha do pivô
                    A[m][l] = A[m][l] + F * A[k][l];
                }
            }
        }
    }

    double *x = alocarVetor(ordem);

    // ETAPA DE RESOLUÇÃO DO SISTEMA
    for (int i = ordem - 1; i >= 0; i--)
    {
        x[i] = vetorB[i];
        for (int j = i + 1; j < ordem; j++)
        {
            x[i] = x[i] - x[j] * A[i][j];
        }

        x[i] = x[i] / A[i][i];
    }

    printf("\nVetor solucao - Eliminacao de Gauss\n");

    for (int i = 0; i < ordem; i++)
    {
        printf("x[%d] = %lf\n", i, x[i]);
    }
    free(A);
    free(x);
}
