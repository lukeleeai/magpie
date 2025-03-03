#include<iostream>

#include<cstdio>

#define mod 998244353

using namespace std;

long long n,a,b,k,ans=0,anss[300005][3],fac[300005],cnt=0;

inline long long inv(long long b){  

    return b==1?1:(mod-mod/b)*inv(mod%b)%mod;

}

inline long long C(long long n,long long m){  

    long long t=(fac[m]*fac[n-m])%mod;

    return (fac[n]*inv(t))%mod;

}

inline void init(){

	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);

	fac[0]=1,fac[1]=1;

	for(int i=2;i<300005;i++) fac[i]=(fac[i-1]*i)%mod;

}

int main(){

	init();

	for(int i=0;i<=n;i++)

		if(k>=(i*a)&&(k-a*i)%b==0&&(k-a*i)/b<=n){

			anss[cnt][0]=i;

			anss[cnt++][1]=(k-a*i)/b;

		}

	for(int i=0;i<cnt;i++) ans=(ans+C(n,anss[i][0])*C(n,anss[i][1])%mod)%mod;

	printf("%lld\n",ans);

	return 0;

}