#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
		
	double Mat[51][51], A[51], B[51], C[51];
	int i, j, k, meses, dim;

	/*zerando a matriz*/
	for(i=1;i<=50;i++){
		B[i] = 0;
		for(j=1;j<=50;j++){
			Mat[i][j] = 0;
		}
	}

	/* Programa */
	printf("Forneca a ordem a dimensao de sua matriz quadrada\n");
	scanf("%d",&dim);

	printf("Digite o numero de meses\n");
	scanf("%d",&meses);
	printf("Forneca os dados em ordem cronologica crescente\n");

	for(k=1;k<=meses;k++){
		printf("Consumo[%d]: ",k);
		scanf("%lf", &C[k]);
	}
	for(i=1;i<=dim;i++){
		for(j=1;j<=dim;j++){
			for(k=1;k<=meses;k++){
				if(i==j)
					Mat[i][j] = Mat[i][j] + k*k;
				else
					Mat[i][j] = Mat[i][j] + k;
			}
		}
	}


	/*impressao da mat*/

	printf("\n");
	
	for(i=1;i<=dim;i++){
		for(j=1;j<=dim;j++){
			printf("[%f]  ", Mat[i][j]);
		}
		printf("\n");
	}
			 
	/*calculo do vetor B*/
	for(i=1;i<=dim;i++)
		for(k=1;k<=meses;k++)
			B[i] = B[i] + C[k] * k;
			 
	/*Impressao vetor B*/

	for(i=1;i<=dim;i++)
		printf("[%f] \n",B[i]);       
				
	/*O passo de isolamento de incoginita do sistem foram feitos a mao*/

	A[2] = (((Mat[1][1]*B[2]) - (Mat[2][1]*B[1]))/
					((Mat[2][1]*Mat[1][2]) + (Mat[2][2]*Mat[1][1])));

	A[1] = ((B[1]-A[2]*Mat[1][2]) / Mat[1][1]);

	printf("Os valores de A1 e A2 para a equacao da reta sao: \n");

	for(i=1;i<=dim;i++)
		printf("A%d: [%f]\n",i,A[i]);

	return 0;
}