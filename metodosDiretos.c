#include "metodosDiretos.h"

void imprimirMatriz(double** matriz, int ordem){

	for(int i = 0; i < ordem; i++){
		for(int j = 0; j < ordem; j++){

			printf("%10.5lf",matriz[i][j]);
		}

		printf("\n");
	}
}

void imprimirVetor(double* vet, int ordem){
	
	for (int i = 0; i < ordem; i++){
		printf("%.5lf\n",vet[i]);
	}
}


void eliminacaoGauss(FILE *matriz, FILE *vetorB, int ordem){

    double **A = malloc(ordem * sizeof(double *));
    double *B = malloc(ordem * sizeof(double *));

   
    for (int i = 0; i < ordem; i++)
    {
        
        *(A + i) = malloc(ordem * sizeof(double));
        fscanf(vetorB, "%lf", &B[i]);

        for (int j = 0; j < ordem; j++)
            fscanf(matriz, "%lf", &A[i][j]);
    }

    //ETAPA DE ESCALONAMENTO
    for(int k = 0; k < ordem - 1; k++){
    	/*RODA N - 1 VEZES POR QUE EU NÃO PRECISO 
    	ESCALONAR ATÉ A ÚLTIMA COLUNA PARA TER UMA 
    	MATRIZ TRIANGULAR SUPERIOR. OS 0'S VÃO ATÉ A PENÚLTIMA COLUNA. N É O TAMANHO HUMANO; N - 1 TAMANHO DA MÁQUINA;
    	< N - 1 -> PERCORRA ATÉ A PENÚLTIMA LINHA */
    	

        //Se A[k][k] é zero, então a matriz dos coeficiente é singular
        //det A = 0
        if(A[k][k] == 0){
            printf("A matriz dos coeficientes é singular\n");
            //return;
        }else{
                #pragma omp parallel for
                //realiza o escalonamento
                for(int m = k + 1; m < ordem; m++){
                         /*Esse loop defini o multiplicador da linha*/
                        double F = 0;
                        //printf("Thread id: %d - m: %d\n",omp_get_thread_num(),m);
                        #pragma omp critical
                            F = -A[m][k] / A[k][k];
                            A[m][k] = 0; //evita uma iteração
                            B[m] = B[m] + F * B[k];
                        
                        //#pragma single
                        for(int l = k + 1; l < ordem; l++){
                            //Atualização da linha, matriz[k][l] é o elemento da linha do pivô
                           //printf("[Single] Thread id: %d - m: %d\n",omp_get_thread_num(),m);
                           //#pragma omp critical
                            A[m][l] = A[m][l] + F * A[k][l];
                        }
                    
                   
                }
            
                
            
            
        }
    }

    double* x = alocarVetor(ordem);

    //ETAPA DE RESOLUÇÃO DO SISTEMA
    
    for (int i = ordem - 1; i >= 0; i--){
        x[i] = B[i];
        #pragma omp parallel for
        for(int j = i + 1; j < ordem; j++){
            #pragma omp critical
            x[i] = x[i] - x[j] * A[i][j];
        }
        x[i] = x[i] / A[i][i];
    }
     
    int cont = 0;

    printf("\nVetor solucao - Eliminacao de Gauss\n");
    while(cont < ordem){

    	printf("x[%d] = %.5lf\n",cont,x[cont]);
    
   		cont++;
    }
   
    printf("\n");
    free(x);
    free(B);
    liberarMatriz(A,ordem);

}