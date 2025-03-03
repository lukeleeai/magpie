#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>



using namespace std;



int n,x,y,siz[200001],fa[200001],maxs[200001],maxp[200001],mins[200001],minp[200001],maxl[200001],minn;

long long ans;

vector<int> point[200001];

char str[200001];



void dfs1(int u,bool check){

	siz[u]=str[u]-'0';

	for(int v:point[u])if(v!=fa[u]){

		fa[v]=u;

		dfs1(v,true);

		siz[u]+=siz[v],maxs[u]=max(maxs[u],maxs[v]+1);

		if(mins[v]<0x7f7f7f7f)mins[u]=min(mins[u],maxs[v]+1);

	}

	if(point[u].size()==check)maxs[u]=0,mins[u]=str[u]-'0'?0:0x7f7f7f7f;else if(str[u]-'0')mins[u]=min(mins[u],maxs[u]);

}



void dfs2(int u,bool check){

	maxp[u]=max(maxp[u],check+maxp[fa[u]]);

	if(check)maxl[u]=max(maxl[u],maxp[u]-1);

	int mx=-1;for(int v:point[u])if(v!=fa[u])maxp[v]=max(maxp[v],mx+2),mx=max(mx,maxs[v]);

	mx=-1;for(int i=point[u].size()-1;~i;--i){int v=point[u][i];if(v!=fa[u])maxp[v]=max(maxp[v],mx+2),mx=max(mx,maxs[v]);}

	for(int v:point[u])if(v!=fa[u])dfs2(v,true);

}



int main(){

	memset(mins,0x7f,sizeof(mins)),memset(minp,0x7f,sizeof(minp));

	scanf("%d",&n);for(int i=1;i<n;++i)scanf("%d%d",&x,&y),point[x].push_back(y),point[y].push_back(x);scanf("%s",str+1);

	dfs1(1,false),dfs2(1,false);

	for(int i=1;i<=n;++i){

		if(str[i]-'0')minn=0;else minn=min(mins[i],siz[i]==siz[1]?2147483647:maxp[i]);

		int d=max(maxs[i],maxp[i])-1;for(int v:point[i])if(v!=fa[i])d=min(d,maxl[v]+1);else d=min(d,maxs[i]+1);

		if(d>=minn)ans+=d-minn+1;

	}

	printf("%lld",ans+1);

}