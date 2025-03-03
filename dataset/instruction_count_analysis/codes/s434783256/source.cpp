#include "stdc++.h"

using namespace std;

int n , m;

vector<vector<int>>vi(200005);

map<int,int>mp;

int mem[200005];

bool ok[200005];

int dfs(int node){

	if(mem[node])

		return mem[node];

	for(auto it : vi[node]){

		mem[node] = max(dfs(it) + 1 , mem[node]);

	}

	return mem[node];

}

int main() {

	memset(mem,0,sizeof(mem));

	cin>>n>>m;

	for(int i = 0 ; i < m ; i++){

		int x , y ; cin>>x>>y;

		vi[x].push_back(y);

		mp[y]++;

	}

	for(int i  = 1 ; i <= n ; i++){

		if(!mp[i]){

			dfs(i);

		}

	}

	int ans = 0;

	for(int i = 1 ; i <=  n; i++)

		ans = max(ans,mem[i]);

	cout<<ans;

	return 0;

}
