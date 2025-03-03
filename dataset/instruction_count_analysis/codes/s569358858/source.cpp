#include "stdc++.h"

#define LL long long int

using namespace std;



LL sum[100010];

LL a[100010];

map<LL,LL> Q;



int main()

{

    LL n,m;

    while(scanf("%lld%lld",&n,&m)!=EOF)

    {

        Q.clear();

        sum[0]=0;

        LL ans=0;

        for(LL i=1;i<=n;i++)

        {

            scanf("%I64d",&a[i]);

            sum[i]=sum[i-1]+a[i];

            sum[i]%=m;

            Q[sum[i]]++;

        }

        Q[0]++;

        map<LL,LL>::iterator it=Q.begin();

        while(it!=Q.end())

        {

            ans+=(it->second)*(it->second-1)/2;

            it++;

        }

        printf("%lld\n",ans);

    }

    return 0;

}
