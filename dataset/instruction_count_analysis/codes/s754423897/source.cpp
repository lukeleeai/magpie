#include"stdc++.h"

using namespace std;

const int maxn = 2e5 + 7;

int n;



int fir[maxn], nxt[2 * maxn], to[2 * maxn], e = 0;

void add(int x, int y) {

	to[++e] = y; nxt[e] = fir[x]; fir[x] = e;

	to[++e] = x; nxt[e] = fir[y]; fir[y] = e;

}



int dp[maxn];

int dfs(int pos, int f) {

	int y, z, rs = pos, d;

	for (y = fir[pos]; y; y = nxt[y]) {

		if((z = to[y]) == f) continue;

		dp[z] = dp[pos] + 1;

		d = dfs(z, pos);

		if(dp[d] > dp[rs]) rs = d;

	}

	return rs;

}



int main() {

	scanf("%d", &n);

	int x, y;

	for (int i = 1; i < n; ++i) {

		scanf("%d%d", &x, &y);

		add(x, y);

	}

	dp[1] = 0;

	x = dfs(1, 0);

	dp[x] = 0;

	y = dfs(x, 0);

	//printf("%d %d\n", x, y);

	if(dp[y] % 3 == 1) printf("Second\n");

	else printf("First\n");

	return 0;

}