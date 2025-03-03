/*In the name of Allah*/

#include "stdc++.h"

using namespace std;

#define inf 1000000001

#define MAX 200005

#define mod 1000000007

#define ll long long

#define fr first

#define sc second

bool c[MAX];

vector< pair<int,int> > g[MAX];

void dfs(int u,int par ){

	for(auto v : g[u]){

		if(v.fr != par){

			if(v.sc&1)c[v.fr] = 1 - c[u];

			else c[v.fr] = c[u];

			dfs(v.fr,u);

		}

	}

}



int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n,x,y,w;

	cin>>n;

	for(int i = 0; i < n - 1; i++){

		cin>>x>>y>>w;

		g[x].push_back({y,w});

		g[y].push_back({x,w});

	}

	dfs(1,0);

	for(int i = 1; i <= n ;i++)cout<<c[i]<<endl;

	return 0;

}
