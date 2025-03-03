#include "stdc++.h"

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)

#define SIZE 200005

#define INF 1000000005LL

#define MOD 1000000007



using namespace std;

typedef long long int ll;

typedef pair <int,int> P;



int H,W;

string s[100];

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



void add_edge(int i,int j,int y,int x){

	G[i*W+j].push_back((edge){y*W+x,1});

}



int main()

{

	cin >> H >> W;

	V = H*W;

	int m[4][2] = {1,0,-1,0,0,1,0,-1};

	rep(i,0,H)cin >> s[i];

	int blk = 0;

	rep(i,0,H) rep(j,0,W) {

		if(s[i][j] == '#'){

			blk++;

			continue;

		}

		rep(k,0,4) {

			int y = i+m[k][0];

			int x = j+m[k][1];

			if(y < 0 || y >= H)continue;

			if(x < 0 || x >= W)continue;

			if(s[y][x] == '.')add_edge(i,j,y,x);

		}

	}



	dijkstra(0);



	if(d[H*W-1] >= INF){

		cout << -1 << endl;

		return 0;

	}



	cout << (H*W - d[H*W-1] - 1 - blk) << endl;



	return 0;

}
