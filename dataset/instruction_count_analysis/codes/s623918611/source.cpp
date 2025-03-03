#include <stdio.h>

#include<stdlib.h>

#define N 100100

using namespace std;

long long f[N],k[N],ans[N],sum;

int x[N],y[N];

int get(int x)

{

    if(k[x]==x) return x;

    return k[x]=get(k[x]);

}

void ju(int x,int y)

{

    int tx=get(x);

    int ty=get(y);

    k[tx]=ty;

    f[ty]+=f[tx];

}

int main()

{

    int n,m,i;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++) k[i]=i,f[i]=1;

    for(i=1;i<=m;i++)

    {

        scanf("%d%d",&x[i],&y[i]);

    }

    for(i=m;i>=1;i=i-1)

    {

        int tx=get(x[i]);

        int ty=get(y[i]);

        if(tx!=ty)

        sum=f[tx]*f[ty],

        ju(x[i],y[i]),

        ans[i]=ans[i+1]+sum;

        else ans[i]=ans[i+1];

    }

    for(i=2;i<=m;i++)

    {

        printf("%lld\n",1ll*(n-1)*n/2-ans[i]);

    }

    printf("%lld\n",1ll*(n-1)*n/2);

}
