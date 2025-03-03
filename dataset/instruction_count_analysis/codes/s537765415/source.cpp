#include "stdc++.h"

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<=(b);++i)

#define ROF(i,a,b) for (int i=(a);i>=(b);--i)

typedef long long ll;

inline int read() {

	int x=0,s=1; char ch=getchar();

	while (ch<'0'||ch>'9') { if (ch=='-') s=-1; ch=getchar(); }

	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

	return s*x;

}



const int MAXN=1000005,MAXM=4000006,INF=2147483647;

int en,u[MAXN],cur[MAXN];//cur为当前弧优化

struct edge{ int v,nt,c; }e[MAXM];

inline void clear(){ en=0; memset(u,-1,sizeof(u)); }

inline void addEdge(int x,int y,int z){//反向边为i^1

	e[en]=(edge){y,u[x],z}; u[x]=en++;

	e[en]=(edge){x,u[y],0}; u[y]=en++;

}

int S,T,nn,rear,head,Q[MAXN],dis[MAXN];

int BFS(){

	FOR(i,1,nn) dis[i]=INF;

	rear=head=0; dis[Q[++rear]=S]=0;

	while (head<rear) {

		int x=Q[++head];

		for (int i=u[x];~i;i=e[i].nt) {

			int j=e[i].v;

			if (e[i].c>0&&dis[j]>dis[x]+1) dis[Q[++rear]=j]=dis[x]+1;

		}

	}

	return dis[T]!=INF;

}

int DFS(int now,int flow) {

	if (now==T) return flow;

	int ans=0;

	for (int& i=cur[now];~i;i=e[i].nt) {

		int j=e[i].v;

		if (e[i].c>0&&dis[j]==dis[now]+1) {

			int k=min(e[i].c,flow); k=DFS(j,k);

			e[i].c-=k; e[i^1].c+=k; ans+=k; flow-=k;

		}

		if (!flow) break;

	}

	return ans;

}

int Dinic() {

	int ans=0;

	while (BFS()) {

		FOR(i,1,nn) cur[i]=u[i];

		ans+=DFS(S,INF);

	}

	return ans;

}

int n,m,q,a[MAXN],b[MAXN];

int main(){

	n=read(); m=read(); clear();

	S=n+m+1,nn=T=S+1;

	FOR(i,1,n)

		FOR(j,1,m) {

			char ch=getchar();

			while (ch!='.'&&ch!='o'&&ch!='S'&&ch!='T') ch=getchar();

			if (ch=='o') addEdge(i,n+j,1),addEdge(n+j,i,1);

			if (ch=='S') addEdge(S,i,n*m+1),addEdge(S,n+j,n*m+1);

			if (ch=='T') addEdge(i,T,n*m+1),addEdge(n+j,T,n*m+1);

		}

	int ans=Dinic();

	if (ans>=n*m) puts("-1");

	else printf("%d\n",ans);

	

	return 0;

}



/*

*/
