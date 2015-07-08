/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias

	5 5 6
	6 7 7 7 3
	14 4 5 10 2
	14 0 3 15 14
	14 14 13 1 11
	4 12 8 0 9
*/

#include <stdio.h>
#include <stdlib.h>


	 


int converteParaBin(int A);

void verificaValor(int **tabuleiro, int N, int M, int X, int *flag);

int main(){
	int i, j, auxNum;
	int **tabuleiro;
	int *encontrouCaminho;
	int N, M, E;

	scanf(" %d %d %d", &N, &M, &E);

	tabuleiro = malloc(N * sizeof(int*));
	for(i=0;i<N;i++)
		tabuleiro[i] = malloc(N * sizeof(int));

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%4d ", &auxNum);
			tabuleiro[i][j] = converteParaBin(auxNum);
		}
	}
	for(i=0;i<M;i++){
		encontrouCaminho = 0;
		verificaValor(tabuleiro, N, M, i, &encontrouCaminho);
		if(encontrouCaminho)
			printf("Sim\n");
		else
			printf("Nao\n");
	}

	printf(" %d %d %d\n", N, M, E);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%4d ", tabuleiro[i][j]);
		}
		printf("\n");
	}

	for( i=0 ; i<N ; i++)
		free(tabuleiro[i]);
	free(tabuleiro);
	return 0;
}

int converteParaBin(int A){
	int num=0, i=1;
	do{
		num += (A%2)*i;
		i = 10*i;
		A = A/2;
	}while(A>0);
	return num;
}

void verificaValor(int **tabuleiro, int N, int M, int X, int *encontrouCaminho){
	int Y=0;
	int direita=0, esquerda=0, cima=0, baixo=0;

	if(*flag)
		return;
	else{

		cima = tabuleiro[X][Y]/1000;

		if(direita){
			if(Y == M){
				*encontrouCaminho = 1;
			}else{

			}
		}
		if(esquerda){
			
		}
		if(cima){

		}
		if(baixo){

		}
	}

		

}