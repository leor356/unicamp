/*
Aluno: Leonardo de Oliveira Ramos
RA: 171941
Sala: mc102r
Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

/* Verifica se os politicos comprados juntos tem influencia suficiente para
serem considerados como compra */
int verificaInfluencia(int **influencias, int n, int *temp,
	int qtdPoliticosComprados, int r){
	int i, j, qtdInfluenciados=0;

/* Procura horizontalmente os politicos influenciados */
	for(i=0;i<n;i++){
/* Se encontrar alguem que influencia o j-esimo politico, incrementa
qtdInfluenciados e passa para o proximo politico */
		for(j=0;j<qtdPoliticosComprados;j++){
			if(influencias[temp[j]][i]){
				qtdInfluenciados++;
				j = qtdPoliticosComprados;
			}
		}
	}
/* Retorna verdadeiro se a quantidade de politico influenciados for maior 
que o numero K de entrada */
	if(qtdInfluenciados >= r)
		return 1;
	return 0;
}

/* Retorna a soma dos precos referentes aos n primeiros numeros do vetor[n] */
int somaPrecos(int vetor[], int n, int *precos) {
	int i, soma = 0;
	for (i = 0; i < n; i++)
		soma += precos[vetor[i]];
	return soma;
}

/* Faz todas as possiveis combinacoes de politicos, se os politicos da
combinacao juntos influenciarem r politicos, verifica se o preco deles
da a menor preco */
void encontraMenorPreco(int n, int r, int temp[], int next, int size,
	int **influencias, int *precos, int *menorPreco) {
	int i, somaLocal;
/* Caso esta combinacao de politicos tenha a influencia minima desejada,
calcula a soma do preco deles e verifica se eh o menor */
	if(size && verificaInfluencia(influencias, n, temp, size, r)){
		somaLocal = somaPrecos(temp, size, precos);
		if(somaLocal < *menorPreco)
			*menorPreco = somaLocal;
	}
/* Realiza as combinacoes e as guarda em temp[] */
	if(r != size){
		for ( i=next ; i<n ; i++ ) {
			temp[size] = i;
			encontraMenorPreco(n,r,temp,i+1,size+1,influencias,precos,menorPreco);
		}
	}
}

int main(){
	int N, K, *precos, **influencias, i, j, menorPreco = 0, *temp;

/* Entrada e alocacao de memoria */
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

/* Inicializa o menor preco com um valor possivel */
		for(i=0;i<K;i++)
			menorPreco += precos[i];

/* Encontra o valor do menor preco */
		encontraMenorPreco(N, K, temp, 0, 0, influencias, precos, &menorPreco);

/* Saida e desalocamento de memoria */
		printf("%d\n", menorPreco);

		for(i=0;i<N;i++)
			free(influencias[i]);
		free(influencias);
		free(temp);
		free(precos);
		return 0;
	}
