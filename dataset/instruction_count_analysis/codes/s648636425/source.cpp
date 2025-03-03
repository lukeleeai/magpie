#define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

#define all(v) v.begin(), v.end()

#define allr(v) v.rbegin(), v.rend()





int main() {

  ll n;

  cin >> n;

  vector<ll> a(1100000);

  rep(i, 3*n) cin >> a[i];

  sort(&a[0], &a[0]+n*3);

  

  ll ans = 0;

  for (int i = 0; i < n; i++) {

    ans += a[n + 2*i];

  }

  cout << ans << endl;

}


