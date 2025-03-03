#include <iostream>

#include <cstdio>

#define ll long long

using namespace std;

inline int read()

{

	int x = 0, f = 1; char ch = getchar();

	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}

	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}

	return x * f;

}

const int N = 5100,mod = 1e9 + 7;

int n,tot,head[N],siz[N];

int f[N][N],g[N],res[N << 1];

struct node{int nex,to;} a[N << 1];

void add(int f,int t) {a[++ tot].nex = head[f]; a[tot].to = t; head[f] = tot;}

void dfs(int now,int fa)

{

	f[now][siz[now] = 1] = 1;

	for(int i = head[now],to;i;i = a[i].nex)

	{

		to = a[i].to; if(to == fa) continue;

		dfs(to,now);

		for(int j = 1;j <= siz[now] + siz[to];j ++) res[j] = 0;

		for(int j = 1;j <= siz[now];j ++) for(int k = 0;k <= siz[to];k ++) res[j + k] = (res[j + k] + 1ll * f[now][j] * f[to][k] % mod) % mod;

		siz[now] += siz[to]; for(int j = 1;j <= siz[now];j ++) f[now][j] = res[j];

	}

	for(int i = 2;i <= siz[now];i += 2) f[now][0] = (f[now][0] + mod - 1ll * f[now][i] * g[i] % mod) % mod;

}

int main()

{

	n = read(); for(int i = 1,x,y;i < n;i ++) {x = read(); y = read(); add(x,y); add(y,x);}

	g[0] = 1; for(int i = 2;i <= n;i += 2) g[i] = 1ll * g[i - 2] * (i - 1) % mod;

	dfs(1,0); cout << mod - f[1][0] << "\n";

	return 0;

}