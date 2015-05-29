/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void copiaString(char *str1, char *str2){
  int i=0;
  do{
    str1[i] = str2[i];
  }while(str2[i++] != '\0');
}

void troca(int *X, int *Y){
  int aux = *X;
  *X = *Y;
  *Y = aux;
}

int encontraNoTexto(char **texto, int palavrasNoTexto, char *palavra){
  int cmp, i;
  for(i=0;(i<palavrasNoTexto);i++){
    cmp = strcmp(palavra, texto[i]);
    if(!cmp)
      return i;
  }
  return -1;
}

void insertion(char **texto, int palavrasNoTexto, char *palavra, int *bucketPalavras, int tamPalavra){
  int i;
  char *aux;

  aux = malloc(tamPalavra* sizeof(char));

  copiaString(aux, palavra);

  for (i = palavrasNoTexto - 1; (i >= 0) && (strcmp(palavra, texto[i]) < 0); i--){
    copiaString(texto[i+1], texto[i]);
    troca(&bucketPalavras[i+1], &bucketPalavras[i]);
  }

  copiaString(texto[i+1], aux);
  bucketPalavras[i+1]++;
}


int main(){
  int D, F, L, M, i, j, k;
  int tamPalavra, *bucketPalavras, posPalavra;
  int palavrasNoTexto=0, maiorRepeticaoDasPalavras=0;
  char **texto, *palavra;

  scanf("%d %d %d %d", &D, &F, &L, &M);
  
   /* Aloca espaco para os vetores e inicializa texto[i][j] */
  bucketPalavras = malloc((D+1) * sizeof(int));
  palavra = malloc((M+1) * sizeof(char));
  texto = malloc((D+1) * sizeof(char *));
  for(i=0;i<(D+1);i++)
    texto[i] = malloc((M) * sizeof(char));
  for(i=0;i<D;i++){
    bucketPalavras[i] = 0;
  }

  scanf(" ");

  /* Le palavra por palavra e coloca na matriz texto caso entre na condicao */
  do{
    scanf("%s", palavra);
    tamPalavra = strlen(palavra);
    if (tamPalavra>=L){
      posPalavra = encontraNoTexto(texto, palavrasNoTexto, palavra);
      if(posPalavra == -1){
        insertion(texto, palavrasNoTexto, palavra, bucketPalavras, tamPalavra);
        palavrasNoTexto++;
      }else{
        bucketPalavras[posPalavra]++;
      }

    }
  }while(palavra[tamPalavra - 1] != '*');  

  /* Procura a maior recorrencia de palavras */
  for(i=0;i<D;i++)
    if(maiorRepeticaoDasPalavras < bucketPalavras[i])
      maiorRepeticaoDasPalavras = bucketPalavras[i];

  /*
  for(i=0;i<palavrasNoTexto;i++){
    printf("%s ", texto[i]);
    printf("%d\n", bucketPalavras[i]);
  }
*/
  /* Imprime em ordem decrescente de recorrencia */
  for (i=maiorRepeticaoDasPalavras;i>=F;i--){
    for(j=0;j<palavrasNoTexto;j++){
      if(bucketPalavras[j] == i){
        k=0;
        while(texto[j][k] != '\0'){
          printf("%c",texto[j][k]);
          k++;
        }
        printf(" %d\n", bucketPalavras[j]);
      }
    }
  }

  /* Libera os espacos utilizados */
  free(bucketPalavras);
  free(palavra);
  free(texto);
  return 0;
}
