/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

void imprimefatores(int X);

int main(){
  int var;
  scanf("%d", &var);
  imprimefatores(var);
  
  return 0;
}

void imprimefatores(int X){
  int i, j;
  printf("1 x");
  for(i=2;i<X;i++){
    j=0;
    while(X%i==0){
      X = X/i;
      j++;
    }
    if(j)
      printf(" x %d^%d", i, j);
  }
  printf("\n");
  return;
}
