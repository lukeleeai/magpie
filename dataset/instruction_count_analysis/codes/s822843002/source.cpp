#include "stdc++.h"

using namespace std;

const int maxn = 2e5 + 10;

const long long inf = 1e16;

long long pre[maxn], suf[maxn];

struct data {

  int a, b, c;

  data () {}

  bool operator < (data d) const {

    return b - a < d.b - d.a;

  }

} arr[maxn];

int t[maxn * 4];

long long sum[maxn * 4];

int rev[maxn];

int idx;



void add(int x, int c = 1, int b = 1, int e = idx) {

  if(b == e) {

    t[c] += 1;

    sum[c] += rev[b];

    return ;

  }

  int m = (b + e) >> 1;

  int l = c << 1;

  int r = l + 1;

  if(x <= m) add(x, l, b, m);

  else add(x, r, m + 1, e);

  t[c] = t[l] + t[r];

  sum[c] = sum[l] + sum[r];

}

long long get(int x, int c = 1, int b = 1, int e = idx) {

  if(b == e) {

    return 1LL * rev[b] * x;

  }

  int m = (b + e) >> 1;

  int l = c << 1;

  int r = l + 1;

  if(t[r] >= x) return get(x, r, m + 1, e);

  else return sum[r] + get(x - t[r], l, b, m);

}

int main() {

  ios_base :: sync_with_stdio (false); cin.tie(0);

  int X, Y, Z;

  cin >> X >> Y >> Z;

  int n = X + Y + Z;

  map <int, int> cmp;

  for(int i = 1; i <= n; i++) {

    cin >> arr[i].a >> arr[i].b >> arr[i].c;

    cmp[arr[i].c - arr[i].a];

    cmp[arr[i].c - arr[i].b];

  }

  sort(arr + 1, arr + n + 1);

  for(auto &i : cmp) {

    i.second = ++idx;

    rev[idx] = i.first;

  }

  long long total = 0;

  for(int i = 1; i <= n; i++) {

    int x = cmp[arr[i].c - arr[i].a];

    add(x);

    total += arr[i].a;

    if(i >= X) pre[i] = total + get(i - X);

    else pre[i] = -inf;

  }

  memset(t, 0, sizeof t);

  memset(sum, 0, sizeof sum);

  total = 0;

  for(int i = n; i >= 1; i--) {

    int x = cmp[arr[i].c - arr[i].b];

    add(x);

    total += arr[i].b;

    if(n - i + 1 >= Y) suf[i] = total + get(n - i + 1 - Y);

    else suf[i] = -inf;

  }

  long long ans = -inf;

  for(int i = 1; i < n; i++) {

    ans = max(ans, pre[i] + suf[i + 1]);

  }

  cout << ans << endl;

  return 0;

}
