#include "stdc++.h"

#ifndef ONLINE_JUDGE

#define debug(x) cout << #x << ": " << x << endl

#else

#define debug(x)

#endif

using namespace std;

typedef long long ll;

const int maxn=2e5+7;

const int inf=0x3f3f3f3f;

const int mod=1e9+7;



int a[maxn];

ll sum[maxn];



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    ll n,m,v,p;

    cin>>n>>m>>v>>p;

    for(int i=1;i<=n;++i) cin>>a[i];

    sort(a+1,a+1+n);

    for(int i=1;i<=n;++i)

        sum[i]=sum[i-1]+a[i];

    int ans=p;

    for(int i=n-p;i>=1;--i)

    {

        if(a[i]+m<a[n-p+1]) break;

        else

        {

            if( m*v<=i*m+(p-1)*m+(a[i]+m)*(n-p+1-i)-(sum[n-p+1]-sum[i]) )

                ans++;

            else break;

        }

    }

    cout<<ans<<endl;

    return 0;

}
