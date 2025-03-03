#include"stdc++.h"

using namespace std;

const int maxN = 3e5 + 13;

int n, val[maxN], deg[maxN];

vector<int> adj[maxN];

map<pair<int, int>, bool> mark;

void dfs (int x) {

    while (adj[x].size()) {

	int u = adj[x].back();

	adj[x].pop_back();

	if (!mark[make_pair(u, x)]) {

	    mark[make_pair(u, x)] = 1;

	    mark[make_pair(x, u)] = 1;

	    if (x < n && u >= n && u != 2 * n)

		val[x] = 1;

	    if (x >= n && u < n && x != 2 * n) 

		val[u] = -1;

	    dfs(u);

	}

    }

}	

	    

int main () {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {

	int p;

	cin >> p;

	if (p == -1) {

	    adj[2 * n].push_back(i);

	    adj[i].push_back(2 * n);

	}

	else {

	    p--;

	    adj[p].push_back(i);

	    adj[i].push_back(p);

	    deg[p]++;

	}

    }

    for (int i = 0; i < n; i++) {

	int p;

	cin >> p;

	if (p == -1) {

	    adj[2 * n].push_back(i + n);

	    adj[i + n].push_back(2 * n);

	}

	else {

	    p += n - 1;

	    adj[p].push_back(i + n);

	    adj[i + n].push_back(p);

	    deg[p]++;

	}

    }

    

    for (int i = 0; i < n; i++) {

	if (deg[i] % 2 != deg[i + n] % 2)

	    return cout << "IMPOSSIBLE" << endl, 0;

	if (deg[i] % 2 == 0) {

	    adj[i].push_back(i + n);

	    adj[i + n].push_back(i);

	}

	else

	    val[i] = val[i + n] = 0;

    }

    cout << "POSSIBLE\n";

    dfs(2 * n);

    for (int i = 0; i < n; i++)

	cout << val[i] << " ";

    cout << '\n';

}
