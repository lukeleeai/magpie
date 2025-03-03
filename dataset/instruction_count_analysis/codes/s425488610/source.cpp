#include <iostream>

#include <vector>

#define rep(i,s,n)for(int i = s;i<n;i++)

#define repe(i,s,n)for(int i = s;i<=n;i++)

using namespace std;

static const int MAX_V = 50;



//Graph Element

struct E {

	E(int t, int f) {

		to = t;

		from = f;

	}

	E(int t, int f, int c) {

		to = t;

		from = f;

		cost = c;

	}

	int to;

	int from;

	int cost;

	bool visited;

	bool use;

};

struct V {

	vector<E*> edge;

	bool visited;

};

V G[MAX_V];

/////////////////////////////////////////////



//dfs

int ans = 0;

int VS, ES;

void dfs(int n) {

	rep(i, 0, G[n].edge.size()) {

		if (G[n].edge[i]->use && !G[G[n].edge[i]->to].visited) {

			G[G[n].edge[i]->to].visited = true;

			dfs(G[n].edge[i]->to);

		}

	}

}



int main() {

	cin >> VS >> ES;



	rep(i, 0, ES)

	{

		int s, t; cin >> s >> t;

		G[s].edge.push_back(new E(t, s));

		G[t].edge.push_back(new E(s, t));

	}



	///////////////////////////////////////////////////////////



	//Edge all false

	repe(i, 1, VS) rep(j, 0, G[i].edge.size()) {

		//Edge all visited false;

		repe(k, 1, VS) rep(l, 0, G[k].edge.size()) G[k].edge[l]->use = true;

		repe(k, 1, VS) G[k].visited = false;



		G[i].edge[j]->use = false;



		//DFS

		G[1].visited = true;

		dfs(1);



		bool ok = true;

		repe(k, 1, VS)  ok &= G[k].visited;

		if (!ok)ans++;

	}



	cout << ans << endl;



	return 0;

}