#include<iostream>

#include<queue>

using namespace std;

#pragma warning(disable:4996)

int n, m, q, dist[110000], mark[110000], u[210000], v[210000];

vector<pair<int, int>>x[110000], y[110000], z[110000]; bool used[210000];

bool isgood(int f) {

	for (int i = 0; i < z[f].size(); i++) {

		if (mark[z[f][i].first] == 0 && used[z[f][i].second] == false)return true;

	}

	return false;

}

int main() {

	scanf("%d%d%d", &n, &m, &q); queue<int>Q;

	for (int i = 0; i < m; i++) {

		int a, b; scanf("%d%d", &a, &b); u[i + 1] = a; v[i + 1] = b;

		x[a].push_back(make_pair(b, i + 1)); x[b].push_back(make_pair(a, i + 1));

	}

	Q.push(1); for (int i = 1; i <= n; i++)dist[i] = 999999; dist[1] = 0;

	while (!Q.empty()) {

		int a1 = Q.front(); Q.pop();

		for (int i = 0; i < x[a1].size(); i++) {

			if (dist[x[a1][i].first] > dist[a1] + 1) { dist[x[a1][i].first] = dist[a1] + 1; Q.push(x[a1][i].first); }

		}

	}

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < x[i].size(); j++) {

			if (dist[i] < dist[x[i][j].first]) { y[i].push_back(x[i][j]); }

			if (dist[i] > dist[x[i][j].first]) { z[i].push_back(x[i][j]); }

		}

	}

	int cnt = 0;

	for (int i = 0; i < q; i++) {

		int a; scanf("%d", &a); used[a] = true;

		int E1 = u[a], E2 = v[a];

		if (dist[E1] == dist[E2]) { cnt += 0; }

		else {

			int a1 = 0; if (dist[E1] < dist[E2])a1 = E2; else a1 = E1;

			if (isgood(a1) == false && mark[a1] == 0) {

				queue<int>Q; Q.push(a1); cnt++; mark[a1] = 1;

				while (!Q.empty()) {

					int a2 = Q.front(); Q.pop();

					for (int j = 0; j < y[a2].size(); j++) {

						if (mark[y[a2][j].first] == 0 && isgood(y[a2][j].first) == false) {

							mark[y[a2][j].first] = 1; Q.push(y[a2][j].first); cnt++;

						}

					}

				}

			}

		}

		cout << cnt << endl;

	}

	return 0;

}