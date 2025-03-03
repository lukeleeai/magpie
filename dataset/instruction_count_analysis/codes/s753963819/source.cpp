#include "stdc++.h"

#define rep(i, m, n) for(int i = m; i < (n); i++)

#define rrep(i,m,n) for(int i = m; i >= n; i--)

#define print(x) cout << (x) << endl;

#define print2(x,y) cout << (x) << " " << (y) << endl;

#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;

#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}

#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;

#define INF (1e18)

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

typedef struct{

    ll to;

    ll cost;

} edge;

typedef pair<ll, ll> lpair;

ll dp[110][100010] = {};



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N,K;

    cin >> N >> K;

    ll a[110];

    rep(i,0,N){

        cin >> a[i];

    }

    dp[0][0] = 1;

    rep(i,0,N){

        ll sum[100010] = {};

        rep(j,0,100001){

            sum[j+1] = (sum[j]+dp[i][j]) % MOD;

            sum[j+1] %= MOD;

        }

        rep(j,0,K+1){

            ll min_val = max(0LL,j-a[i]);

            dp[i+1][j] += (sum[j+1] - sum[min_val] + MOD) % MOD;

            dp[i+1][j] %= MOD;

        }

    }

    print(dp[N][K]);





}
