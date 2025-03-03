#include <cstdio>

#include <algorithm>

using namespace std;



typedef long long ll;



const int INF = (1<<30);

const ll inf = 1E15;



struct FlowGraph{

	#define MAXV (2500)

	#define MAXE (20*MAXV)

	struct edge{

		int to, cap, flow; ll cost;

		edge *nxt, *rev;

	}edges[MAXE + 5], *adj[MAXV + 5], *cur[MAXV + 5], *ecnt;

	FlowGraph() {ecnt = edges;}

	void addedge(int u, int v, int c, ll w) {

		edge *p = (++ecnt), *q = (++ecnt);

		p->to = v, p->cap = c, p->flow = 0, p->cost = w;

		p->nxt = adj[u], adj[u] = p;

		q->to = u, q->cap = 0, q->flow = 0, q->cost = -w;

		q->nxt = adj[v], adj[v] = q;

		p->rev = q, q->rev = p;

	}

	int s, t;

	int hp[MAXV + 5]; ll f[MAXV + 5];

	void update(int x, ll k) {

		f[x] = k;

		while( x ) {

			hp[x] = x;

			if( (x<<1) <= t && f[hp[x<<1]] < f[hp[x]] )

				hp[x] = hp[x<<1];

			if( (x<<1|1) <= t && f[hp[x<<1|1]] < f[hp[x]] )

				hp[x] = hp[x<<1|1];

			x >>= 1;

		}

	}

	ll d[MAXV + 5], h[MAXV + 5];

	bool relabel() {

		for(int i=1;i<=t;i++)

			h[i] += d[i], d[i] = f[i] = inf, hp[i] = i, cur[i] = adj[i];

		update(s, d[s] = 0);

		while( f[hp[1]] != inf ) {

			int x = hp[1]; update(x, inf);

			for(edge *p=adj[x];p;p=p->nxt) {

				ll dis = d[x] + p->cost + (h[x] - h[p->to]);

				if( p->cap > p->flow && dis < d[p->to] )

					update(p->to, d[p->to] = dis);

			}

		}

		return !(d[t] == inf);

	}

	bool vis[MAXV + 5];

	int aug(int x, int tot) {

		if( x == t ) return tot;

		int sum = 0; vis[x] = true;

		for(edge *&p=cur[x];p;p=p->nxt) {

			ll dis = d[x] + p->cost + (h[x] - h[p->to]);

			if( !vis[p->to] && p->cap > p->flow && dis == d[p->to] ) {

				int del = aug(p->to, min(tot - sum, p->cap - p->flow));

				p->flow += del, p->rev->flow -= del, sum += del;

				if( sum == tot ) break;

			}

		}

		vis[x] = false;

		return sum;

	}

	ll min_cost_max_flow(int _s, int _t) {

		s = _s, t = _t; ll cost = 0;

		while( relabel() ) {

			int del = aug(s, INF);

			cost += del*(d[t] + h[t]);

		}

		return cost;

	}

}G;



int main() {

	int N; scanf("%d", &N);

	int s = 2*N + 4 + 1, t = 2*N + 4 + 2;

	for(int i=1;i<=N;i++) {

		int X, Y, C; scanf("%d%d%d", &X, &Y, &C);

		G.addedge(s, i, C, 0);

		G.addedge(i, 2*N + 1, INF, + X + Y);

		G.addedge(i, 2*N + 2, INF, - X + Y);

		G.addedge(i, 2*N + 3, INF, + X - Y);

		G.addedge(i, 2*N + 4, INF, - X - Y);

	}

	for(int i=N+1;i<=2*N;i++) {

		int X, Y, C; scanf("%d%d%d", &X, &Y, &C);

		G.addedge(i, t, C, 0);

		G.addedge(2*N + 1, i, INF, - X - Y);

		G.addedge(2*N + 2, i, INF, + X - Y);

		G.addedge(2*N + 3, i, INF, - X + Y);

		G.addedge(2*N + 4, i, INF, + X + Y);

	}

	printf("%lld\n", -G.min_cost_max_flow(s, t));

}