#include "stdc++.h"



using namespace std;



#define pb push_back

#define eb emplace_back

#define ll long long

#define pii pair < int, int >

#define fr first

#define sc second

#define mk make_pair

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()

#define ok puts("ok");

#define whatis(x) cerr << #x << " = " << x << endl;

#define pause system("pause");



const int N = (int)1e5 + 7;

const int inf = (int)1e9 + 7;



ll a, b, sq, mx, aa;

ll ans;



ll sqr(ll x) {

  ll l = 1;

  ll r = 1e9;

  while (r - l > 1) {

    ll mid = (l + r) >> 1;

    if (mid * mid <= x) {

      l = mid;

    } else {

      r = mid;

    }

  }

  return l;

}



void solve() {

  scanf("%lld %lld", &a, &b);

  if (a > b) swap(a, b);

  sq = sqr(a * b - 1);

  ans = sq;

  if (a <= sq) {

    ans--;

  }

  mx = (a * b - 1) / (sq + 1);

  if (b <= mx) {

    ans--;

  }

  ans += mx;

  cout << ans << endl;

}



main() {

  int test;

  scanf("%d", &test);

  while (test--) {

    solve();

  }

}
