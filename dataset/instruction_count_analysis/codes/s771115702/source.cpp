#include <cstdio>

#include <iostream>



using namespace std;



const int MAXN = 100010;



int n, m;



struct edge{

	int ne, to;

}e[MAXN];

int fir[MAXN], num = 0, d[MAXN];

inline void join(int a, int b)

{

	e[++num].ne = fir[a];

	fir[a] = num;

	e[num].to = b;

}



int f[MAXN];

int q[MAXN], h = 1, t = 0;



inline void topo()

{

	for(int i=1;i<=n;i++)

		if(!d[i]) q[++t] = i;

	while(h <= t)

	{

		int u = q[h++];

		for(int i=fir[u];i;i=e[i].ne)

		{

			int v = e[i].to;

			f[v] = max(f[v], f[u]+1);

			--d[v];

			if(!d[v]) q[++t] = v;

		}

	}

}



int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1,a,b;i<=m;i++)

		scanf("%d%d",&a,&b),join(a, b),d[b]++;

	topo();

	int ans = -1;

	for(int i=1;i<=n;i++)

		ans = max(ans, f[i]);

	printf("%d\n",ans);

	return 0;

}