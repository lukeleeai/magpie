// In the name of God



#include "stdc++.h"



using namespace std;



const int N = 1e5+5;



int p[2 * N];



int find_set(int u) {

	if(p[u] == u) return u;

	return p[u] = find_set(p[u]);

}



void union_set(int u, int v) {

	int pu = find_set(u);

	int pv = find_set(v);

	p[pu] = pv;

}



int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	for(int i = 0; i < 2 * N; i++) p[i] = i;

	int n, m;

	cin >> n >> m;

	for(int i = 0; i < n; i++) {

		int k;

		cin >> k;

		for(int j = 0; j < k; j++) {

			int x;

			cin >> x;

			x--;

			union_set(i, n + x);

		}

	}

	set<int> s;

	for(int i = 0; i < n; i++) s.insert(find_set(i));

	if(s.size() == 1) cout << "YES";

	else cout << "NO";

	return 0;

}
