#include <iostream>

#include <vector>

#include <limits.h>

#include <algorithm>

#include <string>

#include <math.h>

#include <limits.h>

#include <queue>

#include <map>

#include <set>

#include <iomanip>

#include <bitset>

#include <cassert>

#include <random>

#include <functional>

#include <stack>

#include <iomanip>

using namespace std;

int MOD = 1e9 + 7;



int N;

typedef pair<int, int> pii;   //自分、親

vector<vector<int>> G;   //グラフ

vector<pii> order;



void setorder() {

	vector<bool> check;

	check.resize(N, false);   //来た->true

	queue<pii> st;

	st.push(pii(0,-1));

	while (!st.empty()) {

		pii cur = st.front();

		st.pop();

		check[cur.first] = true;

		order.push_back(cur);

		for (int next : G[cur.first]) {

			if (check[next])continue;

			st.push(pii(next, cur.first));

		}

	}

}



int main() {

	cin >> N;

	G.resize(N);

	for (int n = 0; n < N - 1; n++) {

		int u, v;

		cin >> u >> v;

		G[--u].push_back(--v);

		G[v].push_back(u);

	}

	setorder();

	vector<long long> DP[2];

	DP[0].resize(N, 1);

	DP[1].resize(N, 1);

	for (int ord = N - 1; ord >= 0; ord--) {

		pii cur = order[ord];

		//葉っぱの場合

		if (G[cur.first].size() == 1 && G[cur.first][0] == cur.second) {

			DP[0][cur.first] = 1;

			DP[1][cur.first] = 1;

		}

		if (cur.second == -1)continue;

		DP[0][cur.second] *= (DP[0][cur.first]+DP[1][cur.first]);

		DP[1][cur.second] *= (DP[0][cur.first]);

		DP[0][cur.second] %= MOD;

		DP[1][cur.second] %= MOD;

	}

	cout << (DP[0][0] + DP[1][0]) % MOD << endl;

	return 0;

}