/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100

int main() {
  
  int N, matriz[MAX][MAX], i, j, triangular=1;
  
  scanf("%d", &N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &matriz[i][j]);
      if(j>i && matriz[i][j]){
	triangular =0;
      }
    }
  }
  if(triangular)
    printf("A matriz de entrada eh triangular superior\n");
  else
    printf("A matriz de entrada nao eh triangular superior\n");
  
  return 0;
}