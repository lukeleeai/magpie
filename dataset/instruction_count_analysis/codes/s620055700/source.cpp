#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

const int N=16;

const int MOD=1e9+7;

int n,m;

int a[N+1];

long long f[N+1][1<<N|1],fac[1<<N|1],inv[1<<N|1];

long long ksm(long long a,long long b)

{

	long long res=1;

	while(b)

	{

		if(b&1) res=res*a%MOD;

		a=a*a%MOD,b>>=1;

	}

	return res;

}

long long C(int n,int m)

{

    if(n<m) return 0;

    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

		scanf("%d",&a[i]);

    fac[0]=1;

    for(int i=1;i<=(1<<n);i++)

		fac[i]=fac[i-1]*i%MOD;

	inv[1<<n]=ksm(fac[1<<n],MOD-2);

    for(int i=1<<n;i>=1;i--)

    	inv[i-1]=inv[i]*i%MOD;

    sort(a+1,a+m+1,greater<int>());

    f[0][0]=1;

    for(int i=1;i<=m;i++)

        for(int j=0;j<(1<<n);j++)

		{

            f[i][j]=(f[i][j]+f[i-1][j])%MOD;

            for(int k=0;k<n;k++)

			{

                if(j&(1<<k)) continue;

                if((1<<n)-j-a[i]<(1<<k)-1) break;

                f[i][j|(1<<k)]=(f[i][j|(1<<k)]-f[i-1][j]*C((1<<n)-j-a[i],(1<<k)-1)%MOD*fac[1<<k]%MOD+MOD)%MOD;

            }

        }

    long long ans=0;

    for(int i=0;i<(1<<n);i++)

        ans=(f[m][i]*fac[(1<<n)-i-1]%MOD+ans)%MOD;

    ans=(ans*(1<<n)%MOD)%MOD;

    printf("%lld",ans);

    return 0;

}