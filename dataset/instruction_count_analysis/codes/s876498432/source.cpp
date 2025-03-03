#include"stdc++.h"

using namespace std;



const int maxn = 1e5 + 15;



int n;

int cnt[maxn];



bool is[maxn];



set<int> st[maxn];

vector<int> g[maxn];



int main() {

	cin >> n;

	for(int i = 0; i < n - 1; i++) {

		int u, v;

		cin >> u >> v;

		u--, v--;

		cnt[u]++;

		cnt[v]++;

		st[u].insert(v);

		st[v].insert(u);		

		g[u].push_back(v);

		g[v].push_back(u);

	}

	queue<int> q;

	for(int i = 0; i < n; i++) {

		if(cnt[i] == 1) {

			q.push(i);

		}

	}

	while(q.size()) {

		int u = q.front();

		if(!cnt[u]) {

			return cout << "First", 0;

		}

		int v = *st[u].begin();

		is[u] = true;

		is[v] = true;

		for(auto it = st[v].begin(); it != st[v].end(); it++) {

			cnt[*it]--;

			st[*it].erase(v);

			if(cnt[*it] == 1)

				q.push(*it);

		}

		q.pop();

	}

	string a = "Second";

	for(int i = 0; i < n; i++) {

		if(!is[i])

			a = "First";

	}

	cout << a;

	

	return 0;

}
