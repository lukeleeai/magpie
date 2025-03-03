#include<stdio.h>



int main() { 

  long long  n, m, ans = 1;

  scanf("%Ld %Ld", &n, &m);

  if( n-m > 1 || m-n > 1){

    printf("%d\n", 0);

    return 0;

  }

  int i;

  for(i = 0; i < n; i++){

    ans *= (i + 1);

    ans %= 1000000007;

  }

  for(i = 0; i < m; i++){

    ans *= (i + 1);

    ans %= 1000000007;

  }

  if(n == m){

    ans *= 2;

  }

  ans %= 1000000007;

  printf("%Ld\n", ans);

  return 0;

}