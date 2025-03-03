#include<cstdio>



const int mod=998244353,N=1000005;



int fexp(int a,int b)

{

	int x=1;

	for(;b;b>>=1,a=1LL*a*a%mod)

		if(b&1)x=1LL*x*a%mod;

	return x;

}



int n,m,ans,fac[N],ifac[N];



int main()

{

	scanf("%d%d",&n,&m);

	n+=m;

	fac[0]=1;

	for(int i=1; i<=n; ++i)fac[i]=1LL*i*fac[i-1]%mod;

	ifac[n]=fexp(fac[n],mod-2);

	for(int i=n-1; ~i; --i)ifac[i]=1LL*(i+1)*ifac[i+1]%mod;

	n-=m;

	if(n<m){int k=n;n=m;m=k;}

	for(int x=1; x<=m; ++x)

		ans=(ans+1LL*fac[x+x]*ifac[x]%mod*ifac[x]%mod*fac[n-x+m-x]%mod*ifac[n-x]%mod*ifac[m-x])%mod;

	ans=1LL*ans*ifac[2]%mod*ifac[n+m]%mod*fac[n]%mod*fac[m]%mod;

	printf("%d",(ans+n)%mod);

	return 0;

}
