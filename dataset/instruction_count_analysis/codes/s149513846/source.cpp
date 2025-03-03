#include "stdc++.h"

#define ll long long

#define pLL pair<ll, ll>

#define fs first

#define sc second

using namespace std;

const int N = 2e5 + 50;



#define inc(i, x, y) for (register int i = x; i <= y; ++i)

#define dec(i, x, y) for (register int i = x; i >= y; --i)

#define gc getchar



bool chkmin(int &x, int y) { return x > y ? x = y, 1 : 0; }

bool chkmax(int &x, int y) { return x < y ? x = y, 1 : 0; }



inline int rd() {

	int ret = 0; bool fl = 0; char ch = 0;

	while (!isdigit(ch)) fl |= (ch == '-'), ch = gc();

	while (isdigit(ch)) ret = (ret << 1) + (ret << 3) + (ch ^ 48), ch = gc();

	return fl ? -ret : ret;

}



#define go(i, v, x) for (int i = head[x], v = e[i].to; i; i = e[i].nxt, v = e[i].to)

struct edge { int nxt, to; ll w; } e[N << 1];

int head[N], odd[N], l[N], r[N], t[N], v[N], p[N], ecnt;



inline void add(int u, int v, int w) {

	e[++ecnt] = (edge) {head[u], v, w}, head[u] = ecnt;

	e[++ecnt] = (edge) {head[v], u, w}, head[v] = ecnt;

}



ll lim;



vector<pLL> tr, tl;

vector<pLL> f[N];



inline void init(int x, const pLL &t) {

    if (f[x].size() && f[x].back() <= t) return;

    while (f[x].size() && f[x].back().sc >= t.sc) f[x].pop_back();

    f[x].push_back(t);

}



inline bool dfs(int x, int fa) {

    f[x].clear();

    if(!e[head[x]].nxt) return f[x].push_back(pLL(0, 0)), true;

    ll lc, rc, disl, disr;

	bool fl = 0;

    go(i, v, x) {

        if (v==fa) continue;

        if (!dfs(v,x)) return false;

        if (!fl) fl=1, lc=v, disl = e[i].w;

        else rc=v, disr=e[i].w;

    }

    tl.clear(), tr.clear();

	ll lim2 = lim - disl - disr;

    if (lim2 < 0) return false; 

    int p1 = 0;

    inc (p2, 0, (signed) f[rc].size() - 1) {

        while (p1 < f[lc].size() && f[lc][p1].fs + f[rc][p2].sc > lim2) ++p1;

        if(p1 == f[lc].size()) break;

        tl.push_back(pLL(f[rc][p2].fs + disr, f[lc][p1].sc + disl));

    }

    int p2 = 0;

    inc (p1, 0, (signed)f[lc].size() - 1) {

        while (p2 < f[rc].size() && f[lc][p1].sc + f[rc][p2].fs > lim2) ++p2;

        if(p2 == f[rc].size()) break;

        tr.push_back(pLL(f[lc][p1].fs + disl, f[rc][p2].sc + disr));

    }

    int pl=0, pr=0;

    while (pl < tl.size() && pr < tr.size()) {

        if (tl[pl].fs > tr[pr].fs) init(x, tl[pl++]);

        else init(x, tr[pr++]);

    }

    while (pl < tl.size()) init(x, tl[pl++]);

    while (pr < tr.size()) init(x, tr[pr++]);

    return f[x].size() > 0;

}



int main() {

	int n = rd();

	inc(i, 2, n) {

		int v = rd(), w = rd();

		add(i, v, w);

	}

	ll l = 0, r = 17179869184, ans;

	while (l <= r) {

		ll mid = (l + r) >> 1;

		lim = mid;

		if (dfs(1, -1)) ans = mid, r = mid - 1;

		else l = mid + 1;

	}

	printf("%lld\n", ans); 

}