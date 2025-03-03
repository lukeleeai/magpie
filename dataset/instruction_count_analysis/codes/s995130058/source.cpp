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



int S(ll n) {

  int s = 0;

  while (n > 0) {

    s += n % 10;

    n /= 10;

  }

  return s;

}



ll f(ll n) {

  vector<ll> cand = {n};

  for (ll p = 1; p <= n; p *= 10) {

    int d = (n / p) % 10;

    for (int i = d + 1; i <= 9; i++) {

      ll x = (n / p) - d + i;

      x = x * p + p - 1;

      cand.push_back(x);

    }

  }

  ll p = 1, q = 0;

  for (ll x : cand) {

    ll s = S(x);

    if (p * s > x * q || (p * s == x * q && p > x)) {

      p = x;

      q = s;

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
