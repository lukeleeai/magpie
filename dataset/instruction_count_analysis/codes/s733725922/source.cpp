#include "stdc++.h"



#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const int INF = 1e9;



ll a, b, n, c1, c2, ans = 0;



ll f(ll x) { return floor(a * x / b) - a * floor(x / b); }



ll g(ll x) {

  ll l = 0, r = n + 1;

  rep(i, 100) {

    c1 = (l * 2 + r) / 3;

    c2 = (r * 2 + l) / 3;

    f(c1) < f(c2) ? l = c1 : r = c2;

  }

  return f(l);

}



int main() {

  cin >> a >> b >> n;



  ll l = 0, r = n + 1;

  rep(i, 100) {

    c1 = (l * 2 + r) / 3;

    c2 = (r * 2 + l) / 3;

    g(c1) < g(c2) ? l = c1 : r = c2;

  }

  if (f(0) > f(r)) r = 0;

  else if (f(n) > f(r)) r = n;

  cout <<  f(r) << endl;

  return 0;

}
