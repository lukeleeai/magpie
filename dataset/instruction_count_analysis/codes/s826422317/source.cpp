#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

using namespace std;

typedef long long ll;

const ll mod=998244353;

ll n,m,ny[1100000],jc[1100000];

ll c(ll n,ll m)

{

    return (ll)jc[n]*ny[m]%mod*ny[n-m]%mod;

}

 

int main()

{

    cin>>n>>m;

    if(n<=m)swap(n,m);

    jc[0]=jc[1]=ny[0]=ny[1]=1;

    for(int i=2;i<=n+m;i++)jc[i]=(ll)jc[i-1]*i%mod,ny[i]=(ll)(mod-mod/i)*ny[mod%i]%mod;

    for(int i=2;i<=n+m;i++)ny[i]=(ll)ny[i-1]*ny[i]%mod;

    ll ans=0;

    for(int i=1;i<=m;i++)

    {

        ans+=(ll)c(n+m-i*2,n-i)%mod*c(i*2,i)%mod;

        ans%=mod;

    }

    ans=(ll)ans*ny[n+m]%mod*jc[n]%mod*jc[m]%mod*ny[2]%mod;

    ans+=n;

    ans%=mod;

     

    cout<<ans<<endl;

}
