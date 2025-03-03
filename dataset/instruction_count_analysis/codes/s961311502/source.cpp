#include "stdc++.h"

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)

#define SIZE 200005

#define INF 1000000005LL

#define MOD 1000000007



using namespace std;

typedef long long int ll;

typedef pair <int,int> P;



int H,W;

int c[11][11];

int V;

struct edge{int to,cost;};

vector<edge> G[SIZE];

int d[SIZE];



void dijkstra(int s){

	priority_queue<P, vector<P>, greater<P>> que;

	fill(d,d+V,INF);

	d[s] = 0;

	que.push(P(0,s));



	while(!que.empty()){

		P p = que.top();que.pop();

		int v = p.second;

		if(d[v] < p.first)continue;

		for(int i=0;i<G[v].size();i++){

			edge e = G[v][i];

			if(d[e.to] > d[v] + e.cost){

				d[e.to] = d[v] + e.cost;

				que.push(P(d[e.to],e.to));

			}

		}

	}

}



int main()

{

	cin >> H >> W;

	V = 10;

	int C;

	rep(i,0,10) rep(j,0,10){

		cin >> C;

		//Gは逆辺のグラフ

		G[j].push_back((edge){i,C});

	}

	dijkstra(1);

	int a,ans=0;

	rep(i,0,H) rep(j,0,W){

		cin >> a;

		ans += d[a];

	}

	cout << ans << endl;

	return 0;

}
