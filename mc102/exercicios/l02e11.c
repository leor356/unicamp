/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <math.h>

int main() {
  
  int x, xo, y, yo;
  double res;
  
  scanf("%d %d %d %d", &x, &y, &xo, &yo);
  
  res = ((x - xo)*(x - xo)) + ((y - yo)*(y - yo));
  res = sqrt(res);
  
  printf("%f", res);
  
  return 0;
}