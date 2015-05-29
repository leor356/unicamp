/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  int entrada[100], contagem[100], n, i, j, maior, moda = 0;
  
  scanf("%d", &n);
  
  for(i=0;i<n;i++)
    contagem[i] = 0;
  
  for(i=0;i<n;i++){
    scanf("%d", &entrada[i]);
  }
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(entrada[i] == entrada[j]){
	contagem[i]++;
      }
    }
  }
  
  maior = contagem[0];
  j= 0;
  for(i=0;i<n;i++){
    if(contagem[i]>maior){
      maior = contagem[i];
      j = i;
    }
  }
  
  moda = entrada[j+1];
  
  printf("%d %d\n", maior, moda);
  
  return 0;
}