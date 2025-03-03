#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<ll, ll> lpair;

const ll MOD = 1e9 + 7;

const ll INF = 1e18;

#define rep(i,m,n) for(ll i = (m); i < (n); i++)

#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)

#define print(x) cout << (x) << endl;

#define print2(x,y) cout << (x) << " " << (y) << endl;

#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll dp[2010][2010] = {};

int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N,M;

    cin >> N >> M;

    ll S[2010], T[2010];

    rep(i,0,N) cin >> S[i];

    rep(i,0,M) cin >> T[i];

    dp[0][0] = 1;

    ll sb[2010], tb[2010];

    memset(sb,-1,sizeof(sb));

    memset(tb,-1,sizeof(tb));

    ll pos[100010] = {};

    memset(pos,-1, sizeof(pos));

    rep(i,0,N){

        if(pos[S[i]] == -1){

            sb[i] = -1;

        }else{

            sb[i] = pos[S[i]];

        }

        pos[S[i]] = i;

    }

    memset(pos,-1, sizeof(pos));

    rep(i,0,M){

        if(pos[T[i]] == -1){

            tb[i] = -1;

        }else{

            tb[i] = pos[T[i]];

        }

        pos[T[i]] = i;

    }

    rep(i,1,N+1){

        dp[i][0] = 1;

    }

    rep(i,1,M+1){

        dp[0][i] = 1;

    }

    rep(i,0,N){

        rep(j,0,M){

            if(S[i] == T[j]){

                dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1]) % MOD;

            }else{

                dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1] - dp[i][j] + MOD) % MOD;

            }

        }

    }

    print(dp[N][M]);





    

    



}