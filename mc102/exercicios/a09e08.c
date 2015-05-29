/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100

int main() {
  
  int N, matriz[MAX][MAX], i, j, quadradom = 1, soma = 0, somal = 0, somac = 0, somadp = 0, somaod = 0;
  
  scanf("%d", &N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  for(j=0;j<N;j++){
     soma += matriz[0][j]; 
    }
  for(i=0;i<N;i++){
    somadp += matriz[i][i];
    for(j=0;j<N;j++){
      somal += matriz[i][j];
      somac += matriz[j][i];
      if(i+j==N-1){
	somaod += matriz[i][j];
      }
    }
    if(somal != soma || somac != soma){
      quadradom =0;
      printf("entou %d %d somal %d somac %d\n", i, j, somal, somac);
      i=N;
      
    }
    somal = 0;
    somac = 0;
  }
  if(somadp != soma || somaod != soma){
    quadradom =0;
    printf("entou somadp %d somaod %d\n", somadp, somaod);
  }
  
  if(quadradom)
    printf("A matriz de entrada eh um ~*quadrado magico*~\n");
  else 
    printf("A matriz de entrada nao eh um quadrado magico\n");

  return 0;
}