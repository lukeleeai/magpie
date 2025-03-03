#include <stdint.h>

#include <stdio.h>



int main(void) {

  int64_t N;

  // cin >> N;

  scanf("%ld", &N);

  int64_t a[5];

  for (int64_t i = 0; i < 5; ++i) scanf("%ld", a + i);

  int64_t mn = 1000000000000000;



  for (int64_t i = 0; i < 5; ++i) {

    if (a[i] < mn) {

      mn = a[i];

    }

  }

  printf("%ld\n", (N + mn - 1) / mn + 4);



  return 0;

}
