#include "stdc++.h"

using namespace std;



typedef long long LL;

typedef pair<int, int> PII;

typedef pair<LL, LL> PLL;

typedef vector<int> VI;

typedef unsigned long long ULL;



#define MP make_pair

#define PB push_back

#define EB emplace_back

#define FOR(i, a, b) for (int i = (a); i<(b); ++i)

#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)a.size()

#define f first

#define s second

#define FILL(a, b) memset(a, b, sizeof(a))



 

void dout() { cerr << endl; }

 

template <typename Head, typename... Tail>

void dout(Head H, Tail... T) {

    cerr << H << ' ';

    dout(T...);

}	



int main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;

	vector<vector<PII>> g(n);

	for (int i = 0; i < m; ++i)

	{

		int l, r, c;

		cin >> l >> r >> c;

		--l, --r;

		g[l].EB(r, c);

		g[r].EB(l, c);

	}



	for (int i = 1; i < n; ++i)

	{

		g[i].EB(i - 1, 0);

	}

	vector<LL> dist(n, 1e18);

	dist[0] = 0;

	set<PLL> st;

	st.insert({dist[0], 0});

	while(!st.empty())

	{

		auto [d, v] = *st.begin();

		st.erase(st.begin());

		for (auto [to, w] : g[v])

		{

			if (dist[to] > dist[v] + w)

			{

				auto it = st.find({dist[to], to});

				if (it != st.end())

				{

					st.erase(it);

				}

				dist[to] = dist[v] + w;

				st.insert({dist[to], to});

			}

		}

	}



	if (dist[n - 1] > (LL)1e18 - 7)

	{

		cout << -1 << "\n";

	}

	else

	{

		cout << dist[n - 1] << "\n";

	}



	return 0;

}