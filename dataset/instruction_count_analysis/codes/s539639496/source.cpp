#include "stdc++.h"

using namespace std;

#define M 2010

#define MOD 924844033

#define rep(i, x, y) for(int i = (x); i <= (y); i ++)

inline int read() {

	char ch = getchar(); int x = 0, f = 1;

	while(ch < '0' || ch > '9') {

		if(ch == '-') f = -1;

		ch = getchar();

	} while('0' <= ch && ch <= '9') {

		x = x * 10 + ch - '0';

		ch = getchar();

	} return x * f;

}

bool vis[2010][2];

int f[4010][2010][2];

bool a[4010];

int fac[4010];

int sum;

int main() {

	int n = read(), k = read();

	fac[0] = 1; rep(i, 1, n) fac[i] = 1ll * i * fac[i - 1] % MOD;

	rep(i, 1, n) rep(j, 0, 1) if(!vis[i][j]) {

		int u = i, v = j;

		int now = 0;

		while(u <= n) {

			vis[u][v] = 1;

			u += k; v ^= 1;

			now ++;

		} a[sum += now] = 1;

	} f[1][0][0] = 1;

	rep(i, 2, sum) rep(j, 0, n) {

		(f[i][j][0] += f[i - 1][j][0]) %= MOD;

		(f[i][j][0] += f[i - 1][j][1]) %= MOD;

		if(!a[i - 1]) {

			(f[i][j][1] += f[i - 1][j - 1][0]) %= MOD;

		}

	} int ans = 0;

	rep(i, 0, n) {

		ans = (ans + 1ll * (i & 1 ? -1 : 1) * fac[n - i] * (f[sum][i][0] + f[sum][i][1]) % MOD + MOD) % MOD;

	} cout << ans;

	return 0;

}