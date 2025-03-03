#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

typedef long long li;



const int maxn = 1e5;

int n, a[maxn], b[maxn];



int main(void) {

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {

    scanf("%d%d", a + i, b + i);

  }

  li ans = 0;

  for (int i = n - 1; i >= 0; --i) {

    li cur = a[i] + ans;

    li tar = (cur + b[i] - 1) / b[i] * b[i];

    ans += tar - cur;

  }

  printf("%lld\n", ans);

}
