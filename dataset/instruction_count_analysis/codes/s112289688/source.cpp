#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int, int> ii; 



const int N = 2e5 + 10; 

vector<int> adj[N]; 



int dfs(int u, int par = -1) {

	int g = 0; 

	for(int v : adj[u]) if(v - par) 

		g ^= dfs(v, u) + 1; 

	return g; 

}

int main(int argc, char const *argv[]) {

	int n; cin >> n; 

	for(int i = 1; i < n; i++) {

		int u, v; 

		cin >> u >> v;

		adj[u].push_back(v);

		adj[v].push_back(u);

	}	

	puts(dfs(1) ? "Alice" : "Bob"); 

}