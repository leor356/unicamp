/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

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

int achaIntervaloDaFrente(int **V, int N, int ind){
	int i;
	for(i=0;i<N;i++){
		if(V[1][ind] == V[0][i] - 1 && i!=ind){
			if(ind>i)
				return i;
			else
				return i-1;
		}
	}
	return N-1;
}
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

/* Impressao para verificar erros */
void imprimeV(int **v, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d: %d %d\n", i, v[0][i], v[1][i]);
	}
}
void copiaAB(int **A, int **B, int N){
	int i;
	for(i=0;i<N;i++){
		A[0][i] = B[0][i];
		A[1][i] = B[1][i];
	}
}

/* Organiza o vetor pelos criterios de menor distancia */
void encontraDist(int **V, int N, int size, int *distancia){
	int i, j, pos, **Vaux, Naux;

	
	
	if(N == 1){
/*
		printf("Dist: %d\n", size);
		*/
		if(size < *distancia)
			*distancia = size;
		return;
	}
	

	if(N >= size && size < *distancia){
		for (i=0;i<N;i++){

			Vaux = malloc(2 * sizeof(int*));
			for(j=0;j<2;j++){
				Vaux[j] = malloc(N * sizeof(int));
			}

			copiaAB(Vaux, V, N);
			Naux = N;

/*
			printf("\n");
			imprimeV(Vaux, Naux);
			*/
			
			pos = achaIntervaloDaFrente(Vaux, N, i);
			inserIntervalo(Vaux, i, pos);
			retiraSequencias(Vaux, &Naux);

/*
			printf("Frente %d em %d (%d)\n", i, pos, size);
			printf("\n");
			imprimeV(Vaux, Naux);
			printf("\n");
			*/
			encontraDist(Vaux, Naux, size + 1, distancia);

			copiaAB(Vaux, V, N);
			Naux = N;
/*
			printf("\n");
			printf("Normal\n");
			imprimeV(Vaux, N);
			*/
			
			pos = achaIntervaloDeTras(Vaux, N, i);
			inserIntervalo(Vaux, i, pos);
			retiraSequencias(Vaux, &Naux);
/*			
			printf("Tras %d em %d\n", i, pos);
			printf("\n");
			imprimeV(Vaux, Naux);
			printf("\n");
			*/
			encontraDist(Vaux, Naux, size + 1, distancia);

			for(j=0;j<2;j++)
				free(Vaux[j]);
			free(Vaux);
		}
	}
}

int main(){
	int N, **V, i, distancia;

	scanf(" %d", &N);


	V = malloc(2 * sizeof(int*));
	for(i=0;i<2;i++){
		V[i] = malloc(N * sizeof(int));
	}

	for(i=0;i<N;i++){
		scanf(" %d", &V[0][i]);
		V[1][i] =	 V[0][i];  
	}

	distancia = N;

	retiraSequencias(V, &N);
	encontraDist(V, N, 0, &distancia);

/*
	retiraSequencias(V, &N);
	imprimeV(V, N);
	distancia = achaIntervaloDaFrente(V, N, 4);
	printf("%d\n", distancia);
	printf("\n");
	inserIntervalo(V, 4, distancia);
	imprimeV(V, N);
	printf("\n");

	retiraSequencias(V, &N);
	imprimeV(V, N);
	distancia = achaIntervaloDeTras(V, N, 6);
	printf("%d\n", distancia);
	inserIntervalo(V, 6, distancia);
	imprimeV(V, N);
*/

	printf("%d\n", distancia);

	for(i=0;i<2;i++)
		free(V[i]);
	free(V);
	return 0;
}
