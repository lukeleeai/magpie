#include "stdc++.h"



using namespace std;



#define size(x) ((int) x.size())



const int MAXN = 2e5 + 5;



string s;



vector <int> adj[MAXN];



bool mark[MAXN];



int n, m;

int u, v;

int deg_a[MAXN];

int deg_b[MAXN];

int cnt;



queue <int> Q;



int main() {

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {

		cin >> u >> v;

		u--, v--;

		adj[u].push_back(v);

		adj[v].push_back(u);

		/*if (s[u] == 'A')

			deg_a[v]++;

		else

			deg_b[u]++;

		if (s[v] == 'A')

			deg_a[u]++;

		else

			deg_b[u]++;*/

		(s[u] == 'A' ? deg_a[v]++ : deg_b[v]++);

		(s[v] == 'A' ? deg_a[u]++ : deg_b[u]++);

	}

//	for (int i = 0; i < n; i++) 

//		cout << i << " : " << deg_a[i] << " " << deg_b[i] << endl;

	cnt = n;

	for (int i = 0; i < n; i++) 

		if (!deg_a[i] || !deg_b[i]) {

			Q.push(i);

			mark[i] = true;

		}

	while (!Q.empty()) {

		int u = Q.front();

		Q.pop();

		cnt--;

		for (int i = 0; i < size(adj[u]); i++) {

			int v = adj[u][i];

			(s[u] == 'A') ? deg_a[v]-- : deg_b[v]--;

			if ((!deg_a[v] || !deg_b[v]) && !mark[v]) {

				Q.push(v);

				mark[v] = true;

			}

		}

	}

	if (cnt)

		cout << "Yes";

	else

		cout << "No";

	cout << endl;

	return 0;

}