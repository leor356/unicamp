/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int mdc(int N1, int N2);

int main() {

  int N1, N2;
  
  scanf("%d %d", &N1, &N2);
  
  printf("%d\n", mdc(N1, N2));
  
  return 0;
}

int mdc(int N1, int N2){
  int res;
  if(N2)
    res = mdc(N2, N1%N2);
  else
    res=N1;
  return res;
}
