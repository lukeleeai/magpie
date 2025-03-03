#include"stdc++.h"

using namespace std;

#define ll long long

ll mod(ll n,ll m)

{

    ll ans=1;

    for(ll i=1;i<=n;i++)

    {

        ans=(ans*m)%1000000007;

    }

    return ans;

}

int main()

{

    ll n;cin>>n;

    ll ans=(((mod(n,10)-2*mod(n,9)+mod(n,8))%1000000007)+1000000007)%1000000007;

    cout<<ans<<endl;

    return 0;

}
