#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<vector>

#include<queue>

#include<functional>

 

 

#define rep(i,n) for(int i=0;i<(n);i++)

 

using namespace std;

const int INF = 100000000;

const double EPS = 0.0000001;

typedef pair<int,int> P;



int n,m;



struct edge

{

	//どこから来た,コスト,速度制限

	int to,cost,ub;

	edge(int to,int cost,int ub) {

		this->to = to;

		this->cost = cost;

		this->ub = ub;

	}

};



vector<edge> G[103];

int s,g;

double dist[103][103][33];



typedef pair<double,int> PD;

typedef pair<PD,P> PP;



double dijkstra() {

	rep(i,103) rep(j,103) rep(k,33) dist[i][j][k]=INF;

	dist[s][0][0]=0;



	//最短距離 頂点 前の頂点 今の速さ

	priority_queue<PP,vector<PP>,greater<PP> > que;

	que.push(PP(PD(0,s),P(0,0)));



	while (!que.empty())

	{

		PP pp = que.top(); que.pop();

		int v = pp.first.second;



		int prev = pp.second.first;

		//今の速度

		int u = pp.second.second;



		//printf("[debug] %f,%d,%d,%d\n",pp.first.first,v,prev,u);



		if(dist[v][prev][u] < pp.first.first) continue;



		rep(i,G[v].size()) {

			edge e = G[v][i];

			if(e.to == prev) continue;

			for(int j=-1;j<=1;j++) {

				if(j+u<=0 || u+j > e.ub) continue;





				if(dist[e.to][v][u+j] > dist[v][prev][u] + (1.0*e.cost/(u+j))) {

					dist[e.to][v][u+j] = dist[v][prev][u] + (1.0*e.cost/(u+j));



					que.push(PP(PD(dist[e.to][v][u+j],e.to),P(v,u+j)));

				}

			}

		}



	}

	double ans=INF;

	rep(i,103) ans=min(ans,dist[g][i][1]);



	return ans;

	

}



void solve() {

	rep(i,103) G[i].clear();

	cin>>s>>g;

	rep(i,m) {

		int x,y,d,c;

		cin>>x>>y>>d>>c;

		G[x].push_back(edge(y,d,c));

		G[y].push_back(edge(x,d,c));

	}



	double ans;

	ans = dijkstra();

	if(ans==INF) {

		cout<<"unreachable"<<endl;

	}

	else

	{

		cout<<ans<<endl;

	}





}



int main() {

	while (cin>>n>>m)

	{

		if(n+m==0) return 0;

		solve();



	}







}