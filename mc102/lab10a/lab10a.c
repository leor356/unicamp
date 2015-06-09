/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Copia string2 na string1*/
void copiaString(char *str1, char *str2){
  int i=0;
  do{
    str1[i] = str2[i];
  }while(str2[i++] != '\0');
}

/* Encontra a string palavra no vetor de strings texto[i](ou matriz texto[i][j]) */
int encontraNoTexto(char **texto, int palavrasNoTexto, char *palavra){
  int i;
  for(i=0;(i<palavrasNoTexto);i++)
    if(!(strcmp(palavra, texto[i])))
      return i;
  return -1;
}

/* Coloca a string palavra ordenadamente em texto[i] sempre associando o mesmo bucketPalavras[] */
void insertion(char **texto, int palavrasNoTexto, char *palavra, int *bucketPalavras, int tamPalavra){
  int i, aux;

  aux = bucketPalavras[palavrasNoTexto];

  for (i = palavrasNoTexto - 1; (i >= 0) && (strcmp(palavra, texto[i]) < 0); i--){
    copiaString(texto[i+1], texto[i]);
    bucketPalavras[i+1] = bucketPalavras[i];
  }

  copiaString(texto[i+1], palavra);
  bucketPalavras[i+1] = aux + 1;
}


int main(){
  /*
    D eh o numero maximo de palavras diferentes
    F eh o valor minimo de recorrencia para considerar na estatistica
    L eh o numero minimo de caracteres para considerar na estatistica
    M eh o numero maximo de caracteres para considerar na estatistica
    i, j sao contadores
    palavra[i] eh a string que recebe a entrada de cada palavra a ser analizada
    texto[i][j] eh o vetor de strings que recebe as palavras consideradas
    bucketPalavras eh um vetor que tem a recorrência da palavra [i]
    posPalavra eh a posicao i da palavra em texto[i][j]
    palavrasNoTexto eh o numero de palavras em texto[i][j]
    maiorPNT eh o maior valor de palavrasNoTexto
  */
  int D, F, L, M, i, j;
  int tamPalavra, *bucketPalavras, posPalavra;
  int palavrasNoTexto=0, maiorPNT=0;
  char **texto, *palavra;

  scanf("%d %d %d %d", &D, &F, &L, &M);
  
   /* Aloca espaco para os vetores e inicializa texto[i][j] */
  bucketPalavras = malloc(D * sizeof(int));
  palavra = malloc((M+1) * sizeof(char));
  texto = malloc(D * sizeof(char *));
  for(i=0;i<D;i++){
    texto[i] = malloc((M+1) * sizeof(char));
    bucketPalavras[i] = 0;
  }

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
    if(maiorPNT < bucketPalavras[i])
      maiorPNT = bucketPalavras[i];

  /* Imprime em ordem decrescente de recorrencia */
  for (i=maiorPNT;i>=F;i--)
    for(j=0;j<palavrasNoTexto;j++)
      if(bucketPalavras[j] == i){
        printf("%s ",texto[j]);
        printf("%d\n", bucketPalavras[j]);
      }
    


  /* Libera os espacos utilizados */
  free(bucketPalavras);
  free(palavra);
  free(texto);
  return 0;
}
