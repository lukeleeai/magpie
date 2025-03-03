#include "stdc++.h"

using namespace std;

#define ll long long



const int NMAX = 1e5+1;



int parent[NMAX], n;

int subnodes[NMAX];

bool visited[NMAX];

vector<int> adj[NMAX];



void dfs(int node){

	visited[node] = true;

	for(int v : adj[node]){

		if(!visited[v]){

			dfs(v);

			parent[v] = node;

			subnodes[node] += subnodes[v];

		}

	}

	subnodes[node]++;

}



bool ans(){

	vector<int> q;

	int node = n - 1;

	parent[0] = -1;

	while(node != -1){

		q.push_back(node);

		node = parent[node];

	}

	int len = q.size(), fennec = len>>1, i = 0;

	ll a = 0, b = 0;

	for(int i = 0; i < len; i++){

		node = q[i];

		for(int v : adj[node]){

			if((i == 0 ||(i > 0 && q[i-1] != v)) && (i + 1 == len||(i + 1 < len && q[i+1] != v))){

				if(i >= fennec){

					a += subnodes[v];

				}else{

					b += subnodes[v];

				}

			}

		}

	}

	if(len%2 == 0){

		return a > b;

	}else{

		return a >= b;

	}

}



int main()

{

	ios::sync_with_stdio(false);cin.tie(NULL);

	cin >> n;

	int a, b;

	for(int i = 0; i < n - 1; i++){

		cin >> a >> b;

		a--;

		b--;

		adj[a].push_back(b);

		adj[b].push_back(a);

	}

	dfs(0);

	if(ans()){

		cout << "Fennec";

	}else{

		cout << "Snuke";

	}

	return 0;

}


