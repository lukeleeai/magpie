#include<map>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define N 100005

#define inf (1ll<<60)

#define rep(i,j,k) for (ll i=j;i<=k;++i)

#define per(i,j,k) for (ll i=j;i>=k;--i)

using namespace std;

inline ll read(){

	char ch=getchar(); ll x=0,f=1;

	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }

	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

	return x*f;

}

ll n,m,ans,tot,num,dfn[N],low[N],head[N];

struct edge{ ll to,next; }e[N<<1];

void add(ll u,ll v){

	e[++tot]=(edge){v,head[u]}; head[u]=tot;

}

void tarjan(ll u,ll last){

	dfn[u]=low[u]=++num;

	for (ll i=head[u],v=e[i].to;i;i=e[i].next,v=e[i].to){

		if (v==last) continue;

		if (dfn[v]) low[u]=min(low[u],dfn[v]);

		else{

			tarjan(v,u),low[u]=min(low[u],low[v]);

			if (low[v]==dfn[v]) ++ans;

		}

	}

}

int main(){

	n=read(); m=read();

	rep(i,1,m){

		ll u=read(),v=read();

		add(u,v); add(v,u);

	}

	rep(i,1,n) if (!dfn[i]) tarjan(i,-1);

	printf("%lld",ans);

}