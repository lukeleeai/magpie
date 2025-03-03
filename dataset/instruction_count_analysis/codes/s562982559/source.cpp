#include "stdc++.h"

using namespace std;



constexpr int MAX_LEN = 6;

constexpr int MAX_N = 40;



struct edge {

	int to;

	string cost;

	edge(int to_, const string &cost_):to(to_), cost(cost_) {}

	edge(int to_, string &&cost_):to(to_), cost(move(cost_)) {}

};



void dfs(int v, const vector<vector<int>> &G, bitset<MAX_N> &visited) {

	visited[v] = true;

	for(const auto &to : G[v]) {

		if(!visited[to]) dfs(to, G, visited);

	}

}



string dijkstra(int s, int g, const vector<vector<edge>> &G, const bitset<MAX_N> &reach) {

	if(!reach[s]) return "NO";



	typedef pair<string, int> state;



	const int n = G.size();

	const int limit = n * MAX_LEN;



	vector<vector<string>> dist(n, vector<string>(limit + MAX_LEN + 1, "{"));

	dist[s][0] = "";



	priority_queue<state, vector<state>, greater<state>> que;

	que.push({"", s});



	while(!que.empty()) {

		const string d = que.top().first;

		const int v = que.top().second;

		const int l = d.size();

		que.pop();



		if(v == g) return d;

		if(l > limit) return "NO";

		if(dist[v][l] > d) continue;



		for(const auto &e : G[v]) {

			if(!reach[e.to]) continue;



			const string next_dist = d + e.cost;

			const int next_len = next_dist.size();

			if(dist[e.to][next_len] > next_dist) {

				que.push({next_dist, e.to});

				dist[e.to][next_len] = move(next_dist);

			}

		}

	}



	return "NO";

}



int main() {

	cin.tie(nullptr);

	ios::sync_with_stdio(false);



	for(int n, m, s, g; cin >> n >> m >> s >> g && n;) {

		vector<vector<edge>> G(n);

		vector<vector<int>> rG(n);



		while(m--) {

			int x, y;



			string lab;

			cin >> x >> y >> lab;

			G[x].emplace_back(y, move(lab));

			rG[y].emplace_back(x);

		}



		bitset<MAX_N> visited;

		dfs(g, rG, visited);

		cout << dijkstra(s, g, G, visited) << endl;

	}



	return EXIT_SUCCESS;

}