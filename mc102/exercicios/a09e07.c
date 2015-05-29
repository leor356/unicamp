/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100

int main() {
  
  int N, matriz[MAX][MAX], i, j, triangulars=1, triangulari=1;
  
  scanf("%d", &N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &matriz[i][j]);
      if(j<i && matriz[i][j])
	triangulari = 0;
      if(i<j && matriz[i][j])
	triangulars = 0;
      
    }
  }
  if(triangulari && triangulars)
    printf("A matriz de entrada eh diagonal\n");
  else if (triangulari)
    printf("A matriz de entrada eh triangular inferior\n");
  else if (triangulars)
    printf("A matriz de entrada eh triangular\n");
  else 
    printf("A matriz de entrada nao eh diagonal, triangular inferior nem triangular superior\n");
  
  return 0;
}