#pragma GCC optimize("O1")

#pragma GCC optimize("O2")

#pragma GCC optimize("O3")

#include<cstdio>

#define LL long long

#define N 310

int n;

LL g[N][N];

signed main()

{

	scanf("%d",&n);LL ans(0);

	for(register int i(1);i<=n;i++)

		for(register int j(1);j<=n;j++)

			scanf("%lld",&g[i][j]);

	for(register int i(1);i<=n;i++)

		for(register int j(1);j<=i;j++)

		{

			bool f(1);

			for(register int k(1);k<=n;k++)

				if(g[i][j]>g[i][k]+g[k][j])

					return puts("-1"),0;

				else if(i-k&&j-k&&g[i][j]==g[i][k]+g[k][j])

					f=0;

			ans+=g[i][j]*f;

		}

	return printf("%lld\n",ans),0;

}