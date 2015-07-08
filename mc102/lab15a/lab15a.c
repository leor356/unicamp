/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias

*/

#include <stdio.h>
#include <stdlib.h>


void verificaValor(int **tabuleiro, int N, int M, int X, int Y, int *encontrouCaminho, int energia);

int main(){
	int i, j;
	int **tabuleiro;
	int encontrouCaminho;
	int N, M, E;

	/* Leitura da entrada */
	scanf(" %d %d %d", &N, &M, &E);

	/* Alocando espaco */
	tabuleiro = malloc(N * sizeof(int*));
	for(i=0;i<N;i++)
		tabuleiro[i] = malloc(M * sizeof(int));

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf(" %d", &tabuleiro[i][j]);
		}
	}
	
	/* Verifica se encontrou caminho para cada umda das entradas do tabuleiro */
	for(i=0;i<N;i++){
		encontrouCaminho = 0;
		verificaValor(tabuleiro, N, M, i, 0, &encontrouCaminho, E);
		if(encontrouCaminho)
			printf("Sim\n");
		else
			printf("Nao\n");
	}

	/* Desalocando vetores */
	for( i=0 ; i<N ; i++)
		free(tabuleiro[i]);
	free(tabuleiro);
	return 0;
}

/* Verifica se encontrou a saida para a coluna X */
void verificaValor(int **tabuleiro, int N, int M, int X, int Y, int *encontrouCaminho, int energia){
	
	/* Retira as possibilidades de energia maiores E */
	if(energia > M - 1 - Y){
		/* Verifica se saiu */
		if((tabuleiro[X][Y] >> 2)%2 && Y == M-1){
			*encontrouCaminho = 1;
		}else {
			/*Verifica Direita */
			if((tabuleiro[X][Y] >> 2)%2){
					verificaValor(tabuleiro, N, M, X, Y+1, encontrouCaminho, energia - 1);
			}
			/* Verifica baixo */
			if(X < N-1 && (tabuleiro[X][Y] >> 1)%2 && !*encontrouCaminho){
				verificaValor(tabuleiro, N, M, X+1, Y, encontrouCaminho, energia - 1);
			}
			/* Verifica esquerda */
			if(Y > 0 && (tabuleiro[X][Y])%2 && !*encontrouCaminho){
				verificaValor(tabuleiro, N, M, X, Y-1, encontrouCaminho, energia - 1);
			}
			/* Verifica em cima*/
			if(X > 0 && (tabuleiro[X][Y] >> 3)%2 && !*encontrouCaminho){
				verificaValor(tabuleiro, N, M, X-1, Y, encontrouCaminho, energia - 1);
			}
		}
	}

	if(*encontrouCaminho)
		return;
}