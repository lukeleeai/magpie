#include "stdc++.h"

#define rep(i, x, y) for (int i = x; i <= y; i++)

using namespace std;



const int N = 2e3 + 10, mod = 1e9 + 7;

typedef long long ll;

ll n, K;

ll fac[N * N], f[N][N], inv[N * N];



ll quick_pow(ll a, ll b) {

    ll ret = 1;

    for (; b; b >>= 1) {

        if (b & 1) ret = ret * a % mod;

        a = a * a % mod;

    } return ret;

}



void pre() {

    fac[0] = inv[0] = 1;

    rep(i, 1, n * K) fac[i] = fac[i - 1] * i % mod;

    inv[n * K] = quick_pow(fac[n * K], mod - 2);

    for (int i = n * K - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

}



ll C(ll n, ll m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }



ll upd(ll x, ll y) { return (x + y) % mod; }



int main() {

    cin >> n >> K;

    if (K == 1) { puts("1"); return 0; }

    pre();

    rep(i, 1, n) f[i][0] = 1;

    rep(i, 1, n)

        rep(j, 1, i) {

            f[i][j] = upd(f[i - 1][j], (n - j + 1) * f[i][j - 1] % mod * C((n - j + 1) * (K - 1) + n - i - 1, K - 2) % mod);

        }

    printf("%lld\n", f[n][n]);

    return 0;

}
