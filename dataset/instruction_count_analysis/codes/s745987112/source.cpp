#include <algorithm>

#include <cstring>

#include <deque>

#include <functional>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <vector>

using namespace std;

#define fst first

#define snd second

using ll = long long;

using I = pair<int, int>;

const int D = 16;



ll g(ll n, int k) {

  vector<int> dig(D, 0), sum(D + 1, 0);

  for (int i = 0; i < D; i++) {

    dig[i] = n % 10;

    sum[i + 1] = sum[i] + dig[i];

    n /= 10;

  }

  ll m = 0;

  bool eq = true;

  for (int i = D - 1, j = D - 1; i > 0; i--) {

    j = min(i - 1, j);

    while (j >= 0 && dig[j] == 9) --j;

    for (int d = eq ? dig[i] : 0; d <= 9; d++) {

      bool neq = eq & (d == dig[i]);

      int mn = 0, mx = 9 * i;

      if (neq) {

        mn += 9 * (i - j - 1);

        if (j >= 0) {

          mn += sum[j + 1] == dig[j] ? dig[j] : dig[j] + 1;

        }

      }

      if (mn <= k - d && k - d <= mx) {

        m = m * 10 + d;

        k -= d;

        eq = neq;

        break;

      }

    }

  }

  m = m * 10 + k;

  return m;

}



ll f(ll n) {

  ll p = 1, q = 0;

  for (ll k = 1; k <= D * 9; k++) {

    ll m = g(n, k);

    if (p * k > m * q || (p * k == m * q && m < p)) {

      p = m;

      q = k;

    }

  }

  return p;

}



int main() {

  int K;

  while (cin >> K) {

    vector<ll> res;

    res.push_back(1);

    while (res.size() < K) {

      ll n = res.back();

      res.push_back(f(n + 1));

    }

    for (ll x : res) cout << x << endl;

  }

  return 0;

}
