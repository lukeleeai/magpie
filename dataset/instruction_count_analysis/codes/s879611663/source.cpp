#include <cstdio>



int main() {

  int n;

  scanf("%d", &n);



  int max_a = 0;

  int res = 0;

  for (int i = 0; i < n; ++i) {

    int a, b;

    scanf("%d %d", &a, &b);

    if (a > max_a) {

      max_a = a;

      res = a + b;

    }

  }

  printf("%d\n", res);

}
