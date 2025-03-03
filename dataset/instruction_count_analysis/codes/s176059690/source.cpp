#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define fbo find_by_order

#define ook order_of_key



typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



struct DSU

{

	int S;

	

	struct node

	{

		int p; ll sum;

	};

	vector<node> dsu;

	

	DSU(int n)

	{

		S = n;

		for(int i = 0; i < n; i++)

		{

			node tmp;

			tmp.p = i; tmp.sum = 0;

			dsu.pb(tmp);

		}

	}

	

	void reset(int n)

	{

		dsu.clear();

		S = n;

		for(int i = 0; i < n; i++)

		{

			node tmp;

			tmp.p = i; tmp.sum = 0;

			dsu.pb(tmp);

		}

	}

	

	int rt(int u)

	{

		if(dsu[u].p == u) return u;

		dsu[u].p = rt(dsu[u].p);

		return dsu[u].p;

	}

	

	void merge(int u, int v)

	{

		u = rt(u); v = rt(v);

		if(u == v) return ;

		if(rand()&1) swap(u, v);

		dsu[v].p = u;

		dsu[u].sum += dsu[v].sum;

	}

	

	bool sameset(int u, int v)

	{

		if(rt(u) == rt(v)) return true;

		return false;

	}

	

	ll getstat(int u)

	{

		return dsu[rt(u)].sum;

	}

};



struct Graph

{

	struct edge

	{

		int v; ll weight;

	};

	vector<vector<edge> > adj;

	int n;

	

	Graph(int _n)

	{

		adj.resize(_n);

		n = _n;

	}

	

	void addedge(int u, int v, ll c)

	{

		edge tmp;

		tmp.v = v; tmp.weight = c;

		adj[u].pb(tmp);

		tmp.v = u;

		adj[v].pb(tmp);

	}

	

	void reset()

	{

		adj.clear();

	}

	

	vi dist;

	vi par;

	

	void bfs(int s)

	{

		ll INFI = ll(1e18);

		dist.assign(n, INFI);

		par.assign(n, -1);

		dist[s] = 0; par[s] = -1;

		queue<int> q; q.push(s);

		while(!q.empty())

		{

			int u = q.front(); q.pop();

			for(int i = 0; i < adj[u].size(); i++)

			{

				int v = adj[u][i].v;

				if(dist[v] >= INFI)

				{

					dist[v] = dist[u] + 1;

					par[v] = u;

					q.push(v);

				}

			}

		}

	}

	

	void bfs01(int s)

	{

		ll INFI = ll(1e18);

		dist.assign(n, INFI);

		par.assign(n, -1);

		dist[s] = 0; par[s] = -1;

		deque<int> q; q.pb(s);

		while(!q.empty())

		{

			int u = q.front(); q.pop_front();

			for(int i = 0; i < adj[u].size(); i++)

			{

				int v = adj[u][i].v; ll w = adj[u][i].weight;

				if(dist[v] >= INFI)

				{

					if(w == 1)

					{

						dist[v] = dist[u] + 1;

						par[v] = u;

						q.push_back(v);

					}

					else

					{

						dist[v] = dist[u];

						par[v] = u;

						q.push_front(v);

					}

				}

			}

		}

	}

	

	void dijkstra(int s)

	{

		ll INFI = ll(1e18);

		dist.assign(n, INFI);

		par.assign(n, -1);

		dist[s] = 0; par[s] = -1;

		priority_queue<ii, vector<ii>, greater<ii> > pq;

		pq.push(ii(0, s));

		while(!pq.empty())

		{

			int u = pq.top().se; ll d = pq.top().fi; pq.pop();

			for(int i = 0; i < adj[u].size(); i++)

			{

				int v = adj[u][i].v; ll w = adj[u][i].weight;

				if(d + w < dist[v])

				{

					dist[v] = d + w;

					par[v] = u;

					pq.push(ii(dist[v], v));

				}

			}

		}

	}

	

	vector<vector<ll> > d;

	

	void Floyd()

	{

		ll INFIN = ll(1e18);

		d.resize(n);

		for(int i = 0; i < n; i++)

		{

			d[i].assign(n, INFIN);

		}

		for(int i = 0; i < n; i++)

		{

			for(int j = 0; j < adj[i].size(); j++)

			{

				d[i][adj[i][j].v] = adj[i][j].weight;

			}

			d[i][i] = 0;

		}

		for(int k = 0; k < n; k++)

		{

			for(int i = 0; i < n; i++)

			{

				for(int j = 0; j < n; j++)

				{

					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

				}

			}

		}

	}

	

	bool BellmanFord(int s) //returns true if negative weight cycle exists

	{

		ll INFI = ll(1e18);

		dist.assign(n, INFI);

		par.assign(n, -1);

		dist[s] = 0;

		for(int step = 1; step <= n; step++)

		{

			for(int i = 0; i < n; i++)

			{

				for(int j = 0; j < adj[i].size(); j++)

				{

					int u = i; int v = adj[i][j].v; ll w = adj[i][j].weight;

					if(dist[v] > dist[u] + w)

					{

						if(step == n)

						{

							return true;

						}

						dist[v] = dist[u] + w;

					}

				}

			}

		}

		return false;

	}

	

	ll shortest(int s, int e) //returns the distance by Dijkstra

	{

		return dist[e];

	}

	

	vector<pair<ll, ii> > edges;

	

	ll Kruskal()

	{

		DSU dsu(n);

		for(int i = 0; i < n; i++)

		{

			for(int j = 0; j < adj[i].size(); j++)

			{

				int u = i; int v = adj[i][j].v; ll w = adj[i][j].weight;

				edges.pb(mp(w, mp(u, v)));

			}

		}

		sort(edges.begin(), edges.end());

		ll ans = 0; int cnt = 0;

		for(int i = 0; i < edges.size(); i++)

		{

			int u = edges[i].se.fi; int v = edges[i].se.se;

			if(dsu.sameset(u, v)) continue;

			dsu.merge(u, v);

			cnt++; ans += edges[i].fi;

			if(cnt >= n - 1) break;

		}

		return ans;

	}

};



Graph G(200001);

ll cost[200001];



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n,q;

	cin>>n>>q;

	G = Graph(n);

	for(int i = 0; i < n; i++)

	{

		cost[i] = ll(1e18);

	}

	for(int i = 0; i < q; i++)

	{

		ll s,e,c;

		cin>>s>>e>>c;

		G.addedge(s,e,c);

		cost[s]=min(cost[s],c+1);

		cost[e]=min(cost[e],c+2);

	}

	for(int i = 1; i < n; i++)

	{

		cost[i] = min(cost[i], cost[i-1]+2);

	}

	cost[0] = min(cost[0], cost[n-1]+2);

	for(int i = 1; i < n; i++)

	{

		cost[i] = min(cost[i], cost[i-1]+2);

		G.addedge(i-1,i,cost[i-1]);

	}

	G.addedge(n-1,0,cost[n-1]);

	cout<<G.Kruskal()<<'\n';

}
