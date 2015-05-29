#include <stdio.h>

  int main() {
    
  char string[81], inversa[81];
  int n, i;
  
  printf("Digite uma string: ");
  fgets(string, 81, stdin);
  
  /* equivalente a n = strlen(string) da biblioteca string.h */
  n = 0;
  while (string[n] != '\0'){
    n++;
  }
  
  inversa[n] = '\0';
  for(i=0;i<n; i++){
    inversa[i] = string[n - i - 1];
  }
  
  printf("Tamanho da string = %d\n", n);
  printf("%s\n", inversa);
  
  return 0;
}