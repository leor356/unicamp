#include <stdio.h>
#include <math.h>

int main() {
  
  double n, i, c = 2, r;

  printf("informe o valor:");
  scanf("%lf",&i);
  
  for(n=0;n<i;n++){
    for ( c = 2 ; c <= n-1 ; c++ ){
      if ( (int)n%(int)c == 0 ){
	/*printf("%d: numero composto\n", n);*/
	n+=1;
      }
    }
    
    if ( c == n ){
      r = ((pow(2,n))-1)*(pow(2, n-1));
      printf("%.0f : %.0f: numero perfeito\n", n, r);

    }
  }
  return 0;
}