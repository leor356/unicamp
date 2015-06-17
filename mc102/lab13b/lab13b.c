/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int achaRegioes(int **img, int lado, int pos1, int pos2){
	/*
		img eh a matriz imagem de entrada
		lado eh o tamanho do lado da matriz
		pos1 e pos2 sao a posicao x e y da origem para calcular as regioes
		i e j sao contadores
		regioes eh o numero de regioes encontradas
		zero e um sao flags que dizem se encontrou 0 e se encontrou 1 na matriz 
	*/
	int i, j, regioes=0, zero=0, um=0;

	/* Verifica se tem 1 e se tem 0 */
	for(i=pos1;(i<pos1+lado) && (zero + um != 2);i++){
		for(j=pos2;(j<pos2+lado) && (zero + um != 2);j++){
			if(img[i][j])
				zero = 1;
			if(!img[i][j])
				um = 1;
		}
	}

	/* Calcula o numero de regioes em cada uma das 4 submatrizes */
	if(zero + um == 2){
		regioes += achaRegioes(img, lado/2, pos1, pos2);
		regioes += achaRegioes(img, lado/2, pos1 + lado/2, pos2);
		regioes += achaRegioes(img, lado/2, pos1, pos2 + lado/2);
		regioes += achaRegioes(img, lado/2, pos1 + lado/2, pos2 + lado/2);

	}
	/* Caso base para uma submatriz homogenea */
	else if(zero + um == 1){
		regioes += 1;
	}

	return regioes;
}

int main(){
	/*
		i e j sao contadores
		regioes eh o numero de regioes encontradas
		lado eh o tamanho do lado da matriz
		img[i][j] eh a matriz da imagem
		posX e posY sao as posicoes da origem
	*/
  int i, j, regioes, lado, **img, posX, posY;

  scanf(" %d", &lado);

  /* Alocando espaco para a matriz */
  img = malloc(lado * sizeof(int *));
	for(i=0;i<lado;i++)
		img[i] = malloc(lado * sizeof(int));

	/* Leitura da matriz imagem */
	for(i=0;i<lado;i++)
		for(j=0;j<lado;j++)
			scanf(" %d", &img[i][j]);

	posX = 0;
	posY = 0;

	/* Calculo das regioes */
  regioes = achaRegioes(img, lado, posX, posY);

  printf("Numero de regioes = %d\n", regioes);
	free(img);  
  return 0;
}
