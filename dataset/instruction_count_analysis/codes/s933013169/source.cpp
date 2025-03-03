#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 15

#define MAXS 50000

#define MO 1000000007

using namespace std;

int n,m,all;

int cnt[MAXN+5][MAXS+5],p[MAXN+5][MAXS+5];

int dp[MAXS+5];

bool legal[MAXS+5];

int PowMod(int a,int b)

{

	int ret=1;

	while(b)

	{

		if(b&1)

			ret=1LL*ret*a%MO;

		a=1LL*a*a%MO;

		b>>=1;

	}

	return ret;

}

int LowBit(int i)

{

	return i&(-i);

}

int main()

{

	scanf("%d %d",&n,&m);

	all=1<<n;

	int  u,v;

	for(int i=1;i<=m;i++)

	{

		scanf("%d %d",&u,&v);

		cnt[u][1<<(v-1)]=1;

	}

	for(int i=1;i<=n;i++)

		for(int s=1;s<all;s++)

		{

			int k=LowBit(s);

			cnt[i][s]=cnt[i][s-k]+cnt[i][k];

			p[i][s]=(1<<cnt[i][s])-1;

		}

	for(int s=0;s<all;s++)

		if((s&1)==((s&2)/2))

			legal[s]=true;

	dp[0]=1;

	for(int s=1;s<all;s++)

		if(legal[s])

		{

			dp[s]=1;

			for(int t=((s-1)&s);t;t=((t-1)&s))

				if(legal[t])

				{

					int res=s-t,add=dp[res];

					for(int i=0;i<n;i++)

						if((1<<i)&res)

							add=1LL*add*p[i+1][t]%MO;

						else if((1<<i)&t)

							add=1LL*add*(1LL<<cnt[i+1][res])%MO;

					dp[s]=(1LL*dp[s]+1LL*add)%MO;

				}

		}

	int ans=PowMod(2,m);

	ans=((1LL*ans-1LL*dp[all-1])+MO)%MO;

	printf("%d\n",ans);

	return 0;

}