/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int achaRegioes(int **img, int lado, int pos1, int pos2){
	int i, j, regioes=0, zero=0, um=0;

	for(i=pos1;(i<pos1+lado) && (zero + um != 2);i++){
		for(j=pos2;(j<pos2+lado) && (zero + um != 2);j++){
			if(img[i][j])
				zero = 1;
			if(!img[i][j])
				um = 1;
		}
	}

	if(zero + um == 2){
		if(lado == 2){
			return 4;
		}

		regioes += achaRegioes(img, lado/2, pos1, pos2);
		regioes += achaRegioes(img, lado/2, pos1 + lado/2, pos2);
		regioes += achaRegioes(img, lado/2, pos1, pos2 + lado/2);
		regioes += achaRegioes(img, lado/2, pos1 + lado/2, pos2 + lado/2);

	}else if(zero + um == 1){
		regioes += 1;
	}

	return regioes;
}

int main(){
  int i, j, regioes, lado, **img, posX, posY;

  scanf(" %d", &lado);

  img = malloc(lado * sizeof(int *));
	for(i=0;i<lado;i++)
		img[i] = malloc(lado * sizeof(int));

	for(i=0;i<lado;i++)
		for(j=0;j<lado;j++)
			scanf(" %d", &img[i][j]);

	posX = 0;
	posY = 0;

  regioes = achaRegioes(img, lado, posX, posY);

  printf("Numero de regioes = %d\n", regioes);
	free(img);  
  return 0;
}
