#include "stdc++.h"



#define pb push_back



using namespace std;



const int MAXN = 3e4 + 10;



int a[MAXN];



vector<int> adj[MAXN];



bool dfs(int u) {

	for (int v : adj[u]) {

		if (a[v] < a[u] && !dfs(v))

			return true;

	}

	return false;

}



int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)

		cin >> a[i];

	for (int i = 1; i < n; ++i) {

		int u, v;

		cin >> u >> v;

		u--;

		v--;

		adj[u].pb(v);

		adj[v].pb(u);

	}

	for (int i = 0; i < n; i++) {

		if (dfs(i))

			cout << i + 1 << " ";

	}



	return 0;

}