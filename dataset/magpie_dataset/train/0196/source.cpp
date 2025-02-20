#include"stdc++.h"

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;



int d[100], a[100];

int id[1000000];

vector<int>re[5040];

int dp[100][5040];

int h(vector<int>&v) {

	int p = 1, res = 0;

	for (int i : v)res += p*i, p *= 7;

	return res;

}

int main() {

	int n; scanf("%d", &n);

	rep(i, n)scanf("%d", &d[i]);

	rep(i, n)scanf("%d", &a[i]);

	vector<int>v(7); iota(v.begin(), v.end(), 0);

	int p = 0;

	do {

		id[h(v)] = p; re[p] = v;

		int cnt = 0;

		bool t[7]{};

		for (int i : v) {

			rep(j, 7) {

				if (t[j] && abs(j - i) <= d[j])cnt += a[j];

			}

			t[i] = 1;

		}

		dp[0][p] = cnt;

		p++;

	} while (next_permutation(v.begin(), v.end()));

	int ans = 0;

	for (int i = 1; i + 6 < n; i++)rep(j, 5040)rep(k, 8) {

		auto t = re[j].begin();

		int cnt = 0, o = 0;

		bool p[8]{};

		vector<int>q(7);

		rep(l, 8) {

			if (k == l) {

				rep(y, 8) {

					if (p[y] && y + d[i - 1 + y] >= 7)

						cnt += a[i - 1 + y];

				}

				p[7] = 1; q[o++] = 6;

			}

			else {

				if (p[7] && 7 - d[i + 6] <= *t)cnt += a[i + 6];

				p[*t] = 1;

				if (*t)q[o++] = *t - 1;

				t++;

			}

		}

		int v = id[h(q)];

		dp[i][v] = max(dp[i][v], dp[i - 1][j] + cnt);

		ans = max(ans, dp[i][v]);

	}

	printf("%d\n", ans);

}