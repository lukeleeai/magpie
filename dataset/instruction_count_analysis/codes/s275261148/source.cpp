#include "stdc++.h"



using namespace std;



const int N = 2e5 + 100;



queue<int> q;

vector<int> adj[N];

bool mark[N];

char a[N];

int d1[N], d2[N];

int n, m, cnt;



int main() {

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)

		cin >> a[i];

	for (int i = 0; i < m; i++) {

		int v, u;

		cin >> v >> u;

		adj[--v].push_back(--u);

		adj[u].push_back(v);

		(a[v] == 'A' ? d1[u]++ : d2[u]++);

		(a[u] == 'A' ? d1[v]++ : d2[v]++);

	}

	for (int i = 0; i < n; i++)

		if (!d1[i] || !d2[i]) {

			q.push(i);

			mark[i] = true;

		}

	cnt = n;

	while (!q.empty()) {

		int v = q.front();

		q.pop();

		cnt--;

		for (auto u : adj[v]) {

			(a[v] == 'A' ? d1[u]-- : d2[u]--);

			if ((!d1[u] || !d2[u]) && !mark[u]) {

				mark[u] = true;

				q.push(u);

			}

		}

	}

	return cout << (cnt ? "Yes" : "No"), 0;

}