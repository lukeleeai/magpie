#include "stdc++.h"

using namespace std;



const int MAXN = 6000;

vector<pair<long long, pair<int, int>>> adj;

vector<int> adj2[MAXN];

vector<int> adj3[MAXN];

long long dist[MAXN];

int pai[MAXN];

bitset<MAXN> mark, mark2;

int n, m;



void bfs2(int u){

	mark2[u] = 0;

	queue<int> Q;

	Q.push(u);

	while(!Q.empty()){

		int v = Q.front();

		Q.pop();



		for (int k = 0; k < adj3[v].size(); k++){

			int foco = adj3[v][k];

			if (mark2[foco]){

				mark2[foco] = 0;

				//cout << foco << " ---\n";

				Q.push(foco);

			}

		}

	}

}





void bfs(int u){

	mark[u] = 0;

	queue<int> Q;

	Q.push(u);

	while(!Q.empty()){

		int v = Q.front();

		Q.pop();



		for (int k = 0; k < adj2[v].size(); k++){

			int foco = adj2[v][k];

			if (mark[foco]){

				mark[foco] = 0;

				//cout << foco << " ---\n";

				Q.push(foco);

			}

		}

	}

}



int bellmanFord(int s){

	//bellman-ford

	dist[s] = 0;

	for (int i = 1; i < n; i++){

		for (int k = 0; k < adj.size(); k++){

			if (dist[adj[k].second.second] < dist[adj[k].second.first] + adj[k].first){

				dist[adj[k].second.second] = dist[adj[k].second.first] + adj[k].first;

				pai[adj[k].second.second] = adj[k].second.first;

			}

		}

	}

	for (int k = 0; k < adj.size(); k++){

		if (dist[adj[k].second.second] < dist[adj[k].second.first] + adj[k].first && 

			mark[adj[k].second.second] == 0 && mark[adj[k].second.first] == 0 && 

			mark2[adj[k].second.second] == 0 && mark2[adj[k].second.first] == 0){

			//cout << adj[k].second.second << " " << adj[k].second.first << endl;

			return 0;

		}

	}

	return 1;

}



int main(){

	memset(pai, 0, sizeof(pai));

	long long p, w;

	cin >> n >> m >> p;

	for (int i = 0; i <= n; i++)

		dist[i] = -1e9;

	int a, b;

	for (int i = 0; i < m; i++){

		cin >> a >> b >> w;

		a--;

		b--;

		adj.push_back({w-p, {a, b}});

		adj2[b].push_back(a);

		adj3[a].push_back(b);

	}

	mark.set();

	bfs(n-1);

	mark2.set();

	bfs2(0);

	if(!bellmanFord(0)){

		cout << "-1\n";

		return 0;

	}



	if (dist[n-1] < 0) cout << "0\n";

	else cout << dist[n-1] << "\n";



	return 0;

}