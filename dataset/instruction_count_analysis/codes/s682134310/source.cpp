#include<iostream>

#include<cstdio>

#include<vector>

using namespace std;

int n,tot;

const int N=200010;

int head[N],to[N<<1],nt[N<<1],ans[N],mx[N],fa[N],son[N],sf[N],sub[N];

vector<int>v[N];

void add(int f,int t)

{

	to[++tot]=t;nt[tot]=head[f];head[f]=tot;

}

namespace DSU

{

	int fa[N],siz[N];

	void YYCH(){for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;}

	int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

	void he(int x,int y)

	{	

		x=find(x);y=find(y);if(x==y)return;

		fa[x]=y;siz[y]+=siz[x];

	}

}

void dfs1(int x,int fa)

{

	::fa[x]=fa;mx[x]=max(mx[fa],fa);sf[x]=son[mx[x]];

	for(int i=head[x];i;i=nt[i])

		if(to[i]!=fa)son[x]=to[i],dfs1(to[i],x);

}

void dfs2(int x,int fa)

{

	if(fa)ans[x]+=ans[mx[x]]-sub[son[mx[x]]]+1;

	for(int i=head[x];i;i=nt[i])

		if(to[i]!=fa)son[x]=to[i],dfs2(to[i],x);

}

int main()

{

	cin>>n;DSU::YYCH();

	for(int i=1,x,y;i<n;++i)

		scanf("%d%d",&x,&y),add(x,y),add(y,x);

	dfs1(1,0);

	for(int i=2;i<=n;++i)v[mx[i]].push_back(i);

	

	for(int i=1;i<=n;++i)

	{

		for(int j=0,siz=v[i].size();j<siz;++j)

		{

			int x=v[i][j];

			if(x<i)ans[x]=DSU::siz[DSU::find(x)]-1;

			else

			{

				if(x!=sf[x])ans[x]+=DSU::siz[DSU::find(sf[x])];

				for(int k=head[x];k;k=nt[k])

					if(to[k]!=fa[x]&&to[k]<i)

					{

						sub[to[k]]=DSU::siz[DSU::find(to[k])];

						ans[x]+=sub[to[k]];

					}

			}

		}

		for(int j=head[i];j;j=nt[j])

			if(to[j]<i)DSU::he(i,to[j]);

	}

	dfs2(1,0);

	for(int i=2;i<=n;++i)printf("%d ",ans[i]);

	return 0;

}