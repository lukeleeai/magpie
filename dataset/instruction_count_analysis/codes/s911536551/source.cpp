#include "stdc++.h"

using namespace std;

#define REP(i,a) for(int i = 0; i < (a); i++)

typedef long long ll;

typedef pair<int, int> P;

const ll INF = 1e15;

const int MOD = 1e9 + 7;



#define MAX_V 100000



struct edge { int to; ll cost; };



int V;//頂点数



//始点sから各頂点への最短距離を求める

void dijkstra(int s, vector<edge> G[], ll d[]){

	priority_queue<P, vector<P>, greater<P> > que;

	fill(d, d + V, INF);

	d[s] = 0;

	que.push(P(0, s));

	

	while(!que.empty()){

		P p = que.top();

		que.pop();

		int v = p.second;

		if(d[v] < p.first) continue;

		for(int i = 0; i < G[v].size(); i++){

			edge e = G[v][i];

			if(d[e.to] > d[v] + e.cost){

				d[e.to] = d[v] + e.cost;

				que.push(P(d[e.to], e.to));

			}

		}

	}

}



int main(){

	int m,s,t;

	cin >> V >> m >> s >> t;

	s--;

	t--;

	int u,v;

	ll a,b;

	vector<edge> G1[MAX_V], G2[MAX_V];//辺の張り方 : G[from].push_back((edge){to, cost});

	REP(i,m){

		cin >> u >> v >> a >> b;

		u--;

		v--;

		G1[u].push_back((edge){v, a});

		G1[v].push_back((edge){u, a});

		G2[u].push_back((edge){v, b});

		G2[v].push_back((edge){u, b});

	}

	ll d1[MAX_V], d2[MAX_V];

	dijkstra(s,G1,d1);

	dijkstra(t,G2,d2);

	ll mx = 0;

	ll ans[V];

	for(int i = V - 1; i >= 0; i--){

		mx = max(mx, 1000000000000000 - (d1[i] + d2[i]));

		ans[i] = mx;

	}

	REP(i,V){

		cout << ans[i] << endl;

	}

}