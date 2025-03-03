#include<cstdio>

#include<cctype>

#include<cstring>

#include<algorithm>

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define reg register

typedef long long ll;

template<typename T>inline T read(){

	reg T x=0;reg short f=1;reg char c=getchar();

	for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());

	for(;isdigit(c);x=x*10+(c^48),c=getchar());

	return x*f;

}

const int MN=100005;

struct edge{int t,nxt;}es[MN<<1];

int h[MN],cnt;

inline void ins(int s,int t){

	es[++cnt]=(edge){t,h[s]};h[s]=cnt;es[++cnt]=(edge){s,h[t]};h[t]=cnt;

}

int n,f;

inline int dfs(int st,int fa){

	if(f)return 1;

	reg int son=0;

	for(reg int i=h[st];i;i=es[i].nxt)

		if(es[i].t!=fa)son+=dfs(es[i].t,st);

	if(son>1)return f=1;

	return !son;

}

int main(){

	n=read<int>();

	for(reg int i=1;i<n;i++)ins(read<int>(),read<int>());

	reg int ans=dfs(1,0);puts((ans|f)?"First":"Second");

	return 0;

}