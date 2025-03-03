#pragma GCC optimize(3)

#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<cstring>

#include<string>

#include<algorithm>

#include<vector>

#include<map>

#include<set>

#include<list>

#include<queue>

#include<stack>

#include<bitset>

#include<deque>

using namespace std;

#define ll long long

#define inf 0x3f3f3f3f

#define ri register int

#define il inline

#define fi first

#define se second

#define mp make_pair

#define pi pair<int,int>

#define mem0(x) memset((x),0,sizeof (x))

#define mem1(x) memset((x),0x3f,sizeof (x))

il char gc() {

	static const int BS = 1 << 22;

	static unsigned char buf[BS], *st, *ed;

	if (st == ed) ed = buf + fread(st = buf, 1, BS, stdin);

	return st == ed ? EOF : *st++;

}

#define gc getchar

template<class T>void in(T &x) {

	x = 0;

	bool f = 0;

	char c = gc();

	while (c < '0' || c > '9') {

		if (c == '-') f = 1;

		c = gc();

	}

	while ('0' <= c && c <= '9') {

		x = (x << 3) + (x << 1) + (c ^ 48);

		c = gc();

	}

	if (f) x = -x;

}

#undef gc

#define pb push_back

#define N 100010

#define M N

#define int ll

int v[M], u[M], nx[M];

int cnt, head[N];

il void add(int uu, int vv) {

	u[++cnt] = uu, v[cnt] = vv, nx[cnt] = head[uu];

	head[uu] = cnt;

}

int n, m, k;

double pos[N];

double de[N];

double ans[N];

int num[N], ys[N];

int cur;

int bel[N], rk[N];

vector<int>hv[N];

void dfs(int x, int k) {

	bel[x] = k;

	hv[k].pb(x);

	rk[x] = hv[k].size() - 1;

	for (ri i = head[x]; i; i = nx[i])

		if (!bel[v[i]]) dfs(v[i], k);

}

signed main() {

#ifndef ONLINE_JUDGE

	//freopen("in.in", "r", stdin);

#endif

	in(n);

	for (ri i = 1; i <= n; ++i) {

		scanf("%lf", &pos[i]);

		de[i] = pos[i] - pos[i - 1];

		num[i] = i;

	}

	in(m), in(k);

	for (ri i = 1, t; i <= m; ++i) {

		in(t);

		swap(num[t], num[t + 1]);

	}

	for (ri i = 1; i <= n; ++i) ys[num[i]] = i;

	for (ri i = 1; i <= n; ++i)

		add(i, ys[i]);

	for (ri i = 1; i <= n; ++i)

		if (!bel[i]) {

			++cur;

			dfs(i, cur);

		}

	for (ri i = 1, t; i <= n; ++i) {

		t = hv[bel[i]][(rk[i] + k) % hv[bel[i]].size()];

		ans[t] = de[i];

	}

	double tmp = 0.0;

	for (ri i = 1; i <= n; ++i) {

		tmp += ans[i];

		printf("%.9f\n", tmp);

	}

	return 0;

}