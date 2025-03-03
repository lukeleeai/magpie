#include "stdc++.h"

typedef long long ll;



const int N = 2e5+50;

const int P = 924844033;



struct Graph {

	struct Edge {

		int to, nxt;

	} e[N<<1];

	int top, head[N];

	

	Graph(): top(0) {

		memset(head, -1, sizeof head);

	}

	

	void add(int u, int v) {

		e[top] = (Edge){v, head[u]};

		head[u] = top++;

	}

	

	void add2(int u, int v) {

		add(u, v);

		add(v, u);

	}

} G;



int n, a[N];

int siz[N];

int fac[N], ifac[N];

int g[N], h[N], s[N<<1];



int qPow(int x, int k) {

	int rtn = 1;

	for (; k; k >>= 1, x = (ll)x * x % P)

		if (k & 1) rtn = (ll)rtn * x % P;

	return rtn;

}



void dfs(int u, int fa) {

	siz[u] = 1;

	for (int i = G.head[u]; ~i; i = G.e[i].nxt) {

		int v = G.e[i].to;

		if (v == fa) continue;

		dfs(v, u);

		siz[u] += siz[v];

		a[siz[v]]--;

	}

	a[n]++;

	a[n-siz[u]]--;

}



void initFac() {

	fac[0] = 1;

	for (int i = 1; i <= n; i++)

		fac[i] = (ll)fac[i-1] * i % P;

	ifac[n] = qPow(fac[n], P-2);

	for (int i = n-1; i >= 0; i--)

		ifac[i] = (ll)ifac[i+1] * (i+1) % P;

}



namespace NTT {

	const int G = 5;

	

	int n;

	int rev[N<<2];

	int a[N<<2], b[N<<2], t[N<<2];

	

	void init(int m) {

		int len = 0;

		for (n = 1; n < m; n <<= 1)

			len++;

		for (int i = 0; i < n; i++)

			rev[i] = rev[i>>1] >> 1 | (i&1) << len-1;

	}

	

	void NTT(int f[], int sgn) {

		for (int i = 0; i < n; i++)

			if (rev[i] > i) std::swap(f[rev[i]], f[i]);

		for (int i = 1; i < n; i <<= 1) {

			int gn = qPow(G, (P-1)/(i*2));

			if (sgn == -1) gn = qPow(gn, P-2);

			for (int j = 0; j < n; j += i*2) {

				int g = 1;

				for (int k = 0; k < i; k++, g = (ll)g * gn % P) {

					int x = f[j+k], y = (ll)g * f[j+i+k] % P;

					f[j+k] = (x + y) % P;

					f[j+i+k] = (x - y) % P;

				}

			}

		}

		if (sgn == -1) {

			int invn = qPow(n, P-2);

			for (int i = 0; i < n; i++)

				f[i] = (ll)f[i] * invn % P;

		}

		for (int i = 0; i < n; i++)

			f[i] = (f[i] + P) % P;

	}

	

	void mul(int la, int ta[], int lb, int tb[], int res[]) {

		init(la+lb-1);

		memset(a, 0, sizeof a);

		memset(b, 0, sizeof b);

		for (int i = 0; i < la; i++)

			a[i] = ta[i];

		for (int i = 0; i < lb; i++)

			b[i] = tb[i];

		NTT(a, 1);

		NTT(b, 1);

		for (int i = 0; i < n; i++)

			t[i] = (ll)a[i] * b[i] % P;

		NTT(t, -1);

		for (int i = 0; i < la+lb-1; i++)

			res[i] = t[i];

	}

}



int main() {

	scanf("%d", &n);

	initFac();

	for (int i = 1, u, v; i < n; i++) {

		scanf("%d%d", &u, &v);

		G.add2(u, v);

	}

	dfs(1, 0);

	for (int i = 0; i < n; i++) {

		g[i] = ifac[i];

		h[i] = (ll)fac[n-i] * a[n-i] % P;

	}

	NTT::init(n);

	NTT::mul(n, g, n, h, s);

	for (int i = 1; i <= n; i++)

		printf("%d\n", (int)((ll)s[n-i] * ifac[i] % P));

	return 0;

}
