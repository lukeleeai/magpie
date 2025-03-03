#include"stdc++.h"

using namespace std;



#define fi first

#define se second

#define pb push_back

#define ii pair<int, int>

#define mp make_pair

#define iii pair< int, pair<int, ii> >

#define int long long

#define FOR(a, b, c) for(int a = b; a <= c; ++a)

const int N = 1e5 + 10;

const int oo = 1e8;

const int mod = 1e9 + 7;

const double PI = acos(-1);

int n;

int res[N], la[N], pr[N];

vector<int> dsu[N];

struct book{

	int u, v, val;

} eg[N];

bool cmp(const book x, const book y)	{

	return x.val < y.val;

}

void join(int u, int v, int val)	{

	int pru = pr[u], prv = pr[v];

	if(dsu[pru].size() < dsu[prv].size()) swap(pru, prv);

	int tmp = dsu[pru].size();

	la[pru] += dsu[prv].size()*val;

	for(int j = 0; j < dsu[prv].size(); ++j)	{

		int cur = dsu[prv][j];

		pr[cur] = pru; dsu[pru].pb(cur);

		res[cur] += tmp*val; res[cur] += la[prv];

		res[cur] -= la[pru];

	}

	dsu[prv].clear();

}

signed main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; ++i) {

    	pr[i] = i;

    	dsu[i].pb(i);

	}

    for(int i = 1; i < n; ++i)	{

    	cin >> eg[i].u >> eg[i].v >> eg[i].val;

	}

	sort(eg + 1, eg + n, cmp);

	for(int i = n - 1; i >= 1; --i)	{

		int u1 = eg[i].u, v1 = eg[i].v, val1 = eg[i].val;

		join(u1, v1, val1);

	}

	for(int i = 1; i <= n; ++i) cout << res[i] + la[pr[i]] << '\n';

}