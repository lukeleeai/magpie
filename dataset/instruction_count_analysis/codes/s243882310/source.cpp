#include "stdc++.h"

using namespace std;



const int N = 3e5 + 10;

string s;

int n, m, v, u, degA[N], degB[N], mark[N];

vector<int> adj_matrix[N], que;



int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);cout.tie(0);

	

	cin >> n >> m;

	cin >> s;

	for (int i = 0; i < m; i++){

		cin >> v >> u;

		v--;u--;

		

		if(v == u){

			adj_matrix[v].push_back(v);

			degA[v] += (s[v] == 'A');

			degB[v] += (s[v] == 'B');

		}

		else{

			adj_matrix[v].push_back(u);

			adj_matrix[u].push_back(v);

			degA[v] += (s[u] == 'A');

			degB[v] += (s[u] == 'B');

			degA[u] += (s[v] == 'A');

			degB[u] += (s[v] == 'B');

		}

		

	}

	

	for (int i = 0; i < n; i++)

		if(degA[i] == 0 || degB[i] == 0)

			que.push_back(i), mark[i] = true;

	

	int i = 0;

	while(que.size() < n && i < que.size()){

		int v = que[i];

		for (int j : adj_matrix[v]){

			if(mark[j])

				continue;

			degA[j] -= (s[v] == 'A');

			degB[j] -= (s[v] == 'B');

			

			if(degA[j] == 0 || degB[j] == 0)

				que.push_back(j), mark[j] = true;

		}

		i++;

	}

	

	if(que.size() < n)

		cout << "Yes";

	else

		cout << "No";

}