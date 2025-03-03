/*

Date: 3/9/2020

Context: ZR3月省选集训

if (sum[x] >= 2 * max[x]) {

	f[x] = sum[x] / 2;

}

else {

	int u = mp[x];

	sum[x] - max[x] + max(0 \leq k \leq f[u], 2 * k \leq 2 * max[u] - sum[u]);

}

*/

#include "stdc++.h"

#define int long long

using namespace std;

const int N = 2000 + 10;

char ch[N];

int mx[N], sum[N], f[N], ver[N * 2], head[N], nex[N * 2], tot, mp[N], ans;

int n, dist, cnt[N];

inline void add(int x, int y) {

	ver[++tot] = y;

	nex[tot] = head[x];

	head[x] = tot;

}

void dfs(int x, int fa) {

	

	for (int i = head[x]; i; i = nex[i]) {

		int y = ver[i];

		if (y == fa) continue;

		dfs(y, x);

		cnt[x] += cnt[y];

		sum[x] += sum[y] + cnt[y];

		if (sum[y] + cnt[y] > mx[x]) { 

			mp[x] = y;

			mx[x] = sum[y] + cnt[y];

		}

		/*

		mistake:

		if (sum[y] > mx[x]) {

			mp[x] = y;

			mx[x] = sum[y];

		}

		*/

	

	}

	if (ch[x] == '1') {

		cnt[x]++;

	}

	if (head[x] == 0) return;



	if (sum[x] - mx[x] >= mx[x]) {



		f[x] = sum[x] / 2;

	}

	else {

		int u = mp[x];

		f[x] = sum[x] - mx[x] + min(f[u], (2 * mx[x] - sum[x]) / 2);

	}

	// cout << "dfs::x " << x << endl;

}



inline void solve(int x) {

	memset(mx, 0, sizeof(mx));

	memset(sum, 0, sizeof(sum));

	memset(cnt, 0, sizeof(cnt));

	dist = 0;

	dfs(x, 0);



	if (sum[x] % 2) return;

	if (f[x] == sum[x] / 2) {

		ans = min(f[x], ans);

	}

}

signed main() {

	ans = 1e9 + 7;

	ios::sync_with_stdio(0);

	cin >> n;

	cin >> ch + 1;

	for (int i = 1, u, v; i <= n - 1; i++) {

		cin >> u >> v;

		add(u, v);

		add(v, u);

	}

	for (int i = 1; i <= n; i++) {

		solve(i);

	}

	if (ans == 1e9 + 7) {

		cout << -1 << endl;

	}

	else {

		cout << ans << endl;

	}

	return 0;

}


