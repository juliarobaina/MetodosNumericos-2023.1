#ifndef _METODOS_
#define _METODOS_
#include <stdio.h>

void eliminacaoGauss(FILE *matriz, double *vetorB, int ordem);

void imprimirMatriz(double **A, int ordem);
void imprimirVetor(double *vet, int ordem);

double *alocarVetor(int tam);
double **alocarMatriz(int ordem);
void liberarMatriz(double **matriz, int ordem);

#endif
