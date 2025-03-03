#include<cstdio>

#include<cmath>

#include<algorithm>

using namespace std;

int n,a[1000005],ans=1;

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    sort(a+1,a+n+1);

    for(int i=a[2];i>=2;i--)

    {

        int t=0;

        for(int j=1;j<=n;j++)

        {

            if(a[j]%i!=0) t++;

            if(t>=2) break;

        }

        if(t<=1)

        {

            ans=i;

            break;

        }

    }

    printf("%d",ans);

    return 0;

}