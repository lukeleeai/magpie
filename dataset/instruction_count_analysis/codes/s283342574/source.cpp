#include <iostream>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <functional>

using namespace std;

const int MAX = 200010;



typedef int W;

typedef pair<int, int> Pii;

const W INF = 1LL << 25;



struct edge {

	int to;

	W cost;

};



typedef vector<vector<edge>> Graph;



void dijkstra(int s, const Graph& G, vector<W>& d) {

	priority_queue<Pii, vector<Pii>, greater<Pii>> que;

	fill(d.begin(), d.end(), INF);

	d[s] = 0;

	que.push(Pii(0, s));

	while (!que.empty()) {

		Pii p = que.top();

		que.pop();

		int v = p.second;

		if (d[v] < p.first) continue;

		for (int i = 0; i < G[v].size(); i++) {

			edge e = G[v][i];

			if (d[e.to] > d[v] + e.cost) {

				d[e.to] = d[v] + e.cost;

				que.push(Pii(d[e.to], e.to));

			}

		}

	}

}



int P[MAX];

int Q[MAX];

int C[MAX];

map<int, set<int>> vc_map;

map<Pii, int> vn_map;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N, M;

	cin >> N >> M;



	set<Pii> vset;

	for (int i = 0; i < M; i++) {

		cin >> P[i] >> Q[i] >> C[i];

		vset.insert(Pii(P[i], C[i]));

		vset.insert(Pii(Q[i], C[i]));

		vc_map[P[i]].insert(C[i]);

		vc_map[Q[i]].insert(C[i]);

	}

	for (int i = 1; i <= N; i++) {

		vset.insert(Pii(i, -1));

	}

	int cnt = 0;

	for (Pii p : vset) {

		vn_map[p] = cnt++;

	}



	Graph graph(cnt);

	for (int i = 0; i < M; i++) {

		int n1 = vn_map[Pii(P[i], C[i])], n2 = vn_map[Pii(Q[i], C[i])];

		graph[n1].push_back(edge{n2, 0});

		graph[n2].push_back(edge{n1, 0});

	}



	for (int i = 1; i <= N; i++) {

		for (int c : vc_map[i]) {

			if (c == -1) continue;

			int n1 = vn_map[Pii(i, -1)], n2 = vn_map[Pii(i, c)];

			graph[n1].push_back(edge{n2, 1});

			graph[n2].push_back(edge{n1, 0});

		}

	}



	int s = vn_map[Pii(1, -1)], g = vn_map[Pii(N, -1)];

	vector<W> d(cnt);

	dijkstra(s, graph, d);



	if (d[g] == INF) d[g] = -1;

	cout << d[g] << endl;

}
