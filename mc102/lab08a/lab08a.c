/* Laboratorio 08a - BigCalc
 * Nome: Leonardo de Oliveira Ramos
 * RA: 171941
 */

#include <stdio.h>
#include <stdlib.h>

/* Soma os 2 valores casa por casa */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
  int i=1, flag=0;
  do{
    if(i - 1 < tam_n2){
      result[tam_n1-i+1] = n1[tam_n1-i] + n2[tam_n2-i] + flag;
    }else{
      result[tam_n1-i+1] = n1[tam_n1-i] + flag;
    }
    if(result[tam_n1-i+1] > 10){
      result[tam_n1-i+1] -= 10;
      flag=1;
    }else{
      flag=0;
    }
    
  }while(i++<=tam_n1);
}

/* Subtrai os 2 valores casa por casa */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
  int i=1, flag=0;
  do{
    if(i - 1 < tam_n2){
      result[tam_n1-i] = n1[tam_n1-i] - n2[tam_n2-i] - flag;
    }else{
      result[tam_n1-i] = n1[tam_n1-i] - flag;
    }
    if(result[tam_n1-i] < 0){
      result[tam_n1-i] += 10;
      flag=1;
    }else{
      flag=0;
    }
    
  }while(i++<tam_n1);
}

/* Multiplica os 2 valores casa por casa */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
  int i, j;
  for(i=0;i<=tam_n1+tam_n2;i++)
    result[i] = 0;
  for(i=1;i<=tam_n1;i++){
    for(j=1;j<=tam_n2;j++){
      /* Coloca o valor da multiplicacao em result[i] 
        e passa os digitos excedidos pra proxima casa */
      result[tam_n1+tam_n2-i-j+1] += n1[tam_n1-i] * n2[tam_n2-j];
      if(result[tam_n1+tam_n2-i-j+1] >=10 && tam_n1+tam_n2-i-j > 0){
        result[tam_n1+tam_n2-i-j] += result[tam_n1+tam_n2-i-j+1] / 10;
        result[tam_n1+tam_n2-i-j+1] = result[tam_n1+tam_n2-i-j+1] % 10;
      }
    }
  }
}

int main() {
  /* 
    *num1 e *num2 sao os ponteiros correspondentes a n1 e n2
    *res eh o ponteiro correspondente a resposta
    X, Y sao os valores limite de digitos para num1 e num2
    C eh o caractere que seleciona a operacao
    tamRes eh o tamanho de *res
    i eh um contador
    charNum1 e charNum2 sao ponteiros para char que servem para fazer a entrada corretamente
  */
  int X, Y, *num1, *num2, tamRes, *res, i, flag=0;
  char C, *charNum1, *charNum2;
  
  /* Entrada de valores e alocacao de memoria dos ponteiros e conversao de char para int */
  scanf("%d %d %c", &X, &Y, &C);
  charNum1 = malloc(X*sizeof(char));
  charNum2 = malloc(Y*sizeof(char));
  num1 = malloc(X*sizeof(int));
  num2 = malloc(Y*sizeof(int));
  for(i=0;i<X;i++){
    scanf(" %c", &charNum1[i]);
    num1[i] = charNum1[i] - '0';
  }
  for(i=0;i<Y;i++){
    scanf(" %c", &charNum2[i]);
    num2[i] = charNum2[i] - '0';
  }
  
  /*  Aloca a memoria necessaria e seleciona a funcao desejada */
  if(C=='A'){
    tamRes = X + 1;
    res = malloc((tamRes)*sizeof(int));
    add(num1, X, num2, Y, res);
  }else if(C=='S'){
    tamRes = X;
    res = malloc((tamRes)*sizeof(int));
    substract(num1, X, num2, Y, res);
  }else if(C=='M'){
    tamRes = X + Y;
    res = malloc((tamRes+2)*sizeof(int));
    multiply(num1, X, num2, Y, res);
  }
  
  /* Imprime a saida sem os 0 nao significativos */
  for(i=0;i<tamRes;i++){
    if(res[i])
      flag =1;
    if(flag)
      printf("%d", res[i]);
  }
  if (flag==0)
    printf("0");
  printf("\n");
  
  /* Liberando a memoria */
  free(num1);
  free(num2);
  free(charNum1);
  free(charNum2);
  free(res);
  
  return 0;
}  
