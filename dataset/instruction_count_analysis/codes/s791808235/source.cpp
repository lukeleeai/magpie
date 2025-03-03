#include<stdio.h>

#include<algorithm>

#define ll long long

#define maxn 100010

using namespace std;



ll pre[maxn];

ll a[maxn];



int main()

{

    ll i,n,m,t = 1,sum = 0;



    scanf("%lld%lld",&n,&m);

    pre[0] = 0;

    for(i = 1; i <= n; i++)

    {

        scanf("%lld",&a[i]);

        pre[i] = (pre[i-1]+a[i])%m;

    }

    sort(pre+1,pre+n+1);



    for(i = 1; i <= n; i++)

    {

        if(pre[i] == pre[i-1])

            t++;

        else

        {

            sum += t*(t-1)>>1;

            t = 1;

        }

    }

    sum += t*(t-1)>>1;

    printf("%lld\n",sum);



    return 0;

}