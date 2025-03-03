#include"stdc++.h"

using namespace std;



#define CO const

#define IN inline

typedef long long LL;

typedef long double LD;



template<class T> T read(){

	T x=0,w=1;char c=getchar();

	for(;!isdigit(c);c=getchar())if(c=='-') w=-w;

	for(;isdigit(c);c=getchar()) x=x*10+c-'0';

	return x*w;

}

template<class T> IN T read(T&x){

	return x=read<T>();

}

#define gcd __gcd



CO int mod=1e9+7;

IN int add(int a,int b){

	return (a+=b)>=mod?a-mod:a;

}

IN int mul(int a,int b){

	return (LL)a*b%mod;

}

IN int fpow(int a,int b){

	int ans=1;

	for(;b;b>>=1,a=mul(a,a))

		if(b&1) ans=mul(ans,a);

	return ans;

}



CO int N=500;

vector<int> to[N];

int E[N][N];

int pos[N],low[N],dfn,stk[N],top;

vector<int> vcc[N];

int tot;



void tarjan(int u,int fa){

	pos[u]=low[u]=++dfn,stk[++top]=u;

	for(int v:to[u]){

		if(!pos[v]){

			tarjan(v,u);

			low[u]=min(low[u],low[v]);

			if(low[v]>=pos[u]){

				vcc[++tot].push_back(u);

				do vcc[tot].push_back(stk[top]);

				while(stk[top--]!=v);

			}

		}

		else low[u]=min(low[u],pos[v]);

	}

}



int K,C[N][N];



int circle(int n){

	int ans=0;

	for(int i=0;i<n;++i) ans=add(ans,fpow(K,gcd(n,i)));

	ans=mul(ans,fpow(n,mod-2));

	return ans;

}

int calc(CO vector<int>&vcc){

	if(vcc.size()==2) return K;

	int cnt=0;

	for(int u:vcc)for(int v:vcc)

		cnt+=E[u][v];

	cnt/=2;

	if(cnt==(int)vcc.size()) return circle(cnt);

	return C[cnt+K-1][K-1];

}

int main(){

	int n=read<int>(),m=read<int>();read(K);

	for(int i=1;i<=m;++i){

		int u=read<int>(),v=read<int>();

		E[u][v]=E[v][u]=1;

		to[u].push_back(v),to[v].push_back(u);

	}

	for(int i=1;i<=n;++i)if(!pos[i]) tarjan(i,0);

	for(int i=0;i<=m+K;++i){

		C[i][0]=C[i][i]=1;

		for(int j=1;j<i;++j) C[i][j]=add(C[i-1][j-1],C[i-1][j]);

	}

	int ans=1;

	for(int i=1;i<=tot;++i) ans=mul(ans,calc(vcc[i]));

	printf("%d\n",ans);

	return 0;

}
