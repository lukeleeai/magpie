# include <iostream>

# include <algorithm>

# include <vector>

# include <string>

# include <set>

# include <map>

# include <cmath>

# include <iomanip>

# include <functional>

# include <utility>

# include <stack>

# include <queue>

# include <list>

constexpr int MOD = 1000000007;

constexpr int INF = 2000000000;

using namespace std;



constexpr int MAX = 100000;



vector<int> G[MAX];

list<int> out;

bool V[MAX];

int N;

int indeg[MAX];



void bfs(int s) {

	queue<int> q;

	q.push(s);

	V[s] = true;

	while (!q.empty()) {

		int u = q.front();

		q.pop();

		out.emplace_back(u);

		for (int i = 0; i < G[u].size(); i++) {

			int v = G[u][i];

			indeg[v]--;

			if (indeg[v] == 0 && !V[v]) {

				V[v] = true;

				q.push(v);

			}

		}

	}

}

void tsort() {

	for (int i = 0; i < N; i++) {

		indeg[i] = 0;

	}



	for (int u = 0; u < N; u++) {

		for (int i = 0; i < G[u].size(); i++) {

			int v = G[u][i];

			indeg[v]++;

		}

	}



	for (int u = 0; u < N; u++) {

		if (indeg[u] == 0 && !V[u])bfs(u);

	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {

		cout << *it << endl;

	}

}



int main() {

	int s, t, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		V[i] = false;

	}

	for (int i = 0; i < M; i++) {

		cin >> s >> t;

		G[s].emplace_back(t);

	}

	tsort();

}