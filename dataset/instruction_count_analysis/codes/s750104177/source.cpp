#include "stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")

typedef long long lint;

typedef unsigned int uint;

typedef pair<int, int> pii;

typedef pair<lint, lint> pll;

typedef unsigned long long ulint;

#define endl '\n'

#define fst first

#define sed second

#define pb push_back

#define mp make_pair

#define rint register int

#define newline putchar('\n')

#define leave_space putchar(' ')

#define all(x) (x).begin(), (x).end()

#define reveal(x) cerr << #x << " = " << (x) << endl

#define rep(it, f, e) for (rint it = (f); it <= int(e); ++it)

#define per(it, f, e) for (rint it = (f); it >= int(e); --it)

const int MAXN = 1e5 + 10;

vector<int> edge[MAXN], cycle;

struct DSU {

	int par[MAXN];

	DSU() {

		rep (i, 1, MAXN - 1) {

			par[i] = i;

		}

	}

	inline int find(int x) {

		return par[x] == x ? x : par[x] = find(par[x]);

	}

	inline void marry(int x, int y) {

		par[find(x)] = find(y);

	}

}	Dsu;

int val[MAXN], par[MAXN];

inline void dfs(int u, int col) {

	val[u] = col;

	for (auto v : edge[u]) {

		if (v == par[u]) continue;

		par[v] = u;

		dfs(v, -col);

		val[u] += val[v];

	}

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(NULL), cout.tie(NULL);

	int le1 = 1, le2 = 1;

	int n, m, u, v;

	cin >> n >> m;

	rep (i, 1, m) {

		cin >> u >> v;

		if (Dsu.find(u) != Dsu.find(v)) {

			Dsu.marry(u, v);

			edge[u].pb(v);

			edge[v].pb(u);

		} else {

			le1 = u, le2 = v;

		}

	}

	dfs(le1, 1);

	if (n == m) {

		for (int u = le2; u; u = par[u]) {

			cycle.pb(val[u]);

		}

        if (cycle.size() & 1) {

			if (val[le1] & 1) {

				cout << -1 << endl;

				return 0;

			}

			for (int u = le2; u; u = par[u]) {

				val[u] -= val[le1] / 2;

			}

        } else {

			if (val[le1]) {

				cout << -1 << endl;

				return 0;

			}

			sort(all(cycle));

			for (int u = le2; u; u = par[u]) {

				val[u] -= cycle[cycle.size() / 2 - 1];

			}

        }

	} else if (val[le1]) {

		cout << -1 << endl;

		return 0;

	}

	lint ans = 0;

	rep (i, 1, n) {

		ans += abs(val[i]);

	}

    cout << ans << endl;

	return 0;

}