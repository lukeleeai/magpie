#include "stdc++.h"

using namespace std;



long long mod=1e9+7;



long long n,m;

long long maxn,k;



int main()

{

    scanf("%lld%lld",&n,&m);

    if(abs(n-m)>1)

    {

        printf("0\n");

        return 0;

    }

    maxn=max(n,m);

    k=min(n,m);

    if(n==m)

    {

        long long ans=1;

        for(long long i=1;i<=maxn;i++)

        {

            ans=(ans*i)%mod;

        }

        ans=(ans*ans)%mod;

        printf("%lld",(ans*2)%mod);

    }

    else

    {

        long long ans=1;

        for(int i=1;i<=k;i++)

        {

            ans=(ans*i)%mod;

        }

        ans=(ans*ans)%mod;

        ans=(ans*maxn)%mod;

        printf("%lld",ans);

    }

    return 0;

}
