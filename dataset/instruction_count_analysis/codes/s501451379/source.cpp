#include <iostream>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <queue>

using namespace std;

#define rep(i,s,n)for(int i = s;i<n;i++)

#define repe(i,s,n)for(int i = s;i<=n;i++)

typedef long long ll;

static const ll MOD = 1e9 + 7;

static const ll INF = (ll)1 << 62;



//////////////////////////////////////////////////////

//Union Find /////////////////////////////////////////

//////////////////////////////////////////////////////

static const ll MAX_M = 100001;

static const ll MAX_N = 100001;

int par[MAX_N];

int rak[MAX_N];



void init(int n) {

	rep(i, 0, n) {

		par[i] = i;

		rak[i] = 0;

	}

}



int find(int x) {

	if (par[x] == x)return x;

	else return par[x] = find(par[x]);

}



void unite(int x, int y) {

	x = find(x);

	y = find(y);

	if (x == y)return;



	if (rak[x] < rak[y]) par[x] = y;

	else {

		par[x] = y;

		if (rak[x] == rak[y]) rak[x]++;

	}

}



bool same(int x, int y) {

	return find(x) == find(y);

}



struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {

	return e1.cost < e2.cost;

}



int V, E;

edge es[MAX_M];



int krascal() {

	sort(es, es + E, comp);

	init(V);

	int res = 0;



	rep(i, 0, E) {

		edge e = es[i];

		if (!same(e.u, e.v)) {

			unite(e.u, e.v);

			res += e.cost;

		}

	}

	return res;

}



int main() {

	ll n, m; cin >> n >> m;

	V = n, E = m;

	rep(i, 0, m) {

		ll s, t, w; cin >> s >> t >> w;

		edge *e = new edge();

		e->u = s;

		e->v = t;

		e->cost = w;

		es[i] = *e;

	}



	cout << krascal() << endl;



	return 0;

}
