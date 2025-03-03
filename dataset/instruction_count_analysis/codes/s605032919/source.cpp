#include"stdc++.h"

using namespace std;

#define ll long long

#define reg register

#define mo 1000000007

#define maxn 1000

inline ll read()

{

	reg ll x=0,w=0;reg char ch=getchar();

	while(!isdigit(ch))w|=ch=='-',ch=getchar();

	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();

	return w?-x:x;

}

inline int ksm(int x,int y)

{

	int a=1;

	while(y)

	{

		if(y&1)a=1ll*a*x%mo;

		x=1ll*x*x%mo;y>>=1;

	}return a;

}

inline void Min(int &x,int y){x=x>y?y:x;}

inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

int n,m,base,res,ans=1,rt;

int headd[maxn],nextt[maxn<<1],to[maxn<<1],cntt=1;

inline void link(int u,int v)

{nextt[++cntt]=headd[u];headd[u]=cntt;to[cntt]=v;}

vector<int>G[maxn];

int tot,cnt,bs[maxn],bel[maxn],low[maxn],dfn[maxn],top,zhan[maxn];

inline void Tarjan(int u)

{

	reg int i,v;

	if(rt==u&&headd[u]==0){G[++tot].push_back(u);return ;}

	zhan[++top]=u;low[u]=dfn[u]=++cnt;

	for(i=headd[u];i;i=nextt[i])

	{

		v=to[i];

		if(!dfn[v])

		{

			Tarjan(v);

			Min(low[u],low[v]);

			if(low[v]>=dfn[u])

			{

				++tot;G[tot].push_back(u);

				while(zhan[top]!=v)

					G[tot].push_back(zhan[top--]);

				--top;G[tot].push_back(v);

			}

		}

		else Min(low[u],dfn[v]);

	}

}

int vis[maxn];

inline int get(int x)

{

	int sz=G[x].size(),i,j,res=0;

	for(i=1;i<=n;++i)vis[i]=0;

	for(i=0;i<sz;++i)vis[G[x][i]]=1;

	for(i=0;i<sz;++i)

		for(j=headd[G[x][i]];j;j=nextt[j])

			if(vis[to[j]]==1)++res;

	return res/2;

}

int jc[maxn];

inline int C(int x,int y)

{

	if(x<y||x<0||y<0)return 0;

	return 1ll*jc[x]*ksm(1ll*jc[y]*jc[x-y]%mo,mo-2)%mo;

}

int main()

{

	n=read(),m=read(),base=read();

	reg int u,v,i,j;

	for(i=1;i<=m;++i)

	{

		u=read(),v=read();

		link(u,v);link(v,u);

	}jc[0]=1;

	for(i=1;i<=m+n+base;++i)jc[i]=1ll*i*jc[i-1]%mo;

	for(i=1;i<=n;++i)if(!dfn[i])rt=i,Tarjan(i);

	for(i=1;i<=tot;++i)bs[i]=get(i);

	for(i=1;i<=tot;++i)

	{

		if(bs[i]==G[i].size())

		{

			res=0;

			for(j=0;j<bs[i];++j)

				(res+=ksm(base,gcd(j,bs[i])))%=mo;

			res=1ll*res*ksm(bs[i],mo-2)%mo;

		}

		else if(bs[i]>G[i].size())res=C(bs[i]+base-1,base-1);

		else res=ksm(base,bs[i]);

		ans=1ll*ans*res%mo;

	}

	printf("%d\n",ans);

	return 0;

}