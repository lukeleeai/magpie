#include <set>

#include <queue>

#include <vector>

#include <iostream>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

struct edge {

	int to, id;

};

bool operator<(const edge& e1, const edge& e2) {

	if (e1.to != e2.to) return e1.to < e2.to;

	return e1.id < e2.id;

}

int N, M, Q, a[200009], b[200009], dist[100009], r[200009], ans[200009];

vector<int> g[100009]; set<edge> G[100009];

bool ok[200009], vis[200009];

int main() {

	scanf("%d%d%d", &N, &M, &Q);

	for (int i = 0; i < M; i++) {

		scanf("%d%d", &a[i], &b[i]); a[i]--, b[i]--;

		g[a[i]].push_back(b[i]);

		g[b[i]].push_back(a[i]);

	}

	fill(dist + 1, dist + N, 999999999);

	queue<int> que; que.push(0);

	while (!que.empty()) {

		int u = que.front(); que.pop();

		for (int i : g[u]) {

			if (dist[i] == 999999999) {

				dist[i] = dist[u] + 1;

				que.push(i);

			}

		}

	}

	fill(ok, ok + M, true);

	for (int i = 0; i < Q; i++) scanf("%d", &r[i]), ok[--r[i]] = false; r[Q] = M;

	for (int i = 0; i < M; i++) {

		if (dist[a[i]] > dist[b[i]]) swap(a[i], b[i]);

		if (dist[a[i]] != dist[b[i]] && ok[i]) {

			G[a[i]].insert(edge{ b[i], i });

		}

	}

	int sum = 1;

	fill(ok, ok + N, false); ok[0] = true;

	for (int i = Q - 1; i >= 0; i--) {

		if (ok[a[r[i + 1]]]) {

			queue<int> que2; que2.push(a[r[i + 1]]);

			while (!que2.empty()) {

				int u = que2.front(); que2.pop();

				if (!ok[u]) ok[u] = true, sum++;

				vector<int> l;

				for (edge e : G[u]) {

					if (!vis[e.id]) {

						vis[e.id] = true; l.push_back(e.id);

						que2.push(e.to);

					}

				}

				for (int i : l) {

					G[u].erase(edge{ b[i], i });

				}

			}

		}

		ans[i] = sum;

		if (dist[a[r[i]]] != dist[b[r[i]]]) {

			G[a[r[i]]].insert(edge{ b[r[i]], r[i] });

		}

	}

	for (int i = 0; i < Q; i++) printf("%d\n", N - ans[i]);

	return 0;

}