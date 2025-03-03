#include"stdc++.h"



using namespace std;

typedef long long ll;



const ll INF = 1e9;

const ll MOD = 1e9 + 7;



int main() {

  int N;

  ll C;

  cin >> N >> C;



  vector<ll> x(N + 1, 0), v(N + 1, 0), rwv(N + 1, 0);

  for (int i = 1; i <= N; i++) {

    cin >> x[i] >> v[i];

  }



  // 累積和

  for (int i = 0; i < N; i++) {

    rwv[i + 1] = rwv[i] + v[i + 1];

  }



  vector<ll> r(N + 1, 0);

  for (int i = 0; i < N; i++) {

    r[i + 1] = max(r[i], rwv[i + 1] - x[i + 1]);

  }



  vector<ll> l(N + 1, 0);

  l[N] = rwv[N] - rwv[N - 1] - (C - x[N]);

  for (int i = N - 1; i >= 1; i--) {

    l[i] = max(l[i + 1], rwv[N] - rwv[i - 1] - (C - x[i]));

  }



  ll ans = 0;

  for (int i = 1; i <= N; i++) {

    ans = max(ans, rwv[i] - x[i]);

    if (i < N) {

      ans = max(ans, rwv[i] - 2 * x[i] + l[i + 1]);

    }

  }



  for (int i = N - 1; i >= 0; i--) {

    ans = max(ans, rwv[N] - rwv[i] - (C - x[i + 1]));

    if (i > 0) {

      ans = max(ans, rwv[N] - rwv[i] - 2 * (C - x[i + 1]) + r[i]);

    }

  }

  cout << ans << endl;



  return 0;

}
