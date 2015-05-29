/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
  /*
    M e N sao os valores do tamanho da linha e da coluna
    i, j sao contadores
    posI e posJ sao os valores i e j da posicao desejada para saida
    nDroids eh o numero de droids a serem mortos na posicao i j
    disparos eh o numero de disparos quando esta na posicao i j
    nDroidsMax e disparosMax eh o maior valor de nDroids e de disparos
    **campo eh a matriz que representa o campo
    *lDroidsMortos, *cDroidsMortos, *pDiagoDroidsMortos, *nDiagoDroidsMortos
        sao a quantidade de droids em uma linha, coluna, diagonal principal
        e diagonal nao-principal respectivamente
  */
  int M, N, i, j, posI, posJ, nDroids, nDroidsMax, disparos, disparosMax;
  int **campo, *lDroidsMortos, *cDroidsMortos, *pDiagoDroidsMortos, *nDiagoDroidsMortos;

  scanf("%d %d", &M, &N);
  
  /* Alocando espaco para os ponteiros */
  campo = malloc(M* sizeof(int *));
  for(i=0;i<M;i++){
    campo[i] = malloc(N* sizeof(int));
  }
  pDiagoDroidsMortos = malloc((M+N-1) * sizeof(int));
  nDiagoDroidsMortos = malloc((M+N-1) * sizeof(int));
  lDroidsMortos = malloc(M * sizeof(int));
  cDroidsMortos = malloc(N * sizeof(int));

  /* Inicializa vetores */
  for(i=0;i<(M+N-1);i++){
    pDiagoDroidsMortos[i] = 0;
    nDiagoDroidsMortos[i] = 0;
    if(i<M)
      lDroidsMortos[i] = 0;
    if(i<N)
      cDroidsMortos[i] = 0;
  }

  /* Entrada da matriz campo */
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      scanf("%d", &campo[i][j]);
    }
  }

  /* Calcula o valor de droids em uma linha, coluna, diagonalP e diagonalN */
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      lDroidsMortos[i] += campo[i][j];
      cDroidsMortos[j] += campo[i][j];
      pDiagoDroidsMortos[M-1-i+j] += campo[i][j];
      nDiagoDroidsMortos[M+N-2-i-j] += campo[i][j];
    }
  }

  /* Inicializa nDroidsMax e disparosMax com valores adequados*/
  nDroidsMax = 0;
  disparosMax = 5;
  /* Calcula o valor dos droids a serem mortos e a quantidade de disparos */
  for(i=0;i<M;i++){
    for (j=0;j<N;j++){
      if(campo[i][j] == 0){
        nDroids = lDroidsMortos[i] + 
                  cDroidsMortos[j] +
                  pDiagoDroidsMortos[M-1-i+j] +
                  nDiagoDroidsMortos[M+N-2-i-j];

        disparos = (lDroidsMortos[i]>0) +
                   (cDroidsMortos[j]>0) +
                   (pDiagoDroidsMortos[M-1-i+j]>0) +
                   (nDiagoDroidsMortos[M+N-2-i-j]>0);
        /* Encontra o maior valor para nDroids e menor numero de disparos */
        if(nDroids > nDroidsMax || (nDroids == nDroidsMax && disparos < disparosMax)){
          nDroidsMax = nDroids;
          disparosMax = disparos;
          posI = i;
          posJ = j;
        }
      }
    }
  }

  /* Imprime saida */
  printf("Posicao = (%d,%d)\n",posI,posJ);
  printf("Droids = %d\n", nDroidsMax);
  printf("Disparos = %d\n", disparosMax);

  /* Desaloca espacos */
  free(campo);
  free(lDroidsMortos);
  free(cDroidsMortos);
  free(pDiagoDroidsMortos);
  free(nDiagoDroidsMortos);
  return 0;
}