#include<vector>

#include<bitset>

#include<cstdio>

#include<iostream>

#include<algorithm>

#define pb push_back

using namespace std;

inline char nc() {

	static char b[100000],*s=b,*t=b;

	return s==t&&(t=(s=b)+fread(b,1,100000,stdin),s==t)?-1:*s++;

}

inline void read(int &x) {

	char b = nc(); x = 0;

	for (; !isdigit(b); b = nc());

	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';

}

struct Node {

	int x, y, id;	

	inline bool operator<(const Node &o) const {

		return x < o.x || (x == o.x && y < o.y);

	}

} a[100005];

int n, s, t, D, f[100005], fa[100005], rk[100005];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

long long ans;

bitset < 100005 > vis;

inline int ABS(int x) {return x > 0 ? x : -x;}

inline void ae(int u, int v) {

	if ((u = find(u)) != (v = find(v))) {

		if (rk[u] < rk[v]) swap(u, v);

		rk[u] += rk[u] == rk[v]; fa[v] = u;

	}

}

void build(int k) {

	sort(a + 1, a + 1 + n); int i, j, l, r;

	for (i = j = l = r = 1; i <= n; ++i) {

		while (a[l].x < a[i].x - D || (a[l].x == a[i].x - D && a[i].y - a[l].y > k)) ++l;

		while (a[r].x < a[i].x - D || (a[r].x == a[i].x - D && a[r].y - a[i].y <= k)) ++r;

		f[a[i].id] += r - l; j = max(j, l); if (j < r) ae(a[i].id, a[j].id);

		for (; j + 1 < r; ++j) ae(a[j].id, a[j+1].id);

	}

}

int main() {

	read(n); read(s); read(t);

	for (int i = 1; i <= n; ++i) fa[i] = i;

	for (int x, y, i = 1; i <= n; ++i)

		read(x), read(y), a[i] = (Node){x + y, x - y, i};

	D = max(ABS(a[s].x - a[t].x), ABS(a[s].y - a[t].y));

	build(D);

	for (int i = 1; i <= n; ++i) swap(a[i].x, a[i].y);

	build(D-1);

	for (int i = 1; i <= n; ++i)

		if (find(i) == find(s)) ans += f[i];

	printf("%lld\n", ans);

	return 0;

}
