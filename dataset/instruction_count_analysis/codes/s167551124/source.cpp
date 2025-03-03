#include <stdio.h>

#include <string.h>

#include<algorithm>

using namespace std;

int main()

{

    int n;

    scanf("%d",&n);

    int a[105];

    int b[105];

    int sum=0,ans=0;

    for(int x=0;x<n;x++)

    {

        scanf("%d",&a[x]);

        sum+=a[x];

    }

    for(int x=0;x<n;x++)

    {

        b[x]=abs(sum-ans);

        sum-=a[x];

        ans+=a[x];

    }

    b[n]=abs(sum-ans);

    sort(b,b+n+1);

    printf("%d\n",b[0]);

    return 0;

}
