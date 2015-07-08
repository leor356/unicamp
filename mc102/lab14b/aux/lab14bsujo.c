/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int verificaInfluencia(int **influencias, int n, int *temp, int qtdComprados, int r){
	int i, j, qtdInfluenciados=0;
	for(i=0;i<n;i++){
		for(j=0;j<qtdComprados;j++){
			/*printf("%d %d %d\n", temp[j], i, influencias[temp[j]][i]);*/
			if(influencias[temp[j]][i]){
				qtdInfluenciados++;
				j = qtdComprados;
			}
		}
	}
	if(qtdInfluenciados >= r)
		return 1;
	return 0;
}
/*
void imprime_vetor(int vetor[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}
*/
int somaPrecos(int vetor[], int n, int *precos) {
	int i, soma = 0;
	for (i = 0; i < n; i++)
		soma += precos[vetor[i]];
	return soma;
}

void combinacao_simples(int n, int r, int temp[], int next, int size, int **influencias, int *precos, int *menorPreco) {
	int i, somaLocal;
	if(size && verificaInfluencia(influencias, n, temp, size, r)){
		/*imprime_vetor(temp, size);*/
		somaLocal = somaPrecos(temp, size, precos);
		/*printf("%d \n", somaLocal);*/
		if(somaLocal < *menorPreco)
			*menorPreco = somaLocal;		
	}
	if(r != size){
		for ( i=next ; i<n ; i++ ) {
			temp[size] = i;
			combinacao_simples(n, r, temp, i + 1, size + 1, influencias, precos, menorPreco);
		}
	}
}

int main(){
	int N, K, *precos, **influencias, i, j, menorPreco = 0, *temp;

	scanf(" %d %d", &N, &K);
	precos = malloc(N * sizeof(int));
	temp = malloc(K * sizeof(int));

	influencias = malloc(N * sizeof(int*));
	for(i=0;i<N;i++)
		influencias[i] = malloc(N * sizeof(int));

	for(i=0;i<N;i++){
		scanf(" %d", &precos[i]);
	}

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf(" %d", &influencias[i][j]);
/*
	temp[0] = 0;
	temp[1] = 1;
	temp[2] = 2;
	temp[3] = 3;
	printf("Influencia do 1: %d\n", verificaInfluencia(influencias, N, temp, 4, K));
	printf("%d \n", somaPrecos(temp, 4, precos));
*/

	for(i=0;i<K;i++){
		menorPreco += precos[i];
	}

	combinacao_simples(N, K, temp, 0, 0, influencias, precos, &menorPreco);

/*
	printf("%d %d\n", N, K);
	for(i=0;i<N;i++)
		printf("%d ", precos[i]);
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%d ", influencias[i][j]);
		printf("\n");
	}
*/
	printf("%d\n", menorPreco);

	for(i=0;i<N;i++)
		free(influencias[i]);
	free(influencias);
	free(temp);
	free(precos);
	return 0;
}
