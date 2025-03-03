#include"stdc++.h"

using namespace std;



#define CO const

#define IN inline

typedef long long int64;



template<class T> IN T read(){

	T x=0,w=1;char c=getchar();

	for(;!isdigit(c);c=getchar())if(c=='-') w=-w;

	for(;isdigit(c);c=getchar()) x=x*10+c-'0';

	return x*w;

}

template<class T> IN T read(T&x){

	return x=read<T>();

}



CO int N=2e5+10;

vector<int> to[N];

int deg[N];

char str[N];

int tag[N],tot;

int val[N],p;

int dp[N][2],f[N];



void check(int u,int fa){

	if(str[u]=='W') tag[u]=1;

	for(int v:to[u])if(v!=fa){

		check(v,u);

		if(!tag[v]) --deg[u],--deg[v];

		tag[u]|=tag[v];

	}

	tot+=tag[u];

}

void dfs(int u,int fa){

	f[u]=2*(tot-1)+p;

	dp[u][0]=val[u]?-1:1;

	for(int v:to[u])if(v!=fa and tag[v]){

		dfs(v,u);

		f[u]=min(f[u],f[v]);

		f[u]=min(f[u],2*(tot-1)+p-dp[u][0]-dp[v][1]-1);

		f[u]=min(f[u],2*(tot-1)+p-dp[u][1]-dp[v][0]-1);

		dp[u][0]=max(dp[u][0],dp[v][0]+1+(val[u]?-1:1));

		dp[u][1]=max(dp[u][1],dp[v][1]+1+(val[u]?-1:1));

	}

}

int main(){

	int n=read<int>();

	for(int i=1;i<n;++i){

		int u=read<int>(),v=read<int>();

		to[u].push_back(v),to[v].push_back(u);

		++deg[u],++deg[v];

	}

	scanf("%s",str+1);

	int rt=0;

	for(int i=1;i<=n;++i)if(str[i]=='W') rt=i;

	check(rt,0);

	for(int i=1;i<=n;++i)if(tag[i]) val[i]=(str[i]=='B')^(deg[i]&1),p+=!val[i];

	dfs(rt,0);

	printf("%d\n",!tot?tot:f[rt]);

	return 0;

}
