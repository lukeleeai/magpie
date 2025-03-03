#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int Mod=998244353;

long long fac[300005],inv[300005];

long long quipow(long long x,long long n)  

{

    long long res=1;

    while(n>0)

    {

        if(n&1) res=res*x%Mod;

        x=x*x%Mod;

        n>>=1;

    }

    return res;

}

int main()

{

	int n;long long k,A,B,ans=0;

	fac[0]=fac[1]=1;

	for(int i=2;i<=300000;i++)fac[i]=fac[i-1]*i%Mod;

	inv[300000]=quipow(fac[300000],Mod-2);

	for(int i=299999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%Mod;

	scanf("%d%lld%lld%lld",&n,&A,&B,&k);

	for(int i=0;i<=n&&i*A<=k;i++)

	{

		if((k-i*A)%B) continue;

		int j=(int)((k-i*A)/B);

		if(j>n) continue;

		ans=(ans+1ll*fac[n]*fac[n]%Mod*inv[i]%Mod*inv[j]%Mod*inv[n-i]%Mod*inv[n-j]%Mod)%Mod;

	}

	printf("%lld",ans);

}
