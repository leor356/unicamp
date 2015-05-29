/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
  
void imprimecontrario(int X){  
  while(X!=0){
    printf("%d", X%10);
    X = X/10;
  }
  printf("\n");
  return;
}
  
int main(){
  int var;
  
  scanf("%d", &var);
  imprimecontrario(var);
  
  return 0;
}
