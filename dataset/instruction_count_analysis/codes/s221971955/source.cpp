#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<cmath>

#include<queue>

#include<vector>

#include<bitset>

using namespace std;

typedef long long ll;

#define N 200006

struct edge{int to,nxxt;}e[N];

int n,X,D,head[N],cnt=1,fa[N];

int v[N],id[N];

ll dp[N],w[N];

inline void ins(int u,int v){e[cnt].to=v;e[cnt].nxxt=head[u];head[u]=cnt++;}

void dfs(int te)

{v[te]=1;

	for(int i=head[te];i;i=e[i].nxxt)

	{

		int j=e[i].to;dfs(j);

		v[te]+=v[j];w[te]+=w[j];

	}

}

bool cmp(int x,int y){return 1ll*v[x]*w[y]>1ll*v[y]*w[x];}

int main()

{

	scanf("%d%d%d",&n,&X,&D);

	scanf("%lld",&w[1]);

	for(int i=2;i<=n;i++)

	{

		scanf("%lld%d",&w[i],&fa[i]);

		ins(fa[i],i);

	}dfs(1);

	for(int i=1;i<=n;i++)id[i]=i;sort(id+1,id+1+n,cmp);int tn=min(n,D),tm=n*n*n;

    for(int i=1;i<=tm;i++)dp[i]=1e18;

    for(int i=1;i<=n;i++)

    {

        int x=id[i],tt=tn;

        for(int j=0;(1<<j)<=tt;j++)

        {

            int tv=v[x]<<j;

            ll tw=w[x]<<j;

            for(int ii=tm;ii>=tv;ii--)dp[ii]=min(dp[ii],dp[ii-tv]+tw);

            tt-=1<<j;

        }

        if(tt)

        {

            int tv=v[x]*tt;

            ll tw=w[x]*tt;

            for(int ii=tm;ii>=tv;ii--)dp[ii]=min(dp[ii],dp[ii-tv]+tw);

        }

    }

    ll ans=0;

    for(int i=0;i<=tm;i++)if(dp[i]<=X)

    {

        ll sum=i,tv=dp[i];

        for(int j=1;j<=n;j++)

        {

            int x=id[j];

            if(x==1)

            {

                sum+=(X-tv)/w[x]*v[x];

                break;

            }

            int ct=min(1ll*D-tn,(X-tv)/w[x]);

            sum+=1ll*ct*v[x],tv+=1ll*ct*w[x];

        }

        ans=max(ans,sum);

    }

    printf("%lld\n",ans);

}
