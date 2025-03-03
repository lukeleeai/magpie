/*** author: yuji9511 ***/

#include "stdc++.h"

using namespace std;

using ll = long long;

using lpair = pair<ll, ll>;

const ll MOD = 1e9+7;

const ll INF = 1e18;

#define rep(i,m,n) for(ll i=(m);i<(n);i++)

#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)

#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

void print() {}

template <class H,class... T>

void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

ll dp[2][100010] = {};

int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N,K;

    cin >> N >> K;

    ll a[110];

    rep(i,0,N) cin >> a[i];

    dp[0][0] = 1;

    ll cur = 0, nxt = 1;

    rep(i,0,N){

        rep(j,0,K+1) dp[nxt][j] = 0;

        rrep(j,K,0){

            dp[nxt][j] += dp[cur][j];

            dp[nxt][j] %= MOD;

            if(j + a[i] + 1 <= K+1) dp[nxt][j+a[i]+1] = (dp[nxt][j+a[i]+1] - dp[cur][j] + MOD) % MOD;

        }

        rep(j,0,K+1) (dp[nxt][j+1] += dp[nxt][j]) %= MOD;

        nxt ^= 1; cur ^= 1;

    }

    print(dp[cur][K]);

    



}
