#include "stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)

#define MP make_pair



using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int MOD = 924844033;

const int PRT = 5;



int power(int x, int t)

{

	int ret = 1;

	while(t > 0) {

		if(t & 1) ret = 1LL * ret * x % MOD;

		x = 1LL * x * x % MOD;

		t >>= 1;

	}

	return ret;

}



void DFT(int from[], int to[], int len, int dir)

{

	int cur = 0;

	rep(i, 1 << len) {

		to[cur] = from[i];

		for(int j = len - 1; j >= 0; j --) {

			cur ^= 1 << j;

			if((cur >> j) & 1) break;

		}

	}

	

	for(int d = 2; d <= (1 << len); d <<= 1) {

		int cr = power(PRT, MOD - 1 + (MOD - 1) / d * dir);

		for(int i = 0; i < (1 << len); i += d) {

			int rt = 1;

			for(int j = i; j < i + (d >> 1); j ++) {

				int ev = to[j], od = 1LL * to[j + (d >> 1)] * rt % MOD;

				to[j] = (ev + od) % MOD;

				to[j + (d >> 1)] = (ev - od + MOD) % MOD;

				rt = 1LL * rt * cr % MOD;

			}

		}

	}

	

	if(dir < 0) {

		int gr = power(1 << len, MOD - 2);

		rep(i, 1 << len) to[i] = 1LL * to[i] * gr % MOD;

	}

}



int _u[524288], _v[524288], _w[524288];

void poly_mul(int p0[], int p1[], int ret[], int n)

{

	int cl = 0;

	while((1 << cl) <= n) cl ++;

	cl ++;

	

	rep(i, 1 << cl) {

		_u[i] = i <= n ? p0[i] : 0;

		_v[i] = i <= n ? p1[i] : 0;

	}

	DFT(_u, _w, cl, 1);

	DFT(_v, _u, cl, 1);

	rep(i, 1 << cl) _v[i] = 1LL * _u[i] * _w[i] % MOD;

	DFT(_v, _w, cl, -1);

	

	for(int i = 0; i <= 2 * n; i ++) ret[i] = _w[i];

}



int inv[200005];

int fac[200005], ifac[200005];

void gen_fac(int n)

{

	inv[1] = 1;

	for(int i = 2; i <= n; i ++) inv[i] = MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;

	

	fac[0] = ifac[0] = 1;

	rep1(i, n) {

		fac[i] = 1LL * fac[i - 1] * i % MOD;

		ifac[i] = 1LL * ifac[i - 1] * inv[i] % MOD;

	}

}



int n;

vector<int> G[200005];



int sz[200005];

void dfs(int v, int par)

{

	sz[v] = 1;

	rep(i, G[v].size()) {

		int u = G[v][i];

		if(u == par) continue;

		dfs(u, v);

		sz[v] += sz[u];

	}

}



int poly0[400005], poly1[400005], poly2[400005];



int main()

{

	scanf("%d", &n);

	rep(i, n - 1) {

		int u, v;

		scanf("%d%d", &u, &v);

		G[u].push_back(v);

		G[v].push_back(u);

	}

	dfs(1, -1);

	

	poly0[n] = n;

	rep1(i, n) rep(j, G[i].size()) {

		int nj = G[i][j];

		if(sz[nj] > sz[i]) poly0[n - sz[i]] --;

		else poly0[sz[nj]] --;

	}

	

	gen_fac(n);

	rep1(i, n) poly0[i] = 1LL * (MOD + poly0[i]) * fac[i] % MOD;

	for(int i = 0; i <= n; i ++) poly1[i] = ifac[n - i];

	

	poly_mul(poly0, poly1, poly2, n);

	

	rep1(i, n) printf("%d\n", 1LL * poly2[n + i] * ifac[i] % MOD);

	return 0;

}