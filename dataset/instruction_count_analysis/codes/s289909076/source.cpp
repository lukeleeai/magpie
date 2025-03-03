#include "stdc++.h"

using namespace std;



vector<int> adj[100005];

vector<bool> vis(100005, false);



void dfs(int i){

	if(!vis[i]) {

		vis[i] = true;

		for(auto v : adj[i])

			dfs(v);

	}

}



void solve() {

	int n, m;

	cin >> n >> m;

	for(int i=0; i<m; i++) {

		int x, y;

		cin >> x >> y;

		--x;

		--y;

		adj[x].push_back(y);

		adj[y].push_back(x);

	}

	int comp = 0;

	for (int i=0; i<n; i++) {

		if(!vis[i]) {

			comp++;

			dfs(i);

		}

	}

	cout << comp-1;

}



int main() {



	solve();	

	return 0;

}