#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<vector>

#include<math.h>

using namespace std;

#define N 1000010

#define LL long long

int a[N],vis[N];

LL s[N],b[N],c[N],p[N];

int main()

{

    int i,j,k,n,m;

    int x,y,z;

    LL d,t,ans;

    scanf("%d%d",&n,&m);

    p[0]=1;

    for(i=1;i<=50;i++)

        p[i]=p[i-1]*2;

    for(i=1;i<=n;i++)

        scanf("%d",&a[i]);

    s[0]=0;

    for(i=1;i<=n;i++)

        s[i]=s[i-1]+a[i];

    k=0;

    for(i=1;i<=n;i++)

    for(j=i;j<=n;j++)

    {

        d=s[j]-s[i-1];

        b[k++]=d;

    }

    ans=0;

    y=40;

    while(1)

    {

        for(i=y;i>=0;i--)

        {

            z=0;

            d=ans+p[i];

            for(j=0;j<k;j++)

            if((b[j]&d)==d)

                z++;

            if(z>=m)

                break;

        }

        if(i<0)

            break;

        ans=ans+p[i];

        y=i-1;

    }

    printf("%lld\n",ans);

    return 0;

}
