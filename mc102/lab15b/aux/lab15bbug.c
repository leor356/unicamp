/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

/*
	How it works:

	Este programa guarda o vetor dado como intervalos, com cada intervalo [ai,bi]
com a<=b representado da forma [ V[0][i], V[1][i] ] sendo i o numero de
intervalos. Por exemplo: 
o vetor 1 2 3 8 6 7 4 5 seria transformado em:
1 8 6 4
3 8 7 5

com V[0][2] = 6 e V[1][2] = 7
	Esta conversao eh feita pela funcao retiraSequencias.
	Assim, deve-se organizar os intervalos de forma crescente de maniera que se
	faça o menor numero de trocas.

	Minha afirmacao eh: existe uma forma de achar a melhor troca de um vetor de 
intervalos. 
	Esta forma seria achar o intervalo da posicao 'ind' que ao mudar ele para
a posicao 'local' automaticamente se mescla o maior numero de intervalos.

Nota-se que

	*O numero maximo de intervalos que se pode mesclar eh 2(Mescla com o
	intervalo da frente e com o de tras).

	*O numero minimo de intervalos que se consegue mesclar quando se procura a 
 troca otima eh 1(Um intervalo procurado sempre pode se mesclar com ao menos 1
 outro intervalo do vetor).

	Entao o programa acha essa melhor posicao em faz a troca, até que se
forme um intervalo so
*/


/* Encontra o melhor indice possivel para a troca vendo se os intervalos da
frente e de tras mesclam */
void melhorIndice(int **vet, int N, int *indProcurado, int *local) {
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(vet[1][i] == vet[0][j] - 1 && i!=j){
				if(vet[0][i] == vet[1][j-1]+1){
					*local = j;
					*indProcurado = i;
					return;
				}
			}
		}
	}
	*indProcurado = 0;
	for(i=0;i<N-1;i++){
		if(vet[0][i] > vet[0][*indProcurado])
			*indProcurado = i;
	}
	for(i=0;i<N;i++){
		if(i!=*indProcurado && vet[0][*indProcurado] - 1 == vet[1][i]){
			*local = i;
			return;
		}
	}
}

/* Insere o intervalo V[][ind] na posicao 'local' de uma forma similar ao
insertion do insertion sort */
void inserIntervalo(int **V, int ind, int local){
	int i, auxZero, auxUm;

	auxZero = V[0][ind];
	auxUm = V[1][ind];
	
	if(ind>local){
		for(i=ind-1;i>=local;i--){
			V[0][i+1] = V[0][i];
			V[1][i+1] = V[1][i];
		}
		V[0][i+1] = auxZero;
		V[1][i+1] = auxUm;

	}else{
		for(i=ind;(i<local);i++){
			V[0][i] = V[0][i+1];
			V[1][i] = V[1][i+1];
		}
		
		V[0][i] = auxZero;
		V[1][i] = auxUm;		
	}

}

/* Retira as sequencias que podem ser representadas por intervalos */
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

void imprimeV(int **V, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d: %d %d \n",i, V[0][i], V[1][i]);
	}
}

/* Organiza o vetor V intervalos, e para cada troca incrementa a
distancia */
int dSort(int **V, int N){
	int dist=0, ind, local,i;

	/*
	while(N > 1){
		melhorIndice(V, N, &ind, &local);
		imprimeV(V, N);
		inserIntervalo(V, ind, local);
		dist++;
		retiraSequencias(V, &N);
	}
*/
	for(i=0;i<8;i++){
		melhorIndice(V, N, &ind, &local);
		imprimeV(V, N);
		printf("M: %d %d\n\n", ind, local);
		inserIntervalo(V, ind, local);
		dist++;
		retiraSequencias(V, &N);
	}

	return dist;
}

int main(){
	int N, **V, i, distancia=0;
/*
	int x, y;
*/
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

/*
	imprimeV(V,N);
	melhorIndice(V, N, &x, &y);
	printf("%d %d\n", x, y);
	inserIntervalo(V, x, y);
	imprimeV(V,N);
	retiraSequencias(V, &N);
	imprimeV(V,N);
	melhorIndice(V, N, &x, &y);
	printf("%d %d\n", x, y);
	inserIntervalo(V, x, y);
	imprimeV(V,N);
*/

	distancia = dSort(V, N);

	printf("%d\n", distancia);

	for(i=0;i<2;i++)
		free(V[i]);
	free(V);
	return 0;
}
