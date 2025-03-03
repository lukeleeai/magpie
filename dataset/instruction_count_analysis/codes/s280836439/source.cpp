#include "stdc++.h"

using namespace std;



int main(void) {

	int n, m, r;

	cin >> n >> m;

	vector<int> tree(n);

	vector<vector<int> > parent(n, vector<int>(0)), child(n, vector<int>(0));

	

	for (int i = 0; i < n - 1 + m; i++) {

		int a, b;

		cin >> a >> b;

		a--; b--;

		parent[b].push_back(a);

		child[a].push_back(b);

	}

	

	for (int i = 0; i < n; i++) {

		if (parent[i].size() == 0) r = i;

	}

	

	queue<int> q;

	vector<int> v(n, 0);

	q.push(r);

	

	tree[r] = -1;

	

	while (!q.empty()) {

		int now = q.front(); q.pop();

		

		for (int i = 0; i < child[now].size(); i++) {

			bool flag = true;

			int next = child[now][i];

			

			v[next]++;

			

			if (v[next] != parent[next].size()) continue;

			

			tree[next] = now;

			q.push(next);

		}

	}

	

	for (int i = 0; i < n; i++) cout << tree[i] + 1 << endl;

}