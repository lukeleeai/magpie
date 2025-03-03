#include"stdc++.h"

using namespace std;

#define int long long

inline int read()

{

    int f=1,w=0;char x=0;

    while(x<'0'||x>'9') {if(x=='-') f=-1; x=getchar();}

    while(x!=EOF&&x>='0'&&x<='9') {w=(w<<3)+(w<<1)+(x^48);x=getchar();}

    return w*f;

}

const int N=200010;

const int INF=1e18;

int num_edge,n,Cnt;

int Cir[N],Vis[N],Val[N];

int head[N<<1],fa[N],Jud[N];

struct Edge{int next,to;} edge[N<<1];

inline void Add(int from,int to)

{

	edge[++num_edge].next=head[from];

	edge[num_edge].to=to;

	head[from]=num_edge;

}

inline void Dfs(int pos)

{

	for(int i=head[pos];i;i=edge[i].next)

		if(!Cir[edge[i].to]) Dfs(edge[i].to);

	for(int i=head[pos];i;i=edge[i].next)

		if(!Cir[edge[i].to]) Jud[Val[edge[i].to]]=1;

	for(;Jud[Val[pos]];Val[pos]++);

	for(int i=head[pos];i;i=edge[i].next)

		if(!Cir[edge[i].to]) Jud[Val[edge[i].to]]=0;

}

main(){

	int pos=1;n=read();

	for(int i=1;i<=n;i++) fa[i]=read(),Add(fa[i],i);

	for(;!Vis[pos];pos=fa[pos]) Vis[pos]=1;

	for(;!Cir[pos];pos=fa[pos]) Cir[pos]=1;

	int Max=-1,Min=INF;

	for(int i=1;i<=n;i++)

		if(Cir[i]) Cnt++,Dfs(i),Max=max(Max,Val[i]),Min=min(Min,Val[i]);

	if(Max==Min&&Cnt&1) puts("IMPOSSIBLE");

	else puts("POSSIBLE");

}
