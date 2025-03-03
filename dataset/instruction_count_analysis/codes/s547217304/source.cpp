#include "stdio.h"

#include "algorithm"

using namespace std;

long long int sum[100500],num[1000500];

int n;

bool ch(int x)

{

    for(int i=x;i<n;i++) if(sum[i]*2<num[i+1]) return false;

    return true;

}

main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d",&num[i]);

    sort(num+1,num+n+1);

    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i];

    int hi=n,lo=1,mid;

    while(hi-lo>1)

    {

        mid=(hi+lo)/2;

        if(ch(mid)) hi=mid;

        else lo=mid;

    }

    if(ch(lo)) printf("%d",n-lo+1);

    else printf("%d",n-lo);

}
