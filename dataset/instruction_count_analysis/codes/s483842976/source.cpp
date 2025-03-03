#include <cstdlib>

#include <cstring>

#include <functional>

#include <iostream>

#include <queue>

#include <utility>

#include <vector>

using namespace std;



const int MAX_LEN = 6;

const int MAX_N = 40;

const int LIMIT = MAX_LEN * MAX_N;

const string INF(LIMIT, 'z');



struct edge {

	int to;

	string cost;

	edge(int t, const string& c):to(t), cost(c){}

};



bool to_goal[MAX_N];

vector<vector<edge> > es;



string dijkstra(int s, int g) {

	typedef pair<string, int> P;

	const int n = es.size();

	vector<vector<string> > dist(n, vector<string>(LIMIT + MAX_LEN + 1, INF));

	dist[s][0] = "";

	priority_queue<P, vector<P>, greater<P> > que;

	que.push(make_pair("", s));



	while(!que.empty()) {

		const string spell = que.top().first;

		const int v = que.top().second, len = spell.size();

		que.pop();



		if(!to_goal[v] || dist[v][len] != spell)

			continue;



		if(len > LIMIT)

			return "NO";



		if(v == g)

			return spell;



		for(int i = 0; i < es[v].size(); ++i) {

			const edge& e = es[v][i];

			if(!to_goal[e.to])

				continue;



			const string next_spell = spell + e.cost;

			const int next_len = next_spell.size();

			if(dist[e.to][next_len] > next_spell) {

				dist[e.to][next_len] = next_spell;

				que.push(make_pair(next_spell, e.to));

			}

		}

	}



	return "NO";

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	for(int n, a, s, g; cin >> n >> a >> s >> g, n;) {

		es.clear();

		es.resize(n);

		for(int i = 0; i < a; ++i) {

			int x, y;

			string lab;

			cin >> x >> y >> lab;

			es[x].push_back(edge(y, lab));

		}



		memset(to_goal, false, sizeof(to_goal));

		to_goal[g] = true;



		for(int i = 0; i < n; ++i) {

			for(int j = 0; j < n; ++j) {

				if(!to_goal[j]) {

					for(int k = 0; k < (int)es[j].size(); ++k) {

						if(to_goal[es[j][k].to]) {

							to_goal[j] = true;

							break;

						}

					}

				}

			}

		}



		cout << dijkstra(s, g) << endl;

	}



	return EXIT_SUCCESS;

}