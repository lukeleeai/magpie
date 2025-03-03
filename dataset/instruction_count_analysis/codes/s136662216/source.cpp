#include <algorithm>

#include <cstdio>

using namespace std;

int n, k;

long long int a[200005], s[200005], ps = 0;

const long long MOD = 1e9 + 7;

int main() {

  scanf("%d %d", &n, &k);

  long long res = 1;

  for (int i = 0; i < n; ++i) {

    scanf("%lld", &a[i]);

  }

  sort(a, a + n);



  if (k % 2) {

    res = a[n - 1];

    int w = res > 0 ? 1 : -1;

    int l = 0, r = n - 2, cnt = 1;

    while (cnt < k && l < r) {

      if (w * a[l] * a[l + 1] > w * a[r] * a[r - 1]) {

        s[ps++] = a[l++];

        s[ps++] = a[l++];

        cnt += 2;

      } else {

        s[ps++] = a[r--];

        s[ps++] = a[r--];

        cnt += 2;

      }

    }

  } else {

    res = 1;

    int l = 0, r = n - 1, cnt = 0;

    while (cnt < k && l < r) {

      if (a[l] * a[l + 1] > a[r] * a[r - 1]) {

        s[ps++] = a[l++];

        s[ps++] = a[l++];

        cnt += 2;

      } else {

        s[ps++] = a[r--];

        s[ps++] = a[r--];

        cnt += 2;

      }

    }

  }

  for (int i = 0; i < ps; ++i) {

    res = (1l * (s[i] % MOD) * (res % MOD) + MOD) % MOD;

  }

  res = (res % MOD + MOD) % MOD;

  printf("%lld\n", res);

  return 0;

}
