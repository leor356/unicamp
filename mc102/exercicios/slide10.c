#include <stdio.h>
int x = 1;
void funcao1() {
  x = 4;
  printf("%d\n", x); /* 3 */
}
void funcao2() {
  int x = 5;
  printf("%d\n", x); /* 4 */
}
int main() {
  
  x = 2;
  
  printf("%d\n", x);
  
  funcao1();
  printf("%d\n", x);
  
  funcao2();
  printf("%d\n", x); /* 3 */
  
  return 0;
}