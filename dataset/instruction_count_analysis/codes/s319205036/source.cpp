#include <queue>

#include <vector>

#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

int N, M, Q, a[200009], b[200009], r[200009], f[200009], dist[200009], ret[200009]; vector<int> g[200009], gt[200009]; bool vis[100009];

int main() {

	scanf("%d%d%d", &N, &M, &Q);

	for (int i = 0; i < M; i++) {

		scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;

		g[a[i]].push_back(b[i]);

		g[b[i]].push_back(a[i]);

	}

	fill(f, f + M, -1);

	for (int i = 0; i < Q; i++) scanf("%d", &r[i]), r[i]--, f[r[i]] = i;

	queue<int> que1; que1.push(0);

	fill(dist, dist + N, -1); dist[0] = 0;

	while (!que1.empty()) {

		int u = que1.front(); que1.pop();

		for (int i : g[u]) {

			if (dist[i] == -1) {

				dist[i] = dist[u] + 1;

				que1.push(i);

			}

		}

	}

	for (int i = 0; i < M; i++) {

		if (dist[a[i]] == dist[b[i]]) continue;

		if (dist[a[i]] > dist[b[i]]) swap(a[i], b[i]);

		if (f[i] == -1) gt[a[i]].push_back(b[i]);

	}

	int cnt = N - 1;

	vector<bool> vis(N); vis[0] = true;

	queue<int> que2; que2.push(0);

	while (!que2.empty()) {

		int u = que2.front(); que2.pop();

		for (int i : gt[u]) {

			if (!vis[i]) {

				vis[i] = true; cnt--;

				que2.push(i);

			}

		}

	}

	for (int i = Q - 1; i >= 0; i--) {

		ret[i] = cnt;

		if (dist[a[r[i]]] == dist[b[r[i]]]) continue;

		gt[a[r[i]]].push_back(b[r[i]]);

		if (vis[a[r[i]]] && !vis[b[r[i]]]) {

			vis[b[r[i]]] = true; cnt--;

			queue<int> que; que.push(b[r[i]]);

			while (!que.empty()) {

				int u = que.front(); que.pop();

				for (int j : gt[u]) {

					if (!vis[j]) {

						vis[j] = true, cnt--;

						que.push(j);

					}

				}

			}

		}

	}

	for (int i = 0; i < Q; i++) printf("%d\n", ret[i]);

	return 0;

}