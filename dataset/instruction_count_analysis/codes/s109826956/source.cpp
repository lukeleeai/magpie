#include<iostream>

#include<cstdio>

using namespace std;



int d1[200005],d2[200005];

int d3[200005],d4[200005];

int n,x,y,siz[200005],col[200005],fa[200005];

long long ans=0;

int tot=0,h[200005];

struct Edge{

	int x,next;

}e[400005];

char ch[200005];



inline void add_edge(int x,int y){

	e[++tot].x=y;

	e[tot].next=h[x],h[x]=tot;

}



void dfs1(int x,int father){

	siz[x]=col[x],fa[x]=father;

	d3[x]=col[x]?0:1e9;

	for(int i=h[x];i;i=e[i].next){

		if(e[i].x==father)continue;

		dfs1(e[i].x,x);

		siz[x]+=siz[e[i].x];

		d1[x]=max(d1[x],d1[e[i].x]+1);

		if(siz[e[i].x])

			d3[x]=min(d3[x],d1[e[i].x]+1);

	}

}



void dfs2(int x,int father){

	if(father)d4[x]=d2[x]-1;

	int maxn=0,sec=0;

	for(int i=h[x];i;i=e[i].next){

		if(e[i].x==father)continue;

		if(d1[e[i].x]+1>maxn)

			sec=maxn,maxn=d1[e[i].x]+1;

		else sec=max(sec,d1[e[i].x]+1);

	}

	for(int i=h[x];i;i=e[i].next){

		if(e[i].x==father)continue;

		if(d1[e[i].x]+1==maxn)

			d2[e[i].x]=max(d2[x],sec)+1;

		else d2[e[i].x]=max(d2[x],maxn)+1;

		dfs2(e[i].x,x);

	}

}



int main(){

	scanf("%d",&n);

	for(int i=1;i<n;i++){

		scanf("%d%d",&x,&y);

		add_edge(x,y);

		add_edge(y,x);

	}

	scanf("%s",ch+1);

	for(int i=1;ch[i];i++)

		col[i]=ch[i]-'0';

	dfs1(1,0),dfs2(1,0);

	for(int i=1;i<=n;i++){

		int minv,maxv;

		minv=min(d3[i],siz[1]==siz[i]?(int)1e9:d2[i]);

		maxv=max(d1[i],d2[i])-1;

		for(int j=h[i];j;j=e[j].next){

			if(e[j].x==fa[i])maxv=min(maxv,d1[i]+1);

			else maxv=min(maxv,d4[e[j].x]+1);

		}

		if(maxv>=minv)ans+=1LL*maxv-minv+1;

	}

	printf("%lld",ans+1);

}