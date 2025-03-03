#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

long long a[1000010];

int main()

{

    int n,x=1,ans=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)

        scanf("%lld",&a[i]);

    sort(a,a+n);

    for(int i=1;i<n;i++)

    {

        if(a[i]==a[i-1])

            x=(x+1)%2;

        else

        {

            ans+=x;

            x=1;

        }

    }

    if(x%2)

        ans++;

    printf("%d\n",ans);

    return 0;

}


