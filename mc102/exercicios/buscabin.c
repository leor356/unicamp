/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>
void vernafrente(int vet[], int pos, int posicoes[], int *i){
  if(vet[pos+1] == vet[pos]){
    posicoes[*i] = pos + 1;
    (*i)++;
    vernafrente(vet, pos+1, posicoes, i);
  }else if(vet[pos+1] > vet[pos]){
    return;
  }
}
void veratras(int vet[], int pos, int posicoes[], int *i){
  if(vet[pos-1] == vet[pos]){
    posicoes[*i] = pos - 1;
    (*i)++;
    veratras(vet, pos-1, posicoes, i);
  }
}

void buscabinaria(int vet[], int fim, int chave, int posicoes[], int i){
  int meio, inicio = 0;

  while(inicio <= fim){
    meio = (inicio + fim)/2;
    if(vet[meio] == chave){
      posicoes[i] = meio;
      i++;
      if(meio > 0)
        veratras(vet, meio, posicoes, &i);
      if(meio < fim)
        vernafrente(vet, meio, posicoes, &i);
      break;
    }else if(vet[meio] < chave){
      inicio = meio + 1;
    }else if(vet[meio] > chave){
      fim = meio - 1;
    }
  }
}

int main(){

  int chave, *vetor, tamVetor, *posicoes, i;

  scanf("%d %d", &chave, &tamVetor);

  vetor = malloc(tamVetor * sizeof(int));
  posicoes = malloc(tamVetor * sizeof(int));

  for(i=0;i<tamVetor;i++){
    scanf("%d", &vetor[i]);
    posicoes[i] = -1;
  }

  buscabinaria(vetor, tamVetor-1, chave, posicoes, 0);


  i=0;
  while(posicoes[i] != -1){
    printf("%d ", posicoes[i]+1);
    i++;
  }
  printf("\n");

  return 0;
}
