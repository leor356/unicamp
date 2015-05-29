/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
double xay(double X, int Y);

int main() {
  double X;
  int Y;
  
  scanf("%lf %d", &X, &Y);
  printf("%.2f\n", xay(X, Y));
  
  return 0;
}

double xay(double X, int Y){
  int i;
  double res=1;
  for(i=1;i<Y;i++){
    res *= X;
  }
  return res;
}