// cpp219 - the 712534

#include "stdc++.h"

#define ll long long

#define ld long double

#define pb push_back

#define fs first

#define sc second

#define mp make_pair

using namespace std;

const ll base = 7;

const ll N = 2e5 + 9;

const ll mod = 1e9 + 7;

typedef pair<ll,ll> LL;



ll n,k;

ll sum[N],i;



int main(){

    ios_base::sync_with_stdio(false);

   	cin.tie(0); cout.tie(0);

    //freopen("test.inp", "r", stdin);

    cin>>n>>k;

    //fac[1] = fac[0] = 1;

    for (i=1;i<N;i++) sum[i] = sum[i - 1] + i;

    ll ans = 0;

    for (i = k;i <= n + 1;i++){

        ll minsum = sum[i - 1];

        ll maxsum = sum[n] - sum[n - i];

        ans = ans + (maxsum - minsum + 1);

        ans %= mod;

    }

    cout<<ans%mod;

}
