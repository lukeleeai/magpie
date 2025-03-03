#include "stdc++.h"



#define debug(x) cout << #x" = " << x;



#define st first

#define nd second



using namespace std;

using namespace placeholders;



typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> PII;

typedef pair<ll, ll> PLL;



const int MAXN = 2E3 + 10;

const int MOD = 1E9 + 7;



ll inv[MAXN], fac[MAXN], facinv[MAXN];



ll modExp(ll e, ll n, ll m = MOD){

	ll ret = 1;

	for (; n; n >>= 1, e = e * e % m)

		if (n & 1)

			ret = ret * e % m;

	return ret;

}



void getInv(int n = MAXN - 1, int m = MOD){

	inv[0] = 0, inv[1] = 1;

	fac[0] = fac[1] = 1;

	facinv[0] = facinv[1] = 1;

	for (int i = 2; i <= n; ++i){

		inv[i] = inv[m % i] * (m - m / i) % m;

		fac[i] = fac[i - 1] * i % m;

		facinv[i] = facinv[i - 1] * inv[i] % m;

	}

}



ll C(int n, int m){

	return m < 0 || n < m ? 0 : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;

}



inline void update(int &x, int y){

	if ((x += y) >= MOD)

		x -= MOD;

}



int f[MAXN][MAXN];



int main(){

	getInv();



	int n, k;

	scanf("%d%d", &n, &k);

	f[0][0] = 1;

	for (int i = 1; i <= k - 1; ++i){

		int s = f[i - 1][i - 1];

		for (int j = i; j < n; ++j){

			update(f[i][j], s);

			update(f[i][j], f[i - 1][j]);

			update(s, f[i - 1][j]);

//			printf("%d %d %d\n", i, j, f[i][j]);

		}

	}

	int ans = 0;

	for (int i = 0; i < n; ++i)

		update(ans, f[k - 1][i]);

	printf("%d\n", (int)(ans * modExp(2, max(0, n - k - 1)) % MOD));

	return 0;

}
