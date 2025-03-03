#include"stdc++.h"

#define re register

#define inc(i,j,k) for(re int i=j;i<=k;i++)

#define edge(u) for(re int i=head[u];i;i=e[i].nxt)

#define ll long long

using namespace std;

const int mod=924844033;

const int N=8e5+5;

inline int read(){

	int x=0;

	char ch=getchar();

	while(ch<'0'||ch>'9') ch=getchar();

	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();

	return x;

}

int n,lim=1,l,r[N],head[N],num[N],sz[N],cnt;

struct edge{

	int to,nxt;

}e[N];

void add(int a,int b){

	e[++cnt].to=b;

	e[cnt].nxt=head[a];

	head[a]=cnt;

}

ll ans[N],fac[N],inv[N],f[N],g[N];

ll c(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}

ll qp(ll x,ll k){

	ll res=1;

	while(k){

		if(k&1) res=res*x%mod;

		k>>=1,x=x*x%mod;

	}

	return res;

}

void ntt(ll *tmp,int tp){

	inc(i,0,lim-1) if(i<r[i]) swap(tmp[i],tmp[r[i]]);

	for(re int mid=1;mid<lim;mid<<=1){

		ll gn=qp(5,(mod-1)/(mid<<1));

		if(tp==-1) gn=qp(gn,mod-2);

		for(re int i=0;i<lim;i+=(mid<<1)){

			ll g=1;

			inc(j,0,mid-1){

				ll x=tmp[i+j],y=g*tmp[i+j+mid]%mod;

				tmp[i+j]=(x+y)%mod;

				tmp[i+j+mid]=(x-y+mod)%mod;

				g=g*gn%mod;

			}

		}

	}

	if(tp==-1){

		ll inv=qp(lim,mod-2);

		inc(i,0,lim-1) tmp[i]=tmp[i]*inv%mod;

	}

}

void init(){

	n=read();

	inc(i,2,n){

		int a=read(),b=read();

		add(a,b),add(b,a);

	}

	fac[0]=inv[0]=inv[1]=1;

	inc(i,1,n) fac[i]=fac[i-1]*i%mod;

	inc(i,2,n) inv[i]=(mod-mod/i)*inv[mod%i]%mod;

	inc(i,3,n) inv[i]=inv[i-1]*inv[i]%mod;

}

void dfs(int u,int f){

	sz[u]=1;

	edge(u){

		int v=e[i].to;

		if(v==f) continue;

		dfs(v,u);

		sz[u]+=sz[v];	

	}

	if(u!=1){

		num[sz[u]]++;

		num[n-sz[u]]++;

	} 

}

int main(){

	init();dfs(1,0);

	inc(i,1,n) g[i]=inv[n-i];

	inc(i,1,n) f[i]=num[i]*fac[i]%mod;

	inc(i,1,n) ans[i]=n*c(n,i)%mod;

	while(lim<=2*n) lim<<=1,l++;

	inc(i,0,lim-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));

	ntt(g,1),ntt(f,1);

	inc(i,0,lim-1) f[i]=f[i]*g[i]%mod;

	ntt(f,-1);

	inc(i,1,n) (ans[i]+=mod-inv[i]*f[i+n]%mod)%=mod;

	inc(i,1,n) printf("%lld\n",ans[i]);	

}

/*

3

1 2

2 3

*/