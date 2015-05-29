/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  int *vetor, tamVetor, chave, i, j, *posicoes;

  scanf("%d %d", &chave, &tamVetor);

  vetor = malloc(tamVetor * sizeof(int));
  posicoes = malloc(tamVetor * sizeof(int));

  for(i=0;i<tamVetor;i++){
    scanf("%d", &vetor[i]);
    posicoes[i] = -1;
  }

  j=0;
  for(i=0;i<tamVetor;i++){
    if(vetor[i] == chave){
      posicoes[j] = i;
      j++;
    }
  }

  i=0;
  while(posicoes[i] != -1){
    printf("%d ", posicoes[i]);
    i++;
  }
  printf("\n");

  free(vetor);
  return 0;
}
