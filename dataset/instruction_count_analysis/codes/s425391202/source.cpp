#include "stdc++.h"

using namespace std;

 

typedef long long LL;

typedef pair <int,int> pii;

const double pi = acos(-1.0);

const double eps = 1e-8;

const int mod = 1e9 + 7;

const int inf = 1e9;

const LL INF = 1e18;

const int N = 1e5 + 5;

 

int main() {

  ios_base::sync_with_stdio(0); cin.tie(0);

  #ifdef LOCAL

    freopen("input.txt", "r", stdin);

  #endif

  LL a, b, c, k;

  cin >> a >> b >> c >> k;

  LL ans = 0;

  ans += min(k, a);

  k -= min(k, a);

  k -= min(k, b);

  ans -= min(k, c);

  cout << ans << endl;

  return 0;

}