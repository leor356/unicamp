/* Laboratorio 08a - BigCalc
 * Nome: Leonardo de Oliveira Ramos
 * RA: 171941
 */

#include <stdio.h>
#include <stdlib.h>

void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
    int i=1, flag=0;
    do{
      if(i - 1 < tam_n2){
        result[tam_n1-i+1] = n1[tam_n1-i] + n2[tam_n2-i] + flag;
        /*printf("%d: Adicao de %d por %d = %d\n",i , n1[tam_n1-i], n2[tam_n2-i], result[tam_n1-i+1]);*/
      }else{
        result[tam_n1-i+1] = n1[tam_n1-i] + flag;
        /*printf("%d: Adicao de %d = %d\n",i , n1[tam_n1-i], result[tam_n1-i+1]);*/
      }
      if(result[tam_n1-i+1] > 10){
        result[tam_n1-i+1] -= 10;
        flag=1;
      }else{
        flag=0;
      }
      
    }while(i++<tam_n1);
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i=1, flag=0;
    do{
      if(i - 1 < tam_n2){
        result[tam_n1-i] = n1[tam_n1-i] - n2[tam_n2-i] - flag;
        /*printf("%d: Subtracao de %d por %d = %d\n",i , n1[tam_n1-i], n2[tam_n2-i], result[tam_n1-i]);*/
      }else{
        result[tam_n1-i] = n1[tam_n1-i] - flag;
        /*printf("%d: Subtracao de %d = %d\n",i , n1[tam_n1-i], result[tam_n1-i]);*/
      }
      if(result[tam_n1-i] < 0){
        result[tam_n1-i] += 10;
        flag=1;
      }else{
        flag=0;
      }
      
    }while(i++<tam_n1);
}

/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, j, aux;
    for(i=0;i<tam_n1*tam_n2;i++)
      result[i] = 0;
    for(i=1;i<=tam_n2;i++){
      for(j=1;j<=tam_n1;j++){
        result[tam_n1+tam_n2-i-j+1] += n2[tam_n2-i] * n1[tam_n1-j];
        if(result[tam_n1+tam_n2-i-j+1] >=10){
          aux = result[tam_n1+tam_n2-i-j+1] / 10;
          result[tam_n1+tam_n2-i-j+1] = result[tam_n1+tam_n2-i-j+1] % 10;
          result[tam_n1+tam_n2-i-j] += aux;
        }
        /*printf("%d, %d: Mult de %d por %d = %d\n",i , j, n2[tam_n2-i], n1[tam_n1-j], result[(tam_n1+tam_n2)-i-j+1]);*/
      }
    }
}

int main() {    
  int X, Y, *num1, *num2, tamRes, *res, i, flag=0;
  char C, *charNum1, *charNum2;
  
  scanf("%d %d %c", &X, &Y, &C);
  
  charNum1 = malloc(X*sizeof(char));
  charNum2 = malloc(Y*sizeof(char));
  num1 = malloc(X*sizeof(int));
  num2 = malloc(Y*sizeof(int));
  
  for(i=0;i<X;i++){
    scanf(" %c", &charNum1[i]);
    num1[i] = charNum1[i] - '0';
    /*printf("Coloca em N1[%d] %d\n",i , num1[i]);*/
  }
  for(i=0;i<Y;i++){
    scanf(" %c", &charNum2[i]);
    num2[i] = charNum2[i] - '0';
    /*printf("Coloca em N2[%d] %d\n",i , num2[i]);*/
  }
  /*printf("%d %d %c\n", X, Y, C);*/
  if(C=='A'){
    tamRes = X + 1;
    res = malloc((tamRes)*sizeof(int));
    add(num1, X, num2, Y, res);
  }else if(C=='S'){
    tamRes = X;
    res = malloc((tamRes)*sizeof(int));
    substract(num1, X, num2, Y, res);
  } else if(C=='M'){
    tamRes = X + Y;
    res = malloc((tamRes)*sizeof(int));
    multiply(num1, X, num2, Y, res);
  }
  
  for(i=0;i<tamRes;i++){
    if(res[i])
      flag =1;
    if(flag)
      printf("%d", res[i]);
  }
  if (flag==0)
    printf("0");  
  printf("\n");
  
  free(charNum1);
  free(charNum2);
  free(num1);
  free(num2);
  free(res);
  
  
  return 0;
}  
