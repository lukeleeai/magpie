#include"stdc++.h"

#define int long long

using namespace std;

const int maxN = 2e3 + 13, mod = 1e9 + 7;

int n, k, dp[maxN][maxN], fac[maxN * maxN], rfac[maxN * maxN];



int pw (int a, int b) {

    int ret = 1;

    for (; b; b >>= 1, a = 1ll * a * a % mod)

	if (b & 1)

	    ret = 1ll * ret * a % mod;

    return ret;

}



int c (int a, int b) {

    return 1ll * fac[b] * rfac[a] % mod * rfac[b - a] % mod;

}



int32_t main () {

    cin >> n >> k;

    dp[0][0] = 1;

    fac[0] = rfac[0] = 1;

    for (int i = 1; i <= n * k; i++) {

	fac[i] = 1ll * fac[i - 1] * i % mod;

	rfac[i] = 1ll * rfac[i - 1] * pw(i, mod - 2) % mod;

    }



    for (int i = 1; i <= n; i++)

	for (int j = 0; j <= i; j++) {

	    if (j)

		dp[i][j] = dp[i][j - 1];

	    dp[i][j] = (dp[i][j] + (1ll * dp[i - 1][j] * c(k - 2, i * (k - 1) + j - 1) % mod)) % mod;

	    // cout << i << " " << j << " " << dp[i][j] << endl;

	}

    //cout << dp[n][n] << endl;

    if (k == 1)

	return cout << 1 << endl, 0;

    cout << 1ll * dp[n][n] * fac[n] % mod << endl;

}
