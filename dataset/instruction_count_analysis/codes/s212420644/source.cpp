/*** author: yuji9511 ***/

#include "stdc++.h"

using namespace std;

using ll = long long;

using lpair = pair<ll, ll>;

const ll MOD = 998244353;

const ll INF = 1e18;

#define rep(i,m,n) for(ll i=(m);i<(n);i++)

#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)

#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

void print() {}

template <class H,class... T>

void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

ll dp[2][90010] = {};

ll dp2[2][90010] = {};

ll power(ll x, ll n){

    if(n == 0) return 1LL;

    ll res = power(x * x % MOD, n/2);

    if(n % 2 == 1) res = res * x % MOD;

    return res;

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N;

    cin >> N;

    ll a[310];

    rep(i,0,N) cin >> a[i];

    dp[0][0] = 1;

    dp2[0][0] = 1;

    ll sum = 0;

    rep(i,0,N) sum += a[i];

    ll cur = 0, nxt = 1;



    rep(i,0,N){

        rep(j,0,sum + 1){

            dp[nxt][j] = 0;

            dp2[nxt][j] = 0;

            if(j - a[i] >= 0) dp[nxt][j] += dp[cur][j - a[i]];

            if(j - a[i] >= 0) dp2[nxt][j] += dp2[cur][j - a[i]];

            (dp[nxt][j] += 2 * dp[cur][j]) %= MOD;

            (dp2[nxt][j] += dp2[cur][j]) %= MOD;



        }

        cur ^= 1;

        nxt ^= 1;

    }



    ll ans = 0;

    rep(i,(sum+1)/2, sum+1){

        (ans += dp[cur][i]) %= MOD;

    }

    if(sum % 2 == 0){

        ans -= dp2[cur][sum/2];

        ans = (ans + MOD) % MOD;

    }

    ans *= 3;

    ans %= MOD;



    ans = (power(3,N) - ans + MOD) % MOD;

    print(ans);



}