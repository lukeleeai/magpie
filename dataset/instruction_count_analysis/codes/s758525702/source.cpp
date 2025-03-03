#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cstdlib>

#include<cstring>

using namespace std;

int n,m;

const int maxn=5e4+1000;

const int maxv=600;

struct Edge

{

	int u,v,w,next;

	Edge(int _u=0,int _v=0,int _w=0,int _next=0)

	{

		u=_u,v=_v;w=_w;next=_next;

	}

}edge[maxn*2],tedge[maxn];

int head[maxv],ednum,idx[maxn];

void addedge(int u,int v,int w)

{

	edge[ednum]=Edge(u,v,w,head[u]);

	head[u]=ednum++;

	edge[ednum]=Edge(v,u,w,head[v]);

	head[v]=ednum++;

}

bool cmp(int a,int b)

{

	return tedge[a].w<tedge[b].w;

}

int dfn[maxv],low[maxv],idxn,stnum,sccnum,stk[maxv],scc[maxv];

bool inst[maxv];

void tarjan(int u,int pre)

{

	int i,v;

	dfn[u]=low[u]=++idxn;

	inst[u]=true;

	stk[stnum++]=u;

	for(i=head[u];i!=-1;i=edge[i].next)

	{

		v=edge[i].v;

		//cout <<u<<" "<<v<<" "<<i<<" "<<edge[i].next<<endl;getchar();

		if(v==pre)continue;

		if(!dfn[v])

		{

			tarjan(v,u);

			low[u]=min(low[u],low[v]);

		}

		else if(inst[v])low[u]=min(low[u],dfn[v]);

	}

	if(low[u]==dfn[u])

	{

		++sccnum;

		while(stk[stnum-1]!=u)

		{

			scc[stk[stnum-1]]=sccnum;

			inst[stk[stnum-1]]=false;

			stnum--;

		}

		scc[stk[stnum-1]]=sccnum;

		inst[stk[stnum-1]]=false;

		stnum--;

	}

}

bool isaim[maxn];

int main()

{

	int i,j,u,v,w;

	int num,ans;

	scanf("%d %d",&n,&m);

	for(i=0;i<m;i++)

	{

		idx[i]=i;

		scanf("%d %d %d",&u,&v,&w);

		tedge[i]=Edge(u,v,w);

	}

	num=ans=ednum=0;

	memset(head,-1,sizeof(head));

	memset(isaim,false,sizeof(isaim));

	sort(idx,idx+m,cmp);	

	for(i=0;i<m;i++)

	{

		if(i==0||tedge[idx[i]].w==tedge[idx[i-1]].w)

			addedge(tedge[idx[i]].u,tedge[idx[i]].v,tedge[idx[i]].w);

		else 

		{

			memset(dfn,0,sizeof(dfn));

			memset(scc,0,sizeof(scc));

			memset(inst,false,sizeof(inst));

			idxn=0;sccnum=0;

			for(j=1;j<=n;j++)

				if(!dfn[j])

				{

					stnum=0;

					tarjan(j,-1);

				}

			//cout <<i<<":";for(j=1;j<=n;j++)cout <<scc[j]<<" ";cout <<endl;

			for(j=0;j<i;j++)

				if(scc[tedge[idx[j]].u]!=scc[tedge[idx[j]].v])isaim[idx[j]]=true;

			addedge(tedge[idx[i]].u,tedge[idx[i]].v,tedge[idx[i]].w);

		}

	}

	memset(dfn,0,sizeof(dfn));

	memset(scc,0,sizeof(scc));

	memset(inst,false,sizeof(inst));

	idxn=0;sccnum=0;

	for(j=1;j<=n;j++)

		if(!dfn[j])

		{

			stnum=0;

			tarjan(j,-1);

		}

	//cout <<i<<":";for(j=1;j<=n;j++)cout <<scc[j]<<" ";cout <<endl;

	for(j=0;j<m;j++)

		if(scc[tedge[idx[j]].u]!=scc[tedge[idx[j]].v])isaim[idx[j]]=true;

	for(j=0;j<m;j++)

		if(isaim[j])num++,ans+=tedge[j].w;

	printf("%d %d\n",num,ans);

	return 0;

}