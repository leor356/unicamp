/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int mmc(int N1, int N2);

int main() {

  int N1, N2;
  
  scanf("%d %d", &N1, &N2);
  
  printf("%d\n", mmc(N1, N2));
  
  return 0;
}

int mmc(int N1, int N2){
  int aux;
  if (N1 < N2){
    aux = N2;
    N2 = N1;
    N1 = aux;
  }
  aux = N1;
  while(aux % N2){
    aux += N1;
  }
  return aux;
}
