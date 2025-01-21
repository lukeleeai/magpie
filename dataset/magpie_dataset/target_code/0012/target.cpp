#include <stdio.h>

#include <math.h>



int main(void){

  int n;

  scanf("%d", &n);

  long int ans = 1;

  

  for(int i = 1; i <= n; i++){

    ans = (ans * i) % (int)(pow(10, 9) + 7);

  }

  

  printf("%ld\n", ans);

  return 0;

}