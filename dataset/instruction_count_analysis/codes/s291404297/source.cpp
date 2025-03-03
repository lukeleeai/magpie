#include "stdc++.h"

#define rep(i, l, r) for (register int i = l; i <= r; i++)

#define per(i, r, l) for (register int i = r; i >= l; i--)

#define srep(i, l, r) for (register int i = l; i < r; i++)

#define sper(i, r, l) for (register int i = r; i > l; i--)

#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)

#define maxn 3020

#define maxm 30020

#define ll long long int 

using namespace std;



const int inf = 2000000020;



int n, m, s, t;

struct edge{

	int next, to, flow, cost;

	edge(int next, int to, int flow, ll cost) : next(next), to(to), flow(flow), cost(cost){}

	edge(){}

}e[maxm << 1];

int cnt = 1, h[maxn];

void Add_Edge(int x, int y, int z, ll w){

	e[++cnt] = edge(h[x], y, z, w);

	h[x] = cnt;

	e[++cnt] = edge(h[y], x, 0, -w);

	h[y] = cnt;

}

int p[maxn];

ll d[maxn];

bool und[maxn];

int spfa[maxn];

bool vis[maxn];

int head = 0, tail = 0;

bool SPFA(){

	rep(i, s, t) und[i] = 1;

	d[s] = 0, und[s] = 0;

	head = tail = 0;

	spfa[++head] = s;

	vis[s] = 1;

	while (head != tail){

		int x = spfa[++tail];

		tail = (tail == maxn - 1) ? 0 : tail;

		erep(i, x){

			if (!e[i].flow) continue;

			int op = e[i].to;

			if (d[op] > d[x] + e[i].cost || und[op]){

				p[op] = i;

				und[op] = 0;

				d[op] = d[x] + e[i].cost;

				if (!vis[op]) {

					vis[op] = 1;

					spfa[++head] = op;

					head = (head == maxn - 1) ? 0 : head;

				}

			}

		}

		vis[x] = 0;

	}

	return !und[t];

}

void Augment(int& maxflow, ll& mincost){

	int now = t, flow = inf;

	while (now != s){

		int k = p[now];

		flow = min(flow, e[k].flow);

		now = e[k ^ 1].to;

	}

	now = t;

	while (now != s){

		int k = p[now];

		e[k].flow -= flow, e[k ^ 1].flow += flow;

		now = e[k ^ 1].to;

	}

	maxflow += flow, mincost += (d[t] - d[s]) * flow;

}

void MCMF(int& maxflow, ll& mincost){

	while (SPFA()) Augment(maxflow, mincost);

}

//     R      B

// 1  + +    - -

// 2  + -    - +

// 3  - +    + -

// 4  - -    + +



int main(){

	int T, sum = 0;

	ll x, y, z;

	scanf("%d", &T);

	s = 0, t = 2 * T + 5;

	rep(TT, 1, T){ //4 + TT

		scanf("%lld%lld%lld", &x, &y, &z);

		Add_Edge(s, 4 + TT, z, 0);

		Add_Edge(4 + TT, 1, z, -(+ x + y));

		Add_Edge(4 + TT, 2, z, -(+ x - y));

		Add_Edge(4 + TT, 3, z, -(- x + y));

		Add_Edge(4 + TT, 4, z, -(- x - y));

		sum += z;

	}

	rep(TT, 1, T){ //4 + TT + T

		scanf("%lld%lld%lld", &x, &y, &z);

		Add_Edge(4 + TT + T, t, z, 0);

		Add_Edge(1, 4 + TT + T, z, +(+ x + y));

		Add_Edge(2, 4 + TT + T, z, +(+ x - y));

		Add_Edge(3, 4 + TT + T, z, +(- x + y));

		Add_Edge(4, 4 + TT + T, z, +(- x - y));

	}

	int maxflow = 0;

	ll mincost = 0;

	MCMF(maxflow, mincost);

	assert(maxflow == sum);

	printf("%lld\n", -mincost);

	return 0;

}