/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int ninversoes(int v[], int n);

int main(){
  int v[100], n, i;
  
  scanf("%d", &n);
  for(i=0;i<n; i++)
    scanf("%d", &v[i]);
    
  printf("%d\n", ninversoes(v, n));
  
  return 0;
}
int ninversoes(int vec[], int n){
  int i, j, inv=0;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
      if(vec[i]>vec[j])
        inv++;
  
  return inv;
}
