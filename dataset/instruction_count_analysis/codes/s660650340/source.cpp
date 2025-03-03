#include<cstdio>

#include<cstring>

#include<algorithm>

#define MN 100005

using namespace std;

inline int in(){

    int x=0;bool f=0;char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

struct edge{

	int to,nxt;

}e[MN<<1];

int h[MN],dep[MN],fa[MN],siz[MN];

int n,x,y,cnt,d;

inline void ins(int x,int y){

	e[++cnt].to=y;e[cnt].nxt=h[x];h[x]=cnt;

}

inline void dfs(int u){

	siz[u]=1;

	for (int i=h[u];i;i=e[i].nxt){

		int v=e[i].to;

		if (v==fa[u]) continue;

		dep[v]=dep[u]+1;fa[v]=u;

		dfs(v);siz[u]+=siz[v];

	}

}

int main()

{

	n=in();

	for (int i=1;i<n;++i){

		x=in();y=in();

		ins(x,y);ins(y,x);

	}fa[n]=0;dep[n]=1;dfs(n);d=(dep[1]>>1)+1;

	for (int i=1;i;i=fa[i])

	if (dep[i]==d){

		printf((siz[i]>n-siz[i])?"Fennec":"Snuke");return 0;

	}return 0;

}