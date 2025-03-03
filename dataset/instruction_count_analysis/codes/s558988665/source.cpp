#include "stdc++.h"

using namespace std;

template<class t> inline t read(t &x){

	char c=getchar();bool f=0;x=0;

	while(!isdigit(c)) f|=c=='-',c=getchar();

	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();

	if(f) x=-x;return x;

}

template<class t> inline void write(t x){

	if(x<0) putchar('-'),write(-x);

	else{if(x>9) write(x/10);putchar('0'+x%10);}

}



#define int long long



const int mod=1e9+7,N=2e5+5;

int en,h[N],fac[N],inv[N],g[N],f[N],n,sz[N];



struct edge{

	int n,v;

}e[N<<1];



void add(int x,int y){

	e[++en]=(edge){h[x],y};

	h[x]=en;

}



int fpow(int x,int y){

	int res=1;

	for(;y;y>>=1,x=x*x%mod) if(y&1) res=res*x%mod;

	return res;

}



int C(int x,int y){

	return fac[x]*inv[y]%mod*inv[x-y]%mod;

}



void dfs1(int x,int fa){

	f[x]=1;

	for(int i=h[x];i;i=e[i].n){

		int y=e[i].v;

		if(y==fa) continue;

		dfs1(y,x);

		sz[x]+=sz[y];

		f[x]=f[x]*f[y]%mod*C(sz[x],sz[y])%mod;

	}

	sz[x]++;

}



void dfs2(int x,int fa){

	for(int i=h[x];i;i=e[i].n){

		int y=e[i].v;

		if(y==fa) continue;

		g[y]=f[y]*g[x]%mod*fpow(f[y]*C(n-1,sz[y])%mod,mod-2)%mod*C(n-1,n-sz[y])%mod;

		dfs2(y,x);

	}

}



signed main(){

	read(n);

	for(int i=1,x,y;i<n;i++){

		read(x);read(y);

		add(x,y);add(y,x);

	}

	fac[0]=1;

	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;

	inv[n]=fpow(fac[n],mod-2);

	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;

	dfs1(1,0);

	g[1]=f[1];

	dfs2(1,0);

	for(int i=1;i<=n;i++) write(g[i]),puts("");

}