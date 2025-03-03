// luogu-judger-enable-o2

#include<cstdio>

#include<iostream>

using namespace std;



inline int In(){

	char c=getchar(); int x=0,ft=1;

	for(;c<'0'||c>'9';c=getchar()) if(c=='-') ft=-1;

	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';

	return x*ft;

}



const int N=2e5+5;

int n,h[N],e_tot=0;

struct Edge{

	int to,nex;

	Edge(){}

	Edge(int to,int nex):to(to),nex(nex){}

}e[N<<1];



inline void add(int u,int v){

	e[++e_tot]=Edge(v,h[u]); h[u]=e_tot;

}



int sz[N],cnt[N],fac[N],inv[N];



void dfs(int u,int pre){

	sz[u]=1;

	for(int i=h[u],v;i;i=e[i].nex){

		v=e[i].to; if(v==pre) continue;

		dfs(v,u); sz[u]+=sz[v];

	}

	if(u!=1) ++cnt[sz[u]],++cnt[n-sz[u]];

}



const int P=924844033;

int L,C,r[N<<2],F[N<<2],G[N<<2],H[N<<2];



inline void Add(int& x,int y){

	x+=y; if(x>=P) x-=P;

}



inline int Mul(int x,int y){

	return 1ll*x*y%P;

}



inline int fpow(int x,int k){

	int res=1;

	for(;k;k>>=1,x=Mul(x,x)) if(k&1) res=Mul(res,x);

	return res;

}



inline void NTT_prepare(int len){

	for(L=1,C=0;L<=len;L<<=1,++C);

	for(int i=0;i<L;++i) r[i]=(r[i>>1]>>1)|((i&1)<<(C-1));

}



void NTT(int* A,int op){

	for(int i=0;i<L;++i) if(i<r[i]) swap(A[i],A[r[i]]);

	for(int i=1;i<L;i<<=1){

		int Wn=fpow(5,(P-1)/(i<<1));

		if(op==-1) Wn=fpow(Wn,P-2);

		for(int j=0;j<L;j+=i<<1){

			int w=1;

			for(int k=0;k<i;++k,w=Mul(w,Wn)){

				int p=A[j+k],q=Mul(w,A[j+i+k]);

				A[j+k]=(p+q)%P; A[j+i+k]=((p-q)%P+P)%P;

			}

		}

	}

	if(op==-1){

		int inv_L=fpow(L,P-2);

		for(int i=0;i<L;++i) A[i]=Mul(A[i],inv_L);

	}

}



int main(){

	n=In();

	for(int i=1,u,v;i<n;++i){

		u=In(); v=In();

		add(u,v); add(v,u);

	}

	dfs(1,0); fac[0]=inv[0]=inv[1]=1;

	for(int i=1;i<=n;++i) fac[i]=Mul(fac[i-1],i);

	for(int i=2;i<=n;++i) inv[i]=Mul(P-P/i,inv[P%i]);

	for(int i=1;i<=n;++i) inv[i]=Mul(inv[i-1],inv[i]);

	for(int i=0;i<=n;++i) G[i]=Mul(cnt[i],fac[i]);

	for(int i=0;i<=n;++i) H[i]=inv[n-i];

	NTT_prepare(n+n); NTT(G,1); NTT(H,1);

	for(int i=0;i<L;++i) F[i]=Mul(G[i],H[i]); NTT(F,-1);

	for(int i=1;i<=n;++i){

		int res=Mul(n,Mul(fac[n],Mul(inv[i],inv[n-i])));

		Add(res,P-Mul(inv[i],F[n+i])); printf("%d\n",res);

	}

	return 0;

}