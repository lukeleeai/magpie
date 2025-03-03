#include"stdc++.h"

using namespace std;

#define ll long long

const ll mod=1e9+7;

const int maxn=2e5+10;

ll inv[maxn];

ll fac[maxn];

ll power(ll base,ll n)

{

    ll r=1;

    while(n)

    {

        if(n&1) r=r*base%mod;

        base=base*base%mod;

        n/=2;

    }

    return r;

}

void init()

{

    fac[0]=1;

    for(int i=1;i<=2e5;i++)

    {

        fac[i]=fac[i-1]*i%mod;

    }

    inv[200000]=power(fac[200000],mod-2);

    for(int i=2e5;i>=1;i--)

    {

        inv[i-1]=inv[i]*i%mod;

    }

}

ll C(ll m,ll n)

{

    return fac[n]*inv[m]%mod*inv[n-m]%mod;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n,k;

    cin>>n>>k;

    init();





    int red=n-k;

    for(int i=1;i<=k;i++)

    {

        if(i>red+1)

        {

            cout<<0<<'\n';

            continue;

        }

        int ans=(C(i,red+1)*C(i-1,k-1))%mod;

        cout<<ans<<'\n';

    }





}
