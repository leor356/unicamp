/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100

int main() {
  
  int matriz[MAX][MAX], linhas, colunas, i, j;
  
  scanf("%d %d", &linhas, &colunas);
  for(i=0;i<linhas;i++)
    for(j=0;j<colunas;j++)
      scanf("%d", &matriz[i][j]);
  
  for(j=0;j<colunas;j++){
    for(i=0;i<linhas;i++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
     
    
  return 0;
}