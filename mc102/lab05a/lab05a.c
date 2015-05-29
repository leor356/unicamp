/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 20

int main() {
  
  int N, i, j, k, tamE, tamC;
  char stringE[MAX + 1], stringC[MAX + 1], flag = 0;
  
  scanf("%d ", &N);
  
  /* Verifica N vezes se stringE eh subsequencia de stringC */
  for(i=0;i<N;i++){ 
    scanf("%s %s", stringE, stringC);
    
    /* Calculando o tamanho da stringE e da stringC */
    tamE = 0;
    tamC = 0;
    while(stringE[tamE])
      tamE++; 
    while(stringC[tamC])
      tamC++;
     
    
    /* Verificacao se eh subsequencia */
    if(tamC >= tamE){
      j = 0;
      k = 0;
      while(k<tamC){
	if(stringE[j] == stringC[k])
	  j++;
	k++;	
      }
      if(j == tamE)
	flag = 1;
      else
	flag = 0;
    }else{
      flag = 0;
    }
    
    /* Retorna a resposta de acordo com a flag */
    if(flag)
      printf("Sim\n");
    else
      printf("Nao\n");
  }
  
  
  return 0;
}