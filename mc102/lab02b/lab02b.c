/* 
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: MC102R
*/
#include <stdio.h>
int main() {
  
  /*
   ncasas eh o numero de casas 
   qouro eh a quantidade de ouro
   pcasas[n] eh o valor da potencia da n-esima casa
   tx eh a taxa de cambio 
   i, k, l sao variaveis para contagem
   dolares eh o valor do ouro em dolares elficos
   res[n] eh a menor quantidade de notas da n-esima casa de cambio
   min eh a menor quantidade de notas possivel   
   */
  int ncasas, qouro, tx, pcasas[20], i, k, l, dolares, res[20], min;

  
  scanf("%d %d %d", &ncasas, &qouro, &tx);
  
  /* inicializacao das variaveis res[n] */
  for(k=0;k<=19;k++ ){
    res[k]=0;
  }
  
  /* calculo do menor numero de notas da i-esima casa */
  for(i=0; i<ncasas; i++){
    scanf("%d", &pcasas[i]);
    dolares = qouro * tx;
    while (dolares > 0){
      if(dolares%pcasas[i]){
	res[i] = res[i] + dolares%pcasas[i];
      }
      
      dolares = dolares/pcasas[i];
    }
  }
  
  /* descobrindo qual eh o menor valor */
  min = res[0];
  for(l=0;l<ncasas;l++){
    if(res[l]<min){
	min=res[l];
    }
  }
  printf("Numero minimo de notas = %d\n", min);


  return 0;
}