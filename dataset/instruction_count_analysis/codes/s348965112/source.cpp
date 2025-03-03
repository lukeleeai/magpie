#include <stdio.h>



int n, sum;



int main() {

  scanf("%d", &n);

  int x = n;

  while (x) {

    sum += x % 10;

    x /= 10;

  }

  puts(n % sum ? "No" : "Yes");

  return 0;

}


