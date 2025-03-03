#include<cstdio>

#include<algorithm>

#include<cstring>

#include<vector>

#define MN 200005

using namespace std;

const int mod=1e9+7;

int n,x,y,cc,tt,tot,ttmp[MN],head[MN],sum[MN],inv[MN],c[MN],w[MN],num[MN];

bool vis[MN];

struct edge{int to,next;}g[MN<<4];

void ins(int u,int v){g[++cc].next=head[u];head[u]=cc;g[cc].to=v;}

void insw(int u,int v){ins(u,v);ins(v,u);}

vector<pair<int,int> >now[MN],minx;

void dfs(int u){

	++tt,ttmp[++tot]=c[u],++num[c[u]];vis[u]=1;

	for(int i=head[u];i;i=g[i].next)if(!vis[g[i].to])dfs(g[i].to);

}

int main(){

	scanf("%d%d%d",&n,&x,&y);

	sum[0]=sum[1]=inv[0]=inv[1]=1;

	for(int i=2;i<=n;i++)sum[i]=1ll*sum[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;

	for(int i=2;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[i]%mod;

	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]),now[c[i]].push_back(make_pair(w[i],i));

	for(int i=1;i<=n;i++)if(now[i].size()){

		sort(now[i].begin(),now[i].end());minx.push_back(now[i][0]);

		for(int j=1;j<now[i].size();j++)if(now[i][j].first+now[i][0].first<=x)insw(now[i][j].second,now[i][0].second);

	}sort(minx.begin(),minx.end());

	if(minx.size()){

		int tmp=minx[0].second;

		for(int i=1;i<=n;i++)if(c[i]!=c[tmp]&&w[i]+w[tmp]<=y)insw(tmp,i);

	}

	if(minx.size()>1){

		int tmp=minx[1].second,nowmin=c[minx[0].second];

		for(int i=0;i<now[nowmin].size();i++)if(w[tmp]+now[nowmin][i].first<=y)insw(now[nowmin][i].second,tmp);

	}

	dfs(minx[0].second);long long ans=sum[tt];

	for(int i=1;i<=tot;i++)ans=ans*inv[num[ttmp[i]]]%mod,num[ttmp[i]]=0;printf("%lld\n",ans);

}