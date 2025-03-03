#include <stdio.h>

#include <string.h>

#include <algorithm>

#define ME 200000

#define MN 1400000

#define INF 0x7f7f7f7f

int n,m,pl,ql,pc;

int lst[MN+5],pnt[MN+5];

int dis[MN+5]; bool usd[MN+5];

int hd[MN+5],to[MN+5],val[MN+5],nxt[MN+5],rn=0;

struct edge{int p,q,c;}e[ME+5];

bool cmp(edge a,edge b){return a.c<b.c;}

struct DEQUE{

	int mem[MN*2+5],hd,tl;

	DEQUE(){hd=MN,tl=MN+1;}

	int front(){return mem[hd];}

	bool empty(){return hd==tl-1;}

	void hdpush(int x){mem[++hd]=x;}

	void hdpop(){--hd;}

	void tlpush(int x){mem[--tl]=x;}

	void tlpop(){++tl;}

}q;

inline void add(int u,int v,int c){

	++rn;

	nxt[rn]=hd[u],hd[u]=rn;

	to[rn]=v,val[rn]=c;

}

int main(){

	memset(dis,0x7f,sizeof(dis));

	memset(hd,0xff,sizeof(hd));

	scanf("%d%d",&n,&m); pc=n;

	for(int i=1;i<=m;i++)

		scanf("%d%d%d",&e[i].p,&e[i].q,&e[i].c);

	std::sort(e+1,e+1+m,cmp);

	for(int i=1;i<=m;i++){

		if(lst[e[i].p]!=e[i].c){

			lst[e[i].p]=e[i].c,pnt[e[i].p]=(++pc);

			add(e[i].p,pnt[e[i].p],1),add(pnt[e[i].p],e[i].p,0);

		}

		if(lst[e[i].q]!=e[i].c){

			lst[e[i].q]=e[i].c,pnt[e[i].q]=(++pc);

			add(e[i].q,pnt[e[i].q],1),add(pnt[e[i].q],e[i].q,0);

		}

		add(pnt[e[i].p],pnt[e[i].q],0),add(pnt[e[i].q],pnt[e[i].p],0);

	}

	dis[1]=0; q.tlpush(1);

	for(int d=0;;d++){

		while(1){

			int u=q.front();

			if(usd[u]){q.hdpop();continue;}

			if(dis[u]!=d)break;

			q.hdpop(); usd[u]=true;

			for(int i=hd[u];i!=-1;i=nxt[i]){

				if(!usd[to[i]]){

					if(val[i]==0){

						if(dis[to[i]]>d){

							dis[to[i]]=d;

							q.hdpush(to[i]);

						}

					}else{

						if(dis[to[i]]>d+1){

							dis[to[i]]=d+1;

							q.tlpush(to[i]);

						}

					}

				}

			}

		}

		if(dis[n]!=INF||q.empty())break;

	}

	printf("%d",dis[n]==INF?-1:dis[n]);

}