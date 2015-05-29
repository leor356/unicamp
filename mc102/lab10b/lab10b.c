/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>


void insert(int *A, int n){
  int j, aux = A[n];
  for (j = n - 1; (j >= 0) && (A[j] > aux); j--)
    A[j + 1] = A[j];
  A[j + 1] = aux;
}

/* Calcula o modulo de I */
int mod(I){
  if(I >= 0)
    return I;
  else
    return -I;
}

int main(){
  int M, N, D, *X, *Y, i, j, numCasais=0;
  scanf("%d %d %d", &M, &N, &D);
  X = malloc(M * sizeof(int));
  Y = malloc(N * sizeof(int));

  /* Escaneia e organiza as entradas no vetor X e o vetor Y */
  scanf("%d", &X[0]);
  for(i=1;i<M;i++){
    scanf("%d", &X[i]);
    insert(X, i);
  }
  scanf("%d", &Y[0]);
  for(i=1;i<N;i++){
    scanf("%d", &Y[i]);
    insert(Y, i);
  }

  /* Encontra os casais */
  i=0;
  j=0;
  do{
    if(mod(X[i]-Y[j]) <= D){
      numCasais++;
      i++;
      j++;
    }else if(Y[j] > X[i]){
      i++;
    }else if(Y[j] < X[i]){
      j++;
    }
  }while(i<M && j<N);

  printf("Numero maximo de duplas equilibradas = %d\n", numCasais);

  return 0;
}