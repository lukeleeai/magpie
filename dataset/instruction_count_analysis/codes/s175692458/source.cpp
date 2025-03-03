#include<algorithm> 

#include<cstdio>

#include<iostream>

#define inver(a) power(a,mod-2)

using namespace std;

typedef long long LL;

const int mod=1e9+7;

int fac[2050];

int fac_inv[2050];

int add(int x)

{

	return x>=mod?x-mod:x; 

}

LL power(LL x,LL y)

{

	LL re=1;

	while(y)

	{

		if(y&1) re=re*x%mod;

		x=x*x%mod;

		y>>=1;

	}

	return re;

}

LL C(int x,int y)

{

	return (LL)fac[x]*fac_inv[y]%mod*fac_inv[x-y]%mod;

}

int n,m;

int p2[2050];

bool mark[2050];

LL X;

LL v[2050];

namespace us

{

	int fa[1050];

	void init()

	{

		for(int i=1;i<=n;++i)

		{

			fa[i]=i;

		}

	}

	int find(int a)

	{

		return fa[a]==a?a:fa[a]=find(fa[a]); 

	}

	bool merge(int a,int b)

	{

		a=find(a);

		b=find(b);

		if(a==b)

		{

			return false;

		}

		fa[a]=b;

		return true;

	}

}

struct edge

{

	int u,v,w;

	bool operator <(const edge &other) const

	{

		return w<other.w;

	}

} e[2050];

LL kruskal(int ban)

{

	LL MST=0;

	us::init();

	if(ban)

	{

		us::merge(e[ban].u,e[ban].v);

		MST+=e[ban].w;

	}

	for(int i=1;i<=m;++i)if(i!=ban)

	{

		if(us::merge(e[i].u,e[i].v))

		{

			MST+=e[i].w;

			if(ban==0)

			{

				mark[i]=1;

			}

		}

	}

	return MST;

}

void init(int n)

{

	p2[0]=1;

	for(int i=1;i<=n;++i)

	{

		p2[i]=add(p2[i-1]<<1);

	}

	fac[0]=1;

	for(int i=1;i<=n;++i)

	{

		fac[i]=(LL)fac[i-1]*i%mod;

	}

	fac_inv[n]=inver(fac[n]);

	for(int i=n;i>=1;--i)

	{

		fac_inv[i-1]=(LL)fac_inv[i]*i%mod;

	} 

}

int calc()

{

	int p=n-1;

	int re=0;

	for(int i=1;i<p;++i)

	{

		re=add(re+C(p,i));

	}

	re=(LL)re*p2[m-p]%mod;

	return re;

}

int solve()

{

	init(m);

	for(int i=0;i<=m;++i)

	{

		v[i]=kruskal(i);

	}

	int an=0;

	if(v[0]==X)

	{

		an=calc();

	}

	for(int i=1;i<=m;++i) if(!mark[i])

	{

		if(v[i]==X)

		{

			int t=1;

			for(int j=1;j<=m;++j) if(!mark[j])

			{

				if(v[j]>v[i]||(v[j]==v[i]&&j>i))

				{

					++t;

				}

			}

			an=add(an+p2[t]);

		}

	}

	return an;

}

int main()

{

	scanf("%d%d",&n,&m);

	scanf("%lld",&X);

	for(int i=1;i<=m;++i)

	{

		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

	}

	sort(e+1,e+m+1);

	printf("%d\n",solve());

	return 0;

}