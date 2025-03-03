#include <stdio.h>

#include <string.h>

#include <algorithm>

#define N 100010

int n,m,c[N],d[N],k[N];char vis[N];

int fa[N];

int find(int x) {

	return ~fa[x]?fa[x]=find(fa[x]):x;

}

inline void join(int a,int b) {

	int x=find(a),y=find(b);

	if(x!=y) {

		fa[x]=y;

		if(d[k[y]]>d[k[x]]) k[y]=k[x];

	}

}

int main() {

	int a,b;long long ans=0;

	scanf("%d%d",&n,&m);

	if(n-2*m>2) {

		puts("Impossible");

		return 0;

	}

	if(n-1==m) {

		puts("0");

		return 0;

	}

	memset(fa,-1,sizeof(fa));

	for(int i=0;i<n;++i) scanf("%d",d+i),k[i]=i;

	for(int i=0;i<m;++i) {

		scanf("%d%d",&a,&b);

		join(a,b);

	}

	for(int i=0;i<n;++i) if(!~fa[i]) vis[k[i]]=1,ans+=d[k[i]];

	a=0;

	for(int i=0;i<n;++i) if(!vis[i]) c[a++]=d[i];

	std::sort(c,c+a);

	b=n-m-2;

	for(int i=0;i<b;++i) ans+=c[i];

	printf("%lld",ans);

	return 0;

}