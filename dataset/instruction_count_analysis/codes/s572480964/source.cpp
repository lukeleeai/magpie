#include"stdc++.h"

using namespace std;

typedef long long ll;

const ll mod=1e9+7;

int main()

{

    ll n,k;

    cin>>n>>k;

    ll ans=0;

    for(ll i=k;i<=n+1;i++)

    {

        ll l=i*(i-1)/2;

        ll r=(n+n-i+1)*i/2;

        ans=(ans+r-l+1)%mod;

    }

    cout<<ans;

}