#include <stdio.h>
int main() {
  
  int i, base, potencia, marca;
  
  scanf("%d %d", &base, &potencia);
  
  marca = base;
  
  for(i=1;i<potencia;i++){
    
    base = base * marca;
  }
  printf("%d\n", base);
  
  return 0;
}