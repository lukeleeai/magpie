#include <iostream>

#include <complex>

#include <vector>

#include <string>

#include <algorithm>

#include <cstdio>

#include <numeric>

#include <cstring>

#include <ctime>

#include <cstdlib>

#include <set>

#include <map>

#include <unordered_map>

#include <unordered_set>

#include <list>

#include <cmath>

#include <bitset>

#include <cassert>

#include <queue>

#include <stack>

#include <deque>

#include <random>

#include <iomanip>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long int ll;

typedef long double ld;

typedef pair<ll,ll> P;

typedef pair<P,P> PP;

const ll MOD=998244353;

const ll MAX_N=500010;

const ll INF=4999999996000000001;

ll frac[200100];



ll modpow(ll a, ll n, ll mod){

    ll ret=1;

    while(n>0){

        if(n&1) ret=ret*a%mod;

        a=a*a%mod;

        n>>=1;

    }

    return ret;

}



ll comb(ll n, ll r){

    ll res=1;

    res*=frac[n];

    res*=modpow(frac[r],MOD-2,MOD);

    res%=MOD;

    res*=modpow(frac[n-r],MOD-2,MOD);

    res%=MOD;

    return res;

}



int main(){

    frac[0]=1;

    for(int i=1;i<=200010;i++){

        frac[i]=frac[i-1]*i;

        frac[i]%=MOD;

    }

    int n,m,k;

    cin>>n>>m>>k;

    if(m==1){

        if(k==n-1){

            cout<<1<<endl;

        }else{

            cout<<0<<endl;

        }

        return 0;

    }

    ll ans=0;

    ll times=m;

    times*=modpow(m-1,n-1,MOD);

    times%=MOD;

    ans+=times;

    for(ll i=1;i<=k;i++){

        ll type=comb(n-1,i);

        times*=modpow(m-1,MOD-2,MOD);

        times%=MOD;

        ll buf=times*type;

        buf%=MOD;

        ans+=buf;

        ans%=MOD;

    }

    cout<<ans<<endl;

}