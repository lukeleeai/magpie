#include <cstdio>

#include <algorithm>

#define int long long

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 5;

int n;

int head[MAXN] , to[MAXN << 1] , nxt[MAXN << 1] , cnt , ans , du[MAXN << 1];

LL f[MAXN] , a[MAXN];

void add(int u , int v) {nxt[++cnt] = head[u];head[u] = cnt;to[cnt] = v;}

void dfs(int x , int fa) {

	LL _sum = 0 , mx = 0;

	for (int i = head[x]; i; i = nxt[i]) {

		if(to[i] == fa) continue;

		dfs(to[i] , x);

		if(ans) return;

		mx = max(mx , f[to[i]]);

		_sum += f[to[i]];

	}

	if(!_sum) {

		f[x] = a[x];

		return;

	}

	f[x] = 2ll * a[x] - _sum;

	if(f[x] < 0 || f[x] > a[x] || mx - f[x] > _sum - mx || a[x] < mx) {

		printf("NO");

		exit(0);

	}

}

signed main() {

	scanf("%lld" , &n);

	for (int i = 1; i <= n; ++i) scanf("%lld" , &a[i]);

	if (n == 2) return puts(a[1] == a[2] ? "YES" : "NO"), 0;

	int root = 0;

	for (int i = 1; i < n; ++i) {

		int u , v;

		scanf("%lld %lld" , &u , &v);

		du[u] ++;du[v] ++;

		add(u , v);add(v , u);

		if(du[u] > 1) root = u;

		if(du[v] > 1) root = v;

	}

	dfs(root , 0);

	if(f[root]) printf("NO");

	else printf("YES");

	return 0;

}