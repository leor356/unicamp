/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  double primTermo, numTermos, razao, nesimoValor, somaDosValores;
  
  scanf("%lf %lf %lf", &primTermo, &numTermos, &razao);
  
  nesimoValor = primTermo + (numTermos - 1) * razao;
  somaDosValores = (primTermo + nesimoValor)*numTermos/2;
  
  printf("%.2f %.2f\n", nesimoValor, somaDosValores);
  
  return 0;
}