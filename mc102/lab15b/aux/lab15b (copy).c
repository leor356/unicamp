/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

/* Simplifica os intervalos reorganizando os intervalos que podem ser 
diminuidos */
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

/* Acha a posicao que se deve encaixar o intervalo da posicao ind de forma que o
proximo intervalo seja o que comeca com o proximo numero (V[1][ind] + 1) */
int achaIntervaloDaFrente(int **V, int N, int ind){
	int i;
	for(i=0;i<N;i++){
		if(V[1][ind]+1 == V[0][i] && i!=ind){
			if(ind>i)
				return i;
			else
				return i-1;
		}
	}
	return N-1;
}

/* Acha a posicao que se deve encaixar o intervalo da posicao ind de forma que o
 intervalo anterior seja o que termina com V[0][ind] - 1 */
int achaIntervaloDeTras(int **V, int N, int ind){
	int i;
	for(i=0;i<N;i++){
		if(V[0][ind] == V[1][i] + 1 && i!=ind){
			if(ind>i)
				return i+1;
			else
				return i;
		}
	}
	return 0;
}

/* Faz a troca dos valores do intervalo da posicao ind para a posicao l */
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
		for(i=ind;(i<l);i++){
			V[0][i] = V[0][i+1];
			V[1][i] = V[1][i+1];
		}
		
		V[0][l] = auxZero;
		V[1][l] = auxUm;		
	}

}

/* Copia um vetor de intervalos B em A */
void copiaAB(int **A, int **B, int N){
	int i;
	for(i=0;i<N;i++){
		A[0][i] = B[0][i];
		A[1][i] = B[1][i];
	}
}

/* Encontra a distancia */
void encontraDist(int **V, int N, int size, int *distancia){
	int i, j, pos, **Vaux, Naux;

	/* Caso Base: quando o vetor tem somente 1 intervalo sabe-se que size eh a 
	distancia das trocas feitas ate aqui, e achando a menor delas, tem-se a 
	saida desejada */

	if(N == 1){
		if(size < *distancia)
			*distancia = size;
		return;
	}

	for(i=0;i<N;i++){
		printf("%d %d\n", V[0][i], V[1][i]);
	}printf("\n");


	/* Calcula as possiveis trocas e corta as possibilidades que sao maiores que
	a distancia encontrada */
	if(N >= size && size < *distancia){
		for (i=0;i<N;i++){

			/* Alocacao de memoria para Vaux */
			Vaux = malloc(2 * sizeof(int*));
			for(j=0;j<2;j++){
				Vaux[j] = malloc(N * sizeof(int));
			}

			/* Usa o vetor Vaux para nao baguncar o vetor V */
			copiaAB(Vaux, V, N);
			Naux = N;


			/* Faz a troca para encaixar no intervalo da frente e organiza o vetor de 
			intervalos */
			pos = achaIntervaloDaFrente(Vaux, N, i);
			inserIntervalo(Vaux, i, pos);
			retiraSequencias(Vaux, &Naux);

			/* Calcula as proximas trocas */
			encontraDist(Vaux, Naux, size + 1, distancia);

			/* Volta com o vetor referente a essa combinacao para nao usar o vetor
			baguncado antigo */
			copiaAB(Vaux, V, N);
			Naux = N;			

			/* Faz a troca para encaixar no intervalo de tras e organiza o vetor de 
			intervalos */
			pos = achaIntervaloDeTras(Vaux, N, i);
			inserIntervalo(Vaux, i, pos);
			retiraSequencias(Vaux, &Naux);

			/* Calcula as proximas trocas */
			encontraDist(Vaux, Naux, size + 1, distancia);

			/* Desaloca Vaux */
			for(j=0;j<2;j++)
				free(Vaux[j]);
			free(Vaux);
		}
	}
}

int main(){
	int N, **V, i, distancia;

	scanf(" %d", &N);

	/* Alocando espaco para V */
	V = malloc(2 * sizeof(int*));
	for(i=0;i<2;i++){
		V[i] = malloc(N * sizeof(int));
	}

	/* Leitura da entrada */
	for(i=0;i<N;i++){
		scanf(" %d", &V[0][i]);
		V[1][i] =	 V[0][i];  
	}

	/* Inicializando distancia */
	distancia = N;

	/* Organiza o vetor e calcula a distancia */
	retiraSequencias(V, &N);
	encontraDist(V, N, 0, &distancia);

	printf("%d\n", distancia);

	/* Desalocando espaco */
	for(i=0;i<2;i++)
		free(V[i]);
	free(V);
	return 0;
}
