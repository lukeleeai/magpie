#include <iostream>

#include <vector>

#include <map>

#include <string.h>

#include <algorithm>

#define P pair<int,int>

#define INF (1<<30)

using namespace std;



vector<int> Ind(100010);		//Ind[n]  ??\???n???euler tour??¨??§???????????°?????????

vector<bool> f(100010, false);	//

vector<vector<int>> T(100010);	//??°??????

vector<P> ET;                   //????????¢?´¢??¨



void dfs(int n,int dep) {

	f[n] = true;

	ET.emplace_back(make_pair(dep,n));

	Ind[n] = ET.size() - 1;

	for (int next : T[n]) {

		if (f[next] == true) continue;

		dfs(next,dep + 1);

		ET.emplace_back(make_pair(dep,n));

	}

}



P RMQ(int a, int b, int k, int l, int r, vector<P>& node) {

	if (r <= a || b <= l) {return P(INF, INF); }

	if (a <= l && r <= b) return node[k];



	P vl = RMQ(a, b, 2 * k + 1, l, (l + r) / 2,node);

	P vr = RMQ(a, b, 2 * k + 2, (l + r) / 2, r, node);

	return min(vl, vr);

}



int main() {

	cin.tie(0); ios::sync_with_stdio(false);

	//Graph initialize

	int n_; cin >> n_;

	for (int i = 0; i < n_; i++) {

		int k; cin >> k;

		for (int j = 0; j < k; j++) {

			int c; cin >> c;

			T[i].emplace_back(c);

			T[c].emplace_back(i);

		}

	}

	//ET??¨?????????

	dfs(0,0);



	//RMQ initialize

	n_ = ET.size();



	int n = 1;

	while (n < n_) n *= 2;

	vector<P> node(2 * n - 1, P(INF, INF));



	for (int i = 0; i < n_;i++) { node[n - 1 + i] = ET[i]; }

	for (int i = n - 2; i >= 0; i--) { node[i] = min(node[2 * i + 1], node[2 * i + 2]); }



	//Answer

	int q; cin >> q;

	for (int i = 0; i < q; i++) {

		int u, v; cin >> u >> v;

		int a = Ind[u], b = Ind[v];

		if (a > b) { swap(a, b); }

		if (a == b) { cout << u << endl; continue; }

		cout << RMQ(a,b, 0, 0, n, node).second << endl;

	}

}