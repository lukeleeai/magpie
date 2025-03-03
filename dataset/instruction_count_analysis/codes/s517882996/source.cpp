#include"stdc++.h"

#define mod (1000000007)

using namespace std;



int n;

int num,fst[200010],lst[400010],to[400010];

int fa[200010],son[200010];

long long fac[200010],inv[200010],ans[200010];



long long ksm(long long a,long long b)

{

	long long res=1,sum=a;

	while(b)

	{

		if(b&1) (res*=sum)%=mod;

		(sum*=sum)%=mod;

		b>>=1;

	}

	return res;

}



inline void insert(int u,int v)

{

	lst[++num]=fst[u];to[num]=v;fst[u]=num;

	lst[++num]=fst[v];to[num]=u;fst[v]=num;

}



void dfs(int x)

{

	son[x]=1;

	for(int i=fst[x];i;i=lst[i]) if(fa[x]!=to[i])

	{

		fa[to[i]]=x;

		dfs(to[i]);

		son[x]+=son[to[i]];

	}

}



void work(int x)

{

	int cnt=0;

	ans[x]=1;

	for(int i=fst[x];i;i=lst[i]) if(fa[x]!=to[i])

	{

		work(to[i]);

		ans[x]=ans[x]*ans[to[i]]%mod*fac[son[x]-cnt-1]%mod*inv[son[to[i]]]%mod*inv[son[x]-cnt-1-son[to[i]]]%mod;

		cnt+=son[to[i]];

	}

}



void dfs2(int x,long long d)

{

	if(x!=1) ans[x]=ans[x]*fac[n-1]%mod*inv[n-son[x]]%mod*inv[son[x]-1]%mod*d%mod;

	long long re;

	for(int i=fst[x];i;i=lst[i]) if(fa[x]!=to[i])

	{

		re=ans[x]*ksm(ans[to[i]],mod-2)%mod*fac[son[to[i]]]%mod*fac[n-1-son[to[i]]]%mod*inv[n-1]%mod;

		dfs2(to[i],re);

	}

}



int main()

{

	int u,v;

	scanf("%d",&n);

	fac[0]=inv[0]=1;

	for(int i=1;i<=n;i++)

	{

		fac[i]=fac[i-1]*i%mod;

		inv[i]=ksm(fac[i],mod-2);

	}

	for(int i=1;i<n;i++)

	{

		scanf("%d%d",&u,&v);

		insert(u,v);

	}

	dfs(1);

	work(1);

	dfs2(1,0);

	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);

	return 0;

}