#include <cstdio>

#include <iostream>

#include <vector>

#include <algorithm>

#include <cstring>



using namespace std;



const int MAXN = 100010;

typedef long long ll;



int n, m;



inline int add(int x, int y){return (x+=y)>=m?x-m:x;}

inline int mul(int x, int y){return 1ll*x*y%m;}



struct edge{

	int next, to;

	edge(int N=0,int T=0):next(N),to(T){}

}e[MAXN<<1];

int fir[MAXN], num = 0;

inline void join(int a, int b)

{

	e[++num].next = fir[a];

	fir[a] = num;

	e[num].to = b;

}



int f[MAXN], g[MAXN], ans[MAXN], pre[MAXN], suf[MAXN], t[MAXN];

vector<int> in[MAXN];



void dfs1(int u, int fa)

{

	int cnt = 0;

	f[u]    = 1;

	in[u].push_back(1);

	for(int i=fir[u]; i; i=e[i].next)

	{

		int v = e[i].to;

		if(v == fa) continue;

		dfs1(v, u);

		f[u] = mul(f[u], add(f[v], 1));

		cnt++;

		in[u].push_back(v);

	}

	pre[0] = suf[cnt+1] = 1;

	for(int i=1; i<=cnt; i++)

		pre[i] = mul(pre[i-1], add(f[in[u][i]], 1));

	for(int i=cnt; i>=1; i--)

		suf[i] = mul(suf[i+1], add(f[in[u][i]], 1));

	for(int i=1; i<=cnt; i++)

		t[in[u][i]] = mul(pre[i-1], suf[i+1]);

}

void dfs2(int u, int fa)

{

	int cnt = 0;

	for(int i=fir[u]; i; i=e[i].next)

	{

		int v = e[i].to;

		if(v == fa)continue;

		++cnt;

		g[v] = add(mul(g[u], t[v]), 1);

		ans[v] = mul(g[v], f[v]);

		dfs2(v, u);

	}

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1,a,b;i<n;i++)

		scanf("%d%d",&a,&b), join(a, b), join(b, a);

	dfs1(1, 0);

	g[1] = 1; ans[1] = f[1];

	dfs2(1, 0);

	for(int i=1;i<=n;i++)

		printf("%d\n" ,ans[i]);

	return 0;

}