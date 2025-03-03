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

const int MN=2005;

int n,k,root,s[MN],t[MN],dis[MN][MN];

struct edge{int to,nxt;}es[MN<<1];

int h[MN],cnt;

inline void ins(int s,int t){

	es[++cnt]=(edge){t,h[s]};h[s]=cnt;

	es[++cnt]=(edge){s,h[t]};h[t]=cnt;

}

inline void dfs(int fa,int st,int dep){

	for(reg int i=h[st];i;i=es[i].nxt)

		if(es[i].to!=fa){

			dis[root][es[i].to]=dis[es[i].to][root]=dep;

			dfs(st,es[i].to,dep+1);

		}

}

int main(){

	n=read<int>();k=read<int>();reg int ans=0x7fffffff;

	for(reg int i=1;i<n;i++)ins(s[i]=read<int>(),t[i]=read<int>());

	for(reg int i=1;i<=n;i++)dfs(root=i,i,1);

	if(k&1){

		k>>=1;

		for(reg int i=1;i<n;i++){

			reg int cnt=0;

			for(reg int j=1;j<=n;j++)

				if(dis[j][s[i]]>k&&dis[j][t[i]]>k)cnt++;

			ans=min(ans,cnt);

		}

	}

	else

		for(reg int i=1;i<=n;i++){

			reg int cnt=0;

			for(reg int j=1;j<=n;j++)

				if((i^j)&&(dis[i][j]<<1)>k)cnt++;

			ans=min(ans,cnt);

		}

	printf("%d\n",ans);

    return 0;

}