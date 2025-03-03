#include"stdc++.h"

using namespace std;

typedef long long LL;

const int maxn = 100010;



int n;LL c;

LL d[maxn],v[maxn];

LL mmax[maxn],maxx[maxn];

LL sum1[maxn],sum2[maxn];



int main() {

    scanf("%d%lld",&n,&c);

    for(int i=1;i<=n;i++) scanf("%lld%lld",&d[i],&v[i]);

    for(int i=n;i>=1;i--) sum2[i] = sum2[i+1]+v[i];

    for(int i=1;i<=n;i++) sum1[i] = sum1[i-1]+v[i];



    LL ans = 0;

    for(int i=n;i>=1;i--) {

        mmax[i] = max(mmax[i+1],sum2[i]-(c-d[i]));

        ans = max(ans,mmax[i]);

        //printf("%lld ",mmax[i]);

    }//puts("");



    for(int i=1;i<=n;i++)  {

        maxx[i] = max(maxx[i-1],sum1[i]-d[i]);

        ans = max(ans,maxx[i]);

    }



    for(int i=1;i<=n;i++) {

        ans = max(ans,sum1[i]-2*d[i]+mmax[i+1]);

    }

    for(int i=n;i>=1;i--) {

        ans = max(ans,sum2[i]-2*(c-d[i])+maxx[i-1]);

    }



    printf("%lld\n",ans);

    return 0;

}
