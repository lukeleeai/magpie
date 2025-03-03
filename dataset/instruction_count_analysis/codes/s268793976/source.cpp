#include "stdc++.h"

using namespace std;



const int Maxn = 100005;

struct node {

  long long l, r, x, d;

  node(long long l, long long r, long long x, long long d) : 

    l(l), r(r), x(x), d(d) { }

  node() { l = r = x = d = 0; }

  bool operator<(const node &b) const {

    return l < b.l;

  }

};

int n, b[Maxn];

long long k, ans;

long long a[Maxn];

set <node> st;

int main() {

  scanf("%d %lld", &n, &k), ans = 0;

  for (int i = 0; i < n; ++i) {

    scanf("%lld %d", a + i, b + i);

    ans += (a[i] <<= 1);

    if (a[i] > k && b[i] == 1) 

      return puts("-1") & 0;

    if (b[i] == 2) a[i] %= k;

  } st.insert({0, k, 0, 0});

  long long cur = 0;

  for (int i = 0; i < n; ++i) {

    long long d = a[i];

    long long nx = cur + d;

    (nx > k) && (nx -= k);

    if (b[i] == 1) {

      if (cur < nx) {

        auto it = st.lower_bound({cur, 0, 0, 0});

        while (it -> r < nx) st.erase(it ++);

        node x1 = *it, x2 = *it;

        st.erase(it), x2.l = nx;

        long long now = x2.x + x2.d * (x2.r - nx);

        x1 = node(cur, nx, now, 1);

        st.insert(x1);

        if (x2.l ^ x2.r) st.insert(x2);

      } else {

        auto it = st.lower_bound({cur, 0, 0, 0});

        while (it != st.end()) st.erase(it ++);

        it = st.begin();

        while (it -> r < nx) st.erase(it ++);

        node x1 = *it, x2 = *it;

        st.erase(it), x2.l = nx;

        long long now = x2.x + x2.d * (x2.r - nx);

        x1 = node(0, nx, now, 1);

        st.insert(x1);

        if (x2.l != x2.r) st.insert(x2);

        now = x1.x + x1.d * x1.r;

        x2 = node(cur, k, now, 1);

        st.insert(x2);

      } cur = (cur + a[i]) % k;

    } else {

      (cur += a[i]) %= k;

      auto it = st.lower_bound({cur, 0, 0, 0});

      if (it == st.begin()) continue;

      if ((-- it) -> r <= cur) continue;

      node x1 = *it, x2 = *it;

      st.erase(it), x2.l = cur;

      x1.x = x2.x + x2.d * (x2.r - cur);

      x1.r = cur;

      st.insert(x1), st.insert(x2);

    }

  }

  long long mn = st.begin() -> x;

  for (auto x: st)

    mn = min(mn, x.x);

  printf("%lld\n", ans + mn);

  return 0;

}