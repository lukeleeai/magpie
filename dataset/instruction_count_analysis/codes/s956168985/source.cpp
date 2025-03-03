#include"stdc++.h"



using namespace std;

typedef long long LL;

LL a[100005];

int main()

{

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)

    {

        cin>>a[i];

    }

    sort(a+1,a+1+n);

    LL ans=0;

    if(n%2==1)

    {

        int num=(n-1)/2;

        for(int i=n;i>=n-(n-1)/2+1;i--)

        {

            ans+=a[i]*2;

        }

        for(int i=1;i<=(n-1)/2-1;i++)

        {

            ans-=a[i]*2;

        }

        for(int i=(n-1)/2;i<=n-(n-1)/2;i++)

        {

            ans-=a[i];

        }

        LL sum=0;

        for(int i=1;i<=n/2;i++)

        {

            sum-=a[i]*2;

        }

        sum+=a[n/2+1]+a[n/2+2];

        for(int i=n/2+3;i<=n;i++)

        {

            sum+=a[i]*2;

        }

        if(sum>ans)

        {

            ans=sum;

        }

    }

    else

    {     

         for(int i=n;i>=n-(n-2)/2+1;i--)

         {

             ans+=a[i]*2;

         }

         ans+=a[n-(n-2)/2];

         ans-=a[n-(n-2)/2-1];

         for(int i=1;i<=(n-2)/2;i++)

         {

             ans-=a[i]*2;

         }

    }

    cout<<ans<<endl;

}
