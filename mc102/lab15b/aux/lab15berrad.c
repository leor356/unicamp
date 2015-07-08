/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

/* Encontra o melhor indice primeiramente vendo se mescla 3 intervalos
depois ve se tem um intervalo proximo de mesclar 3, senao pega o maior
numero */
void melhorIndice(int **vet, int N, int *ind, int *l) {
	int i, j;
	double menorRazao, razao;
	menorRazao = (double)N;
	for(i=0;i<N;i++){
		for(j=1;j<N;j++){
			if(vet[1][i] == vet[0][j] - 1 && i!=j){
				if(vet[0][i] == vet[1][j-1]+1){
					*ind = i;
					*l = j;
					return;
				}
			}else if(i+1==j && vet[1][i] < vet[0][j] - 1){
				razao = (double)vet[0][j]/vet[1][i];
				if(menorRazao > razao){
					menorRazao = razao;
					*l = j;
				}
			}
		}
	}
	if(menorRazao != N){
		for(i=0;i<N;i++){
			if(vet[0][*l] -1 == vet[1][i]){
				*ind = i;
			}
		}
		printf("%.2f %d %d\n", menorRazao, *ind, *l);
		return;
	}
	*ind = 0;
	for(i=0;i<N-1;i++){
		if(vet[0][i] > vet[0][*ind])
			*ind = i;
	}
	for(i=0;i<N;i++){
		if(i!= *ind && vet[1][*ind] == vet[0][i]-1){
			*l = i;
			return;
		}
	}

	*l = N;

	return;
}

/* Inseri intervalo do indice ind na posicao l */
void inserIntervalo(int **V, int ind, int l){
	int i, auxZero, auxUm;

	auxZero = V[0][ind];
	auxUm = V[1][ind];
	
	if(ind>l){
		for(i=ind-1;i>=l;i--){
			V[0][i+1] = V[0][i];
			V[1][i+1] = V[1][i];
		}
		V[0][i+1] = auxZero;
		V[1][i+1] = auxUm;

	}else{
		for(i=ind;(i<l-1);i++){
			V[0][i] = V[0][i+1];
			V[1][i] = V[1][i+1];
		}
		
		V[0][l-1] = auxZero;
		V[1][l-1] = auxUm;		
	}

}

/* Diminui vetor simplificando intervalos */
void retiraSequencias(int **V, int *N){
	int i, j=0;

	for(i=1;i<*N;i++){
		while(i<*N && V[0][i] == V[1][i-1] + 1){
			V[1][j] = V[1][i];
			i++;
		}
		if(i<*N){
			j++;
			V[0][j] = V[0][i];
			V[1][j] = V[1][i];
		}
	}
	*N = j+1;
	
}

/* Impressao para verificar erros */
void imprimeV(int **v, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d: %d %d\n", i, v[0][i], v[1][i]);
	}
}

/* Organiza o vetor pelos criterios de menor distancia */
int dSort(int **V, int N){
	int dist=0, ind, l;

	while(N > 1){

			imprimeV(V, N);

			dist++;
			melhorIndice(V, N, &ind, &l);
			inserIntervalo(V, ind, l);

			printf("%d %d\n\n", ind, l);

			retiraSequencias(V, &N);
	}

	return dist;
}

int main(){
	int N, **V, i, distancia=0;

	scanf(" %d", &N);


	V = malloc(2 * sizeof(int*));
	for(i=0;i<2;i++){
		V[i] = malloc(N * sizeof(int));
	}

	for(i=0;i<N;i++){
		scanf(" %d", &V[0][i]);
		V[1][i] =	 V[0][i];  
	}
	retiraSequencias(V, &N);

	distancia = dSort(V, N);

	printf("%d\n", distancia);

	for(i=0;i<2;i++)
		free(V[i]);
	free(V);
	return 0;
}
