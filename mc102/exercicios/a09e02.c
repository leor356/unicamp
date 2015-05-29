/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100
int main() {
  
  int i, j, N, matrizE1[MAX][MAX], matrizE2[MAX][MAX];
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&matrizE1[i][j]);
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&matrizE2[i][j]);
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%2d ",matrizE1[i][j]);
    }
    if(i == N/2){
      printf("+ ");
    }else{
      printf("  ");
    }
    for(j=0;j<N;j++){
      printf("%2d ",matrizE2[i][j]);
    }
    if(i == N/2){
      printf(" = ");
    }else{
      printf("   ");
    }
    for(j=0;j<N;j++){
      printf("%2d ",matrizE2[i][j]+matrizE1[i][j]);
    }
    printf("\n");
    
  }
  
  return 0;
}