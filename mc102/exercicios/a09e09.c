/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100

int main() {
  
  int N, matriz[MAX][MAX], i, j, somac=0, somal=0, matrizp=1;
  
  scanf("%d", &N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      somal += matriz[i][j];
      somac += matriz[j][i];
    }
    if(somal != 1 || somac != 1){
      matrizp = 0;
      i = N;
    }
    somac = 0;
    somal = 0;
  }
  
  if(matrizp)
    printf("A matriz de entrada eh uma matriz de permutacoes\n");
  else
    printf("A matriz de entrada nao eh uma matriz de permutacoes\n");
  
  return 0;
}