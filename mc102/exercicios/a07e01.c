#include <stdio.h>
int main() {
  

  double num, fat, per;
  
  
  
  scanf("%lf", &num);
    
  per = 1;
  fat =2;
    
  while(fat<num){
    if((int)num%(int)fat==0){
      per += fat;
    }
      fat++;
    
  }
  
  if (num == per && num != 1){
    printf("O numero %f eh perfeito\n", num);
  } /*else{
    printf("O numero %d nao eh perfeito\n", num);
  }*/
  
  
  
  return 0;
}