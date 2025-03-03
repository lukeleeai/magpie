#include <stdio.h>

#define min(x, y) ((x)<(y) ? (x) : (y))

int main(){

  int n;  scanf("%d", &n);

	int ans = 1<<30;

  while(n--){

    int a;  scanf("%d", &a);

    int count = 0;

    while(a % 2 == 0){

      count++;

      a >>= 1;

    }

    ans = min(ans, count);

  }

  printf("%d\n", ans);

  return 0;

}