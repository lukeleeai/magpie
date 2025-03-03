#include<cmath>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

#define ll long long

using namespace std;

const int MAXN=200233;

const int D=924844033,G=5,iG=554906420;

int n,ans[MAXN];

vector<int> ver[MAXN];



int fac[MAXN],inv[MAXN];

int rev[MAXN<<2];

int A[MAXN<<2],B[MAXN<<2];



int qpow(int x,int y) {

	int ret=1;

	while(y) {

		if(y&1) ret=1ll*ret*x%D;

		x=1ll*x*x%D;

		y>>=1;

	}

	return ret;

}



void NTT(int f[],int op,int lim) {

	for(int i=1;i<lim;i++)

		if(rev[i]>i) swap(f[rev[i]],f[i]);

	for(int i=1;i<lim;i<<=1) {

		int sta=qpow(~op?G:iG,(D-1)/(i<<1));

		for(int j=0;j<lim;j+=(i<<1)) {

			int w=1;

			for(int k=0;k<i;k++,w=1ll*w*sta%D) {

				int t1=f[j+k],t2=1ll*w*f[i+j+k]%D;

				f[j+k]=(t1+t2)%D;

				f[i+j+k]=(t1-t2+D)%D;

			} 

		}

	}

	if(~op) return ;

	int ilim=qpow(lim,D-2);

	for(int i=0;i<lim;i++)

		f[i]=1ll*f[i]*ilim%D;

}



int siz[MAXN];

void dfs(int u,int fa) {

	siz[u]=1;

	for(int v:ver[u])

		if(v!=fa) dfs(v,u),siz[u]+=siz[v];

}



void first() {

	fac[0]=1;

	for(int i=1;i<=n;i++) fac[i]=1ll*i*fac[i-1]%D;

	inv[n]=qpow(fac[n],D-2);

	for(int i=n-1;~i;i--) inv[i]=1ll*inv[i+1]*(i+1)%D;

}

int C(int x,int y) {

	return 1ll*fac[x]*inv[y]%D*inv[x-y]%D;

}



int main() {

	scanf("%d",&n);

	first();

	for(int i=1;i<n;i++) {

		int x,y; scanf("%d%d",&x,&y);

		ver[x].push_back(y);

		ver[y].push_back(x);

	}

	dfs(1,0);

	siz[0]=1;

	for(int i=2;i<=n;i++)

		++A[siz[i]],++A[n-siz[i]];

	for(int i=0;i<=n;i++)

		A[i]=1ll*A[i]*fac[i]%D;

	for(int i=0;i<=n;i++)

		B[i]=inv[i];

	reverse(B,B+n+1);



	int lim; for(lim=1;lim<=(n<<1);lim<<=1);

	for(int i=1;i<lim;i++)

		rev[i]=(rev[i>>1]>>1)|(i&1?lim>>1:0);

	NTT(A,1,lim),NTT(B,1,lim);

	for(int i=0;i<lim;i++)

		A[i]=1ll*A[i]*B[i]%D;

	NTT(A,-1,lim);



	for(int i=1;i<=n;i++)

		ans[i]=((1ll*C(n,i)*n-1ll*inv[i]*A[n+i])%D+D)%D;



	for(int i=1;i<=n;i++)

		printf("%d\n",ans[i]);

	return 0;

}