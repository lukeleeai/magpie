#include "stdc++.h"

 

using namespace std;



int n, m, z[100005], par[100005], tb, tc;

long long x[100005], y[100005], sum[100005], dp[100005], ta;

vector< int > v[100005], vv[100005];



int find(int a) {

	return par[a] == a ? a : par[a] = find(par[a]);

}



int main() {

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {

		scanf("%lld%lld", &ta, x + i);

		y[i] = max(ta - x[i], 0LL);

		z[i] = i;

	}

	sort(z + 1, z + n + 1, [](const int &a, const int &b) {return y[a] < y[b];});

	while (m--) {

		scanf("%d%d", &tb, &tc);

		v[tb].push_back(tc);

		v[tc].push_back(tb);

	}

	for (int i = 1; i <= n; i++) {

		tb = z[i];

		par[tb] = tb;

		sum[tb] = x[tb];

		dp[tb] = y[tb];

		for (int j: v[tb])

			if (par[j] && (j = find(j)) != tb) {

				vv[tb].push_back(j);

				par[j] = tb;

				sum[tb] += sum[j];

				dp[tb] = min(dp[tb], max(dp[j], y[tb]) - sum[j]);

			}

		dp[tb] += sum[tb];

	}

	printf("%lld\n", dp[z[n]]);

	return 0;

}
