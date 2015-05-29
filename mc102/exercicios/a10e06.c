/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int verificaordem(int v[], int n);

int main(){
  int v[100], n, i;
  
  scanf("%d", &n);
  for(i=0;i<n; i++)
    scanf("%d", &v[i]);
    
  printf("%d\n", verificaordem(v, n));
  
  return 0;
}
int verificaordem(int vec[], int n){
  int i;
  for(i=0;i<n-1;i++)
    if(vec[i]>vec[i+1])
      return 0;
  
  return 1;
}
