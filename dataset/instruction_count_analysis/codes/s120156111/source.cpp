#include <cstdio>

const int N=1000005,Mod=998244353;

int fac[N],inv[N];

inline int qpow(int a,int b){

	int ans=1;

	while (b){

		if (b&1) ans=(1ll*ans*a)%Mod;

		a=(1ll*a*a)%Mod,b>>=1;

	}

	return ans;

}

inline int Min(int a,int b){

	return a<b?a:b;

}

inline int Max(int a,int b){

	return a>b?a:b;

}

inline int C(int n,int m){

	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;

}

int main (){

	int n,m;scanf ("%d%d",&n,&m);

	fac[0]=1;

	for (int i=1;i<=n+m;i++) fac[i]=1ll*fac[i-1]*i%Mod;

	inv[n+m]=qpow(fac[n+m],Mod-2);

	for (int i=n+m-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%Mod;

	int t=Min(n,m),ans=0;

	for (int i=1;i<=t;i++) ans=(1ll*ans+1ll*C(i*2,i)*C(n+m-2*i,n-i))%Mod;

	ans=1ll*ans*qpow(2,Mod-2)%Mod*qpow(C(n+m,n),Mod-2)%Mod;

	printf ("%d",(ans+Max(n,m))%Mod);

	return 0;

}