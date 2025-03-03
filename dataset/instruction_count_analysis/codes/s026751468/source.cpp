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

typedef long long int ll;

typedef long double ld;

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

const ll MOD=998244353;

const ll MAX_N=500010;

const ll INF=999999999999;

ll frac[MAX_N];

ll ifrac[MAX_N];



ll modpow(ll a, ll n, ll mod){

    ll ret=1;

    while(n>0){

        if(n&1) ret=ret*a%mod;

        a=a*a%mod;

        n>>=1;

    }

    return ret;

}



ll comb(ll n, ll r, ll mod){

    ll res=1;

    res*=frac[n];

    res*=modpow(frac[r],mod-2,mod);

    res%=mod;

    res*=modpow(frac[n-r],mod-2,mod);

    res%=mod;

    return res;

}



int main(){

    ll n,m,k;

    cin>>n>>m>>k;

    ll ans=0;

    frac[0]=frac[1]=1;

    for(int i=2;i<MAX_N;i++){

        frac[i]=frac[i-1]*i%MOD;

    }

    for(ll i=0;i<=k;i++){

        ans+=comb(n-1,i,MOD)*m%MOD*modpow(m-1,n-1-i,MOD)%MOD;

        ans%=MOD;

    }

    cout<<ans<<endl;

}