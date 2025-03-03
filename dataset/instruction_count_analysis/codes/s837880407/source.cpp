#include<stdio.h>

#define ll long long

const ll mod=1e9+7;

const int N=1e5+9;

ll vis[N],a[N];

int main()

{

    int t,n,x;

    scanf("%d%d",&t,&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d",&x);

        vis[x]=1;

    }

    a[0]=1;

    if(!vis[1]) a[1]=1;

    for(int i=2;i<=t;i++)

    {

        if(vis[i]) continue;

        a[i]=(a[i-1]+a[i-2])%mod;

//        printf("%lld  a[i],  %d  i\n",a[i],i);

    }

    printf("%lld\n",a[t]);

    return 0;

}
