#include "stdc++.h"

using namespace std;



using pii = pair <int, int>;



#define N 300000



int n, m;

int dp[N], val[N], w[N];



int D, Q;



vector <pii> can[N];



void query(int &ans, int v, int L, int cur) {

	if (v <= m) {

		ans = max(ans, cur + (--lower_bound(can[v].begin(), can[v].end(), pii(L + 1, 0))) -> second);

		return;

	}

	query(ans, v >> 1, L, cur);

	if (L >= w[v]) query(ans, v >> 1, L - w[v], cur + val[v]);

	return;

}



int main() {

	D = 10;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d %d", &val[i], &w[i]);

	dp[1] = 0;

	for (int i = 2; i <= n; i ++) dp[i] = dp[i>>1] + 1;

	m = min(n, (1<<D) - 1);

	can[0] = {{0, 0}};

	for (int i = 1; i <= m; i ++) {

		auto &res = can[i];

		auto &from = can[i>>1];

		vector <pii> tmp;

		tmp = from;

		for (auto x : from) {

			tmp.emplace_back(x.first + w[i], x.second + val[i]);

		}

		sort(tmp.begin(), tmp.end());

		for (auto x : tmp) {

			if (!res.empty() && res.back().second >= x.second) continue;

			res.push_back(x);

		}

	}

	scanf("%d", &Q);

	while (Q --) {

		int v, L, ans = 0;

		scanf("%d %d", &v, &L);

		query(ans, v, L, 0);

		printf("%d\n", ans);

	}

	return 0;

}
