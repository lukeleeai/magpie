#include <iostream>

using namespace std;

typedef long long ll;

ll M = 1000000007LL;

ll inv(ll K) {

  ll A = M - 2;

  ll ret = 1;

  ll D = K;

  while (A > 0) {

    if (A % 2 == 1) {

      ret = (ret * D) % M;

    }

    D = (D * D) % M;

    A /= 2;

  }

  return ret;

}

ll F[2000005];

ll I[2000005];

int main() {

  ios::sync_with_stdio(false);

  ll r1, c1, r2, c2;

  cin >> r1 >> c1 >> r2 >> c2;

  ll ret = 0;

  F[0] = 1;

  for (ll i = 1; i <= r2+c2+1; i++) {

    F[i] = (F[i-1] * i) % M;

  }

  I[r2+c2+1] = inv(F[r2+c2+1]);

  for (ll i = r2+c2; i >= 0; i--) {

    I[i] = (I[i+1] * (i+1)) % M;

  }

  for (ll i = c1; i <= c2; i++) {

    // sum(f(i+j, i)) = f(i+r2+1, i+1)

    // f(i+r2+1, i+1) = (i+r2+1)! / ((i+1)! * (r2)!)

    ll R = F[i+r2+1];

    //R = (R * inv(F[i+1])) % M;

    //R = (R * inv(F[r2])) % M;

    R = (R * I[i+1]) % M;

    R = (R * I[r2]) % M;

    // sum(f(i+j, i)) = f(r1, i+1)

    // f(i+r1, i) = (i+r1)! / ((i+1)! * (r1-1)!)

    ll L = F[i+r1];

    //L = (L * inv(F[i+1])) % M;

    //L = (L * inv(F[r1-1])) % M;

    L = (L * I[i+1]) % M;

    L = (L * I[r1-1]) % M;

    //cout << R << ' ' << L << endl;

    ret = (ret + R) % M;

    ret = ((ret - L) % M + M) % M;

  }

  cout << ret << endl;

}