#include <cstdio>

#include <vector>

#include <algorithm>

#include <map>

#include <queue>

#include <functional>



using namespace std;



typedef long long ll;

typedef pair<int, int> pii;



#define fst first

#define scd second

#define PB push_back

#define rep(i,x) for(int i=0;i<(x);++i)



const ll inf = 3e18;



struct edge {

	int to, cost;

	edge(int to, int cost) : to(to), cost(cost) {}

};



int N, M, C;



ll d[100000];

vector<edge> G[100000];

map<ll, vector<int> >  m;

bool found[100000];

map<int, bool> used[100000];



void dijkstra(int s)

{

	priority_queue<pii, vector<pii>, greater<pii> > q;

	fill(d, d + N, inf);

	d[s] = 0;

	q.push(pii(0, s));

	while (q.size()) {

		pii p = q.top(); q.pop();

		int v = p.scd;

		if (d[v] < p.fst) continue;

		rep(i, G[v].size()) {

			edge e = G[v][i];

			if (d[e.to] > d[v] + e.cost) {

				d[e.to] = d[v] + e.cost;

				m[d[e.to]].PB(e.to);

				q.push(pii(d[e.to], e.to));

			}

		}

	}

}



signed main()

{

	scanf("%d %d %d", &N, &M, &C);



	ll sum = 0;



	rep(i, M) {

		int A, B, D; scanf("%d %d %d", &A, &B, &D), A--, B--;

		G[A].PB(edge(B, D));

		G[B].PB(edge(A, D));

		sum += D;

	}



	dijkstra(0);

	found[0] = true;



	ll mi = inf;



	m[0] = vector<int>();



	for (map<ll, vector<int> >::iterator itr = m.begin(); itr != m.end(); ++itr) {

		ll X = itr->fst;

		vector<int> vs = itr->scd;



		rep(i, vs.size()) found[vs[i]] = true;



		rep(i, vs.size()) {

			int v = vs[i];

			rep(j, G[v].size()) {

				edge e = G[v][j];

				if (!found[e.to]) continue;

				if (used[v][e.to]) continue;

				used[v][e.to] = used[e.to][v] = true;

				sum -= e.cost;

			}

		}



		mi = min(mi, sum + C * X);

	}



	printf("%lld\n", mi);

}