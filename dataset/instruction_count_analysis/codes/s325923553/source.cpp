#include"stdc++.h"

using namespace std;

const int N=2050000;

inline int rd(register int x=0,register char ch=getchar(),register int f=0){

	for(;!isdigit(ch);ch=getchar()) f=ch=='-';

	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;

	return f?-x:x;

}

int n,B;

int head[N],to[N<<1],nxt[N<<1],sta[N],vis[N],a[N],al[N];

vector<int> scc;



void lnk(int x,int y){

	to[++B]=y,nxt[B]=head[x],head[x]=B;

}

void dfs(int x,int prt){

	if(vis[x]){

		//printf("-> %d %d %d %d\n",x,prt,vis[x],sta[0]);

		for(int i=vis[x];i<=sta[0];++i) scc.push_back(sta[i]);

		return;

	}

	sta[++sta[0]]=x,vis[x]=sta[0];

	for(int i=head[x];i;i=nxt[i]) if(to[i]!=prt) dfs(to[i],x);

	vis[x]=0;--sta[0];

}

void DFS(int x,int prt){

	for(int i=head[x];i;i=nxt[i]) if(to[i]!=prt&&!vis[to[i]]) DFS(to[i],x);

	for(int i=head[x];i;i=nxt[i]) if(to[i]!=prt&&!vis[to[i]]) al[a[to[i]]]=1;

	while(al[a[x]]) ++a[x];

	for(int i=head[x];i;i=nxt[i]) if(to[i]!=prt&&!vis[to[i]]) al[a[to[i]]]=0;

}

int main(){

	n=rd();

	for(int i=1;i<=n;++i) lnk(rd(),i);

	for(int i=1;i<=n;++i) if(!scc.size()) dfs(i,0);

	for(auto x:scc) vis[x]=1;

	for(auto x:scc) DFS(x,0);

	int mx=-n-100,mn=n+100;

	for(auto x:scc) mx=max(mx,a[x]),mn=min(mn,a[x]);

	puts((mx==mn&&scc.size()%2!=0)?"IMPOSSIBLE":"POSSIBLE");

}