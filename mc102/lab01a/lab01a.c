/*
Leonardo de Oliveira Ramos
RA: 171941
Professor: Zanoni Dias

*/

#include <stdio.h>
#include <math.h>

int main(){
  /*Declaracao das variaveis */
  double C, i, Mf, M, n;

  /*Entrada de dados */
  scanf("%lf %lf %lf %lf", &C, &i, &n, &M);
  
  /*Calculos do montante final e do numero de lotes*/
  Mf = C * (pow(1 +(i/100), n));
  n = log(M/C)/log(1 +(i/100));
  
   /*Impressao dos resultados*/
  printf("Montante = %.2f\n", Mf);
  printf("%.0lf lote(s)\n", ceil(n));
  
  return 0;
}
