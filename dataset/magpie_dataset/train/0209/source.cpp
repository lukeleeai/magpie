#include"stdc++.h"

#define rep(i,n)for(int i=0;i<n;i++)

using namespace std;



vector<int>E[100000], pr[100000];

int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;

bool b[200000], ok[100000];



void bfs(int u) {

	queue<int>que;

	que.push(u);

	while (!que.empty()) {

		int p = que.front(); que.pop();

		for (int v : E[p]) {

			if (d[v] == d[p] + 1 && !ok[v]) {

				ok[v] = true; cnt++; que.push(v);

			}

		}

	}

}

int main() {

	int n, m, q; scanf("%d%d%d", &n, &m, &q);

	rep(i, m) {

		scanf("%d%d", &u[i], &v[i]);

		u[i]--; v[i]--;

		E[u[i]].push_back(v[i]); E[v[i]].push_back(u[i]);

	}

	queue<int>que;

	memset(d, -1, sizeof(d));

	d[0] = 0; que.push(0);

	while (!que.empty()) {

		int p = que.front(); que.pop();

		for (int i : E[p]) {

			if (d[i] == -1) {

				d[i] = d[p] + 1; que.push(i);

			}

		}

	}

	rep(i, m) {

		if (d[u[i]] > d[v[i]])swap(u[i], v[i]);

	}

	rep(i, n)E[i].clear();

	rep(i, q) {

		scanf("%d", &r[i]); r[i]--;

		b[r[i]] = true;

	}

	ok[0] = true;

	rep(i, m) {

		if (!b[i]) {

			if (d[v[i]] - d[u[i]] == 1) {

				E[u[i]].push_back(v[i]);

			}

		}

	}

	bfs(0);

	for (int i = q - 1; i >= 0; i--) {

		ans[i] = n - cnt;

		if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {

			E[u[r[i]]].push_back(v[r[i]]);

			if (ok[u[r[i]]]) {

				cnt++; ok[v[r[i]]] = true;

				bfs(v[r[i]]);

			}

		}

	}

	rep(i, q)printf("%d\n", ans[i]);

}