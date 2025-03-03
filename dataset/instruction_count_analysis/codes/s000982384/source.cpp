#include"stdc++.h"

using namespace std;

using ll = long long;





struct Edge {

	int to, dist, cap;

	Edge(int t, int d, int c) {

		to = t;

		dist = d;

		cap = c;

	}

};



struct State {

	int pos, prev, v;

	double time;

	State(int p, int pr, int v_, double t) {

		pos = p;

		prev = pr;

		v = v_;

		time = t;

	}

	bool operator<(const State& right) const {

		return time > right.time;

	}

};



double min_time[32][32][32];

bool visited[32][32][32];



int main() {

	while(true) {

		int n, m;

		cin >> n >> m;

		if (n == 0) break;



		int start, goal;

		cin >> start >> goal;

		start--;

		goal--;



		vector<vector<Edge>> G(n);

		for (int i = 0; i<m; i++) {

			int x, y, d, c;

			cin >> x >> y >> d >> c;

			x--;

			y--;

			G[x].emplace_back(y, d, c);

			G[y].emplace_back(x, d, c);

		}



		memset(visited, 0, sizeof(visited));

		priority_queue<State> que;

		que.emplace(start, start, 0, 0);

		visited[start][start][0] = true;

		min_time[start][start][0] = 0;



		double ans = -1;

		while (!que.empty()) {

			auto s = que.top();

			que.pop();

			if (min_time[s.pos][s.prev][s.v] < s.time) continue;

			if (s.pos == goal && s.v == 1) {

				ans = s.time;

				break;

			}

			for (int dv = -1; dv <= 1; dv++) {

				int nv = s.v + dv;

				for (auto& e : G[s.pos]) {

					if (e.to == s.prev) continue;

					if (nv < 1 || e.cap < nv) continue;

					double nt = s.time + double(e.dist) / nv;

					if (!visited[e.to][s.pos][nv] || min_time[e.to][s.pos][nv] > nt) {

						visited[e.to][s.pos][nv] = true;

						min_time[e.to][s.pos][nv] = nt;

						que.emplace(e.to, s.pos, nv, nt);

					}

				}

			}

		}



		if (ans < 0) {

			cout << "unreachable" << endl;

		} else {

			printf("%.5f\n", ans);

		}

	}



	return 0;

}


