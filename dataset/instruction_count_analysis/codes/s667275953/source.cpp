#include<stdio.h>

#include<string.h>

#include<iostream>

#include<algorithm>

#include<string.h>

#include<math.h>

#define ll long long

using namespace std;

ll b[1000005];

int main()

{

    int n;

    scanf("%d",&n);

    

    ll a[100005],i;

    

    for(i=0; i<n; i++)

        scanf("%lld",&a[i]);

    memset(b,0,sizeof(b));

    if(n>=1e5)

        a[-2]=0;

    if(a[0]!=0)

            printf("0\n");

    else

    {

        ll ans=1;

        for(i=0;i<n;i++)

            b[a[i]]++;

        for(i=1;i<n;i++)

        {

            ans*=b[a[i]-1];

            ans%=998244353;

        }



        printf("%lld\n",ans);

    }

    return 0;

}
