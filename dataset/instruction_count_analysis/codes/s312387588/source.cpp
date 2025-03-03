#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#define MAXN 500005

#define mod 1000000007ll



long long f[MAXN]={1ll};



long long power(long long x,long long p){

	if(p==1ll) return x%mod;

	if(p==0ll) return 0ll;

	long long t=power(x,p/2ll);

	if(p&1ll) return t*t%mod*x%mod;

	else return t*t%mod;

}



long long c(long long n,long long m){

	if(m==0||m==n) return 1ll;

	if(n<m) return 0ll;

	return f[n]*power(f[m],mod-2ll)%mod*power(f[n-m],mod-2ll)%mod;

}



long long n,m;

long long a,b;

int main(){

	scanf("%lld %lld",&n,&m);

	scanf("%lld %lld",&a,&b);

	for(long long i=1;i<=m+n;i++)

		f[i]=f[i-1]*i%mod;

	long long ans=c(m+n-2,m-1);

	long long i=n-a+1,j=b;

	while(i<=n&&j>=1){

		ans=((ans-c(i+j-2,j-1)*c(m+n-i-j,m-j))%mod+mod)%mod;

		i++;j--;

	}

	printf("%lld",ans);

	system("pause");

}








