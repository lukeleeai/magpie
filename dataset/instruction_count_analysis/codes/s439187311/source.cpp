#include <stdio.h>

long long mod=1e9+7;

long long vis[100005],a[100005]={1,1,2};

int main()

{

    long long i,x,n,k;

    scanf("%lld%lld",&n,&k);

    for(i=1; i<=k; i++)

    {

        scanf("%lld",&x);

        vis[x]=1;

    }

    if(vis[1]) a[1]=0;

    for(i=2; i<=n; i++)

    {

        if(vis[i]) a[i]=0;

        else a[i]=(a[i-1]%mod+a[i-2]%mod)%mod;

    }

    printf("%lld\n",a[n]);

    return 0;

}


