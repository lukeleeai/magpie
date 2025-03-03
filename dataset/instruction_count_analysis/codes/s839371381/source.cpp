#include "stdc++.h"

 

using namespace std;



int n, m, z[100005], par[100005], tb, tc;

long long x[100005], y[100005], ta;

vector< int > v[100005];



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

		ta = y[tb];

		for (int j: v[tb])

			if (par[j] && (j = find(j)) != tb) {

				par[j] = tb;

				x[tb] += x[j];

				y[tb] = min(y[tb], max(y[j], ta) - x[j]);

			}

		y[tb] += x[tb];

	}

	printf("%lld\n", y[z[n]]);

	return 0;

}
