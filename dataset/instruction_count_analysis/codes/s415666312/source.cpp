#include"stdc++.h"

#define reg register

typedef long long ll;

using namespace std;

const int mod=1e9+7;

const int MN=1e5+5;

const ll inf=0x3f3f3f3f3f3f3f3f;

int to[MN<<2],nxt[MN<<2],c[MN<<2],h[MN],cnt;

inline void ins(int s,int t,int w){

	to[++cnt]=t;nxt[cnt]=h[s];c[cnt]=w;h[s]=cnt;

	to[++cnt]=s;nxt[cnt]=h[t];c[cnt]=w;h[t]=cnt;

}

ll disS[MN],disT[MN];

int gS[MN],gT[MN];

typedef pair<ll,int>pli;

priority_queue<pli,vector<pli>,greater<pli> >q;

bool vis[MN];

int n,m,S,T,x[MN<<1],y[MN<<1],W[MN<<1];

inline void Dij(ll* dis,int* g,int s){

	memset(dis,0x3f,sizeof(ll)*(n+1));

	memset(vis,0,sizeof(vis));

	dis[s]=0;g[s]=1;q.push(make_pair(0,s));

	while(!q.empty()){

		static pli v;v=q.top();q.pop();

		if(vis[v.second])continue;vis[v.second]=true;

		for(reg int st,i=h[st=v.second];i;i=nxt[i])

			if(dis[to[i]]>dis[st]+c[i])

				dis[to[i]]=dis[st]+c[i],

				q.push(make_pair(dis[to[i]],to[i])),

				g[to[i]]=g[st];

			else if(dis[to[i]]==dis[st]+c[i])g[to[i]]=(g[to[i]]+g[st])%mod;

	}

}

int main(){

	scanf("%d%d%d%d",&n,&m,&S,&T);

	for(reg int i=1,s,t,w;i<=m;i++)

		scanf("%d%d%d",&s,&t,&w),ins(s,t,w),x[i]=s,y[i]=t,W[i]=w;

	Dij(disS,gS,S);Dij(disT,gT,T);

	reg int ans=1ll*gS[T]*gS[T]%mod;

	for(reg int i=1;i<=n;i++)

		if(disS[i]+disT[i]==disS[T]&&disS[i]==disT[i])

			ans=(ans-1ll*gS[i]*gS[i]%mod*gT[i]%mod*gT[i]%mod+mod)%mod;

	for(reg int i=1;i<=m;i++){

		if(disS[x[i]]>=disS[y[i]])swap(x[i],y[i]);

		if(disS[x[i]]+W[i]!=disS[y[i]])continue;

		if(disT[y[i]]+W[i]!=disT[x[i]])continue;

		if(disS[x[i]]+W[i]+disT[y[i]]!=disS[T])continue;

		if(disS[x[i]]+W[i]<=disT[y[i]])continue;

		if(disT[y[i]]+W[i]<=disS[x[i]])continue;

		ans=(ans-1ll*gS[x[i]]*gS[x[i]]%mod*gT[y[i]]%mod*gT[y[i]]%mod+mod)%mod;

	}printf("%d\n",ans);

	return 0;

}