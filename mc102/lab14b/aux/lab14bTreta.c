/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int indicemenor(int *precos, int i, int N){
	int j, menor = i;
	for(j=i+1;j<N;j++){
		if(precos[j] < precos[menor]){
			menor = j;
		}
	}
	return menor;
}

void troca(int *A, int *B){
	int aux = *A;
	aux = *A;
	*A = *B;
	*B = aux;
}

void selectionSort(int *precos, int *memoria, int n){
	int i, menor;
	for(i=0;i<n;i++){
		menor = indicemenor(precos, i, n);
		troca(&precos[i], &precos[menor]);
		troca(&memoria[i], &memoria[menor]);
	}
}
int ehvalido(int **influencias, int *memoria, int *precos, int *temp, int tam, int N, int K){
	int i, j, numInfluencia =0, totalPreco=0;

	for(i=0;i<N;i++){
		j=0;
		while(!influencias[i][memoria[temp[j]]] && j<tam){
			j++;
		}
		numInfluencia += influencias[i][memoria[temp[j]]];
	}
	if(numInfluencia >= K){
		for(i=0;i<tam;i++){
			totalPreco += precos[memoria[temp[i]]];
			printf("%d ", precos[memoria[temp[i]]]);
		}
		printf(" %d\n", numInfluencia);
		return totalPreco;
	}
	return 0;
}

int encontraValido(int **influencias, int *precos, int *memoria, int N, int K, int pos, int tam, int *temp){
	int i=0, valorEncontrado;
	if(tam == K)
		return ehvalido(influencias, memoria, precos, temp, tam, N, K);
	else{
		for(i=pos;i<=N;i++){
			temp[tam] = i;
			valorEncontrado = encontraValido(influencias, precos, memoria, N, K, i+1, tam+1, temp) == 0;
			if(valorEncontrado){
				return valorEncontrado;
			}
		}
	}
	return 0;
}

int main(){
	int N, K, *precos, *memoria, **influencias, i, j, menorPreco = 0, *temp;

	scanf(" %d %d", &N, &K);

	precos = malloc(N * sizeof(int));
	memoria = malloc(N * sizeof(int));
	temp = malloc(K * sizeof(int));

	influencias = malloc(N * sizeof(int*));
	for(i=0;i<N;i++)
		influencias[i] = malloc(N * sizeof(int));

	for(i=0;i<N;i++){
		memoria[i] = i;
	}

	for(i=0;i<N;i++){
		scanf(" %d", &precos[i]);
	}
	selectionSort(precos, memoria, N);

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf(" %d", &influencias[i][j]);
	
	for(i=0;i<K && !menorPreco ;i++)
		menorPreco = encontraValido(influencias, precos, memoria, N, i, 1, 0, temp);
	


	printf("%d %d\n", N, K);
	for(i=0;i<N;i++)
		printf("%d[%d] ", precos[i], memoria[i]);
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%d ", influencias[i][j]);
		printf("\n");
	}

	printf("Menor %d\n", menorPreco);

	for(i=0;i<N;i++)
		free(influencias[i]);
	free(influencias);
	free(temp);
	free(memoria);
	free(precos);
	return 0;
}
