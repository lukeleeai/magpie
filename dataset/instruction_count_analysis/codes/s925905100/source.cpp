#include "stdc++.h"

using namespace std;



using ll = long long;



#define REP(i, n) for (int i = 0; i < (n); ++i)

#define SIZE(a) ((int)(a).size())



// Adam Polak, Michal Glapa

const int N = 100005;

int n1,n2;          // INPUT

vector<int> g[N];   // INPUT

int m1[N], m2[N];   // OUTPUT

bool in_vc1[N], in_vc2[N]; // OUTPUT (Vertex Cover)

bool vis[N];



bool dfs(int u) {

	if (u<0) return true;

	if (vis[u]) return false; else vis[u]=true;

	for(int v : g[u])

		if (dfs(m2[v])) { m1[u] = v; m2[v] = u; return true; }

	return false;

}



int matching() {

	REP(i,n1) m1[i] = -1;

	REP(i,n2) m2[i] = -1;

	bool changed;

	do {

		changed = 0;

		REP(i,n1) vis[i] = false;

		REP(i,n1) if (m1[i] < 0) changed |= dfs(i);

	} while(changed);

	REP(i, n1) if (m1[i] != -1) { //Vertex Cover

		if (vis[i]) in_vc2[m1[i]] = true; // Vertex Cover

		else in_vc1[i] = true; // Vertex Cover

	}

	int siz = 0;

	REP(i,n1) siz += (m1[i] != -1);

	return siz;

}



int X1[N], Y1[N];

int X2[N], Y2[N];



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	cin >> n1;

	n2 = n1;

	REP(i, n1) cin >> X1[i] >> Y1[i];

	REP(i, n2) cin >> X2[i] >> Y2[i];



	REP(i, n1) REP(j, n2) {

		if (X1[i] < X2[j] && Y1[i] < Y2[j]) {

			g[i].push_back(j);

		}

	}



	cout << matching() << '\n';



	return 0;

}