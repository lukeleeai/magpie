//test https://blog.csdn.net/rising_shit/article/details/80739593

#include<iostream>

#include<stdio.h>

#include<string.h>

#include<algorithm>

#define maxn 2005

#define _x1 x1

#define _x2 x2

using namespace std;

typedef long long ll;

const ll mod=1e9+7;

int n,m;

ll v;

int fa[maxn],id[maxn],x[maxn],y[maxn];

ll w[maxn];

int getfa(int now)

{

	return fa[now]==now ? now : fa[now]=getfa(fa[now]);

}

int cmp(int i,int j)

{

	return w[i]<w[j];

}

ll kruskal(int now)

{

	for(int i=1;i<=n;i++) fa[i]=i;

	ll ans=0;

	if(now)

		fa[x[now]]=y[now],ans+=w[now];

	for(int i=1;i<=m;i++)

	{

		int pos=id[i];

		int x1=getfa(x[pos]),y1=getfa(y[pos]);

		if(x1!=y1)

		{

			ans+=w[pos];

			fa[x1]=y1;

		}

	}

	return ans;

}

ll quickpow(ll p,ll k)

{

	ll ans=1;

	while(k)

	{

		if(k&1)

			ans=(ans*p)%mod;

		p=(p*p)%mod;

		k>>=1;

	}

	return ans;

}

int main()

{

	scanf("%d%d%lld",&n,&m,&v);

	for(int i=1;i<=m;i++)

		scanf("%d%d%lld",&x[i],&y[i],&w[i]),id[i]=i;

	sort(id+1,id+1+m,cmp);

 

	ll temp=kruskal(0);

 

	if(temp>v)

	return printf("0\n"),0;

 

	if(temp==v)

	{

		int cnt1=0,cnt2=0;

		for(int i=1;i<=m;i++)

		{

			if(kruskal(i)==temp)

				cnt1++;

			else

				cnt2++;

		}

		ll res1=(quickpow(2,cnt1)-2+mod)%mod;

		ll res2=quickpow(2,cnt2)%mod;

		return printf("%lld\n",res1*res2%mod),0;

	}

	else

	{

		int cnt1=0,cnt2=0;

		for(int i=1;i<=m;i++)

		{

			ll res1=kruskal(i);

			if(res1==v)

				cnt1++;

			else if(res1>v)

				cnt2++;

		}

		ll res1=2ll*((quickpow(2,cnt1)-1+mod)%mod)%mod;

		ll res2=quickpow(2,cnt2);

		printf("%lld\n",res1*res2%mod);

	}

}
