#include<iostream>

#include<algorithm>

#include<vector>

#include<queue>

#define lol(i,n) for(int i=0;i<n;i++)

#define mod 1000000007

typedef long long ll;

using namespace std;

#define N 100010

ll n,a[N];

ll f[N],g[N];

ll val[N],cs[N];

int main(){

    cin>>n;

    lol(i,n)cin>>a[i];

    f[0]=1;

    for(ll i=1;i<=n;i++)f[i]=f[i-1]*i%mod;

    g[n+1]=1;

    for(ll i=n;i>=1;i--)g[i]=g[i+1]*i%mod;

    for(ll i=2;i<=n;i++){

	val[i]=f[i-1]*g[i+1]%mod;

    }

    val[1]=g[2];

    cs[0]=cs[1]=0;

    for(ll i=2;i<=n;i++)cs[i]=(cs[i-1]+val[i])%mod;

    ll ans=0;

    lol(i,n){

	ll cur=cs[i+1]+cs[n-i]+val[1];

	ans=(ans+cur*a[i])%mod;

    }

    return cout<<ans<<endl,0;

}
