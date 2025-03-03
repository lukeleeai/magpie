#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<map>

#include<set>

#include<vector>

using namespace std;

#define ll long long

#define db double

ll a[100005];

ll sumj[100005];

ll sumo[100005];

int main()

{

    ll n,cntj=1,cnto=1;

    scanf("%lld",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%lld",&a[i]);

        if(i%2)

        {

            sumj[cntj]=sumj[cntj-1]+a[i];

            cntj++;

        }

        else

        {

            sumo[cnto]=sumo[cnto-1]+a[i];

            cnto++;

        }

    }

    ll sum=sumj[cntj-1]+sumo[cnto-1];

    for(int i=1;i<=n;i++)

    {

        if(i%2)

        {

            ll ans=a[i]-sumj[(i-1)/2]+sumo[(i-1)/2]+(sumj[cntj-1]-sumj[(i+1)/2])-(sumo[cnto-1]-sumo[(i-1)/2]);

            printf("%lld ",ans);

        }

        else

        {

            ll ans=a[i]+sumj[i/2]-sumo[i/2-1]+(sumo[cnto-1]-sumo[i/2])-(sumj[cntj-1]-sumj[i/2]);

            printf("%lld ",ans);

        }

    }

    return 0;

}




