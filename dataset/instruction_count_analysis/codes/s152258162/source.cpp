#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

typedef long long ll;

struct edge{int to;ll cost;};

vector<edge> G[60000];

ll dp[60000];

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> qu;//dp[],2*(n-1)*c+v



int a,b,c;

int nextv(int v){ return (a*v+b)%c;}



int main(void){

	int n,m,v0;

	cin>>n>>m;

	vector<int> x(m),y(m);

	vector<ll> t(m); 

	rep(i,m){

		cin>>x[i]>>y[i]>>t[i];

		--x[i];

		--y[i];

	}

	cin>>v0>>a>>b>>c;

	rep(i,m)rep(v,c){

		G[x[i]*c+v].push_back({y[i]*c+nextv(v),t[i]*v});

		G[y[i]*c+v].push_back({x[i]*c+nextv(v),t[i]*v});	

		G[((n-1)*2-x[i])*c+v].push_back({((n-1)*2-y[i])*c+nextv(v),t[i]*v});

		G[((n-1)*2-y[i])*c+v].push_back({((n-1)*2-x[i])*c+nextv(v),t[i]*v});

	}

	rep(i,60000)dp[i]=LLONG_MAX;

	dp[v0]=0;

	qu.push({0,v0});

	while(qu.size()){

		pair<ll,int> u = qu.top();

		qu.pop();

		if(u.second/c==2*(n-1)){

			cout<<dp[u.second]<<endl;

			return 0;			

		}

		if(dp[u.second] < u.first)continue;

		for(auto e:G[u.second]){

			if(dp[e.to] > dp[u.second] + e.cost){

				dp[e.to] = dp[u.second] + e.cost;

				qu.push({dp[e.to],e.to});

			}

		}



	}

	

	// ll res = LLONG_MAX;

	// rep(i,c){

	// 	res = min(res,dp[2*(n-1)*c+i]);

	// }

	// cout<<res<<endl;



	return 0;

}