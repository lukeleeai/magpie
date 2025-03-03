#include <cstdio>

#include <algorithm>



using namespace std;



long long N, H;

long long b[100010], a = 0;



int main() {

  int i;

  scanf("%lld %lld", &N, &H);

  long long sum = 0;

  for (i = 0; i < N; i++) {

    long long k;

    scanf("%lld %lld", &k, &b[i]);

    a = max(a, k);

  }

  sort(b, b+N);

  /*for (i = 0; i < N; i++) {

    printf("a:%d b:%d", a[i], b[i]);

    }*/

  long long ans = 0;

  for (i = N-1; i >= 0 && b[i] > a; i--) {

    H -= b[i];

    ans += 1;

    if (H <= 0) {

      break;

    }

  }

  //printf("after_b:%d", ans);

  if (H >= 0) {

    long long num_a = H / a;

    ans += num_a;

    if (H % a > 0) {

      ans += 1;

    }

  }

  printf("%lld", ans);

  return 0;

}

  