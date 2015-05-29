/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  int numeros[100], max[98], min[98], nmax=0, nmin=0, i, n;
  
  scanf("%d", &n);
  
  for(i=0;i<n;i++){
    scanf("%d", &numeros[i]);
  }
  
  for(i=1;i<(n-1);i++){
    if(numeros[i]>numeros[i-1] && numeros[i]>numeros[i+1]){
      max[nmax] = numeros[i];
      nmax++;
    }
    if(numeros[i]<numeros[i-1] && numeros[i]<numeros[i+1]){
      min[nmin] = numeros[i];
      nmin++;
    }
  }
  for(i=0;i<nmax;i++){
    printf("%d eh um numero maximo\n",max[i]);
  }
  for(i=0;i<nmin;i++){
    printf("%d eh um numero minimo\n",min[i]);
  }
  
  return 0;
}

