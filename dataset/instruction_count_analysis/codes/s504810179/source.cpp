#include "stdc++.h"



using namespace std;



using ll = long long;

using P = pair<ll, ll>;

using edge = pair<ll, P>;

#define rep(i, n) for(ll i=0;i<(ll)(n);i++)

#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)

#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)

using Graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};

const int dy[4] = {0, 1, 0, -1};

const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const ll MOD = 1000000007;

const ll INF = 1000000000000000000L;

#ifdef __DEBUG



#include "cpp-pyprint/pyprint.h"



#endif



ll dp[2005][2005];



void Main() {

    int N, M;

    cin >> N >> M;

    vector<ll> S(N), T(M);

    rep(i, N) cin >> S[i];

    rep(i, M) cin >> T[i];

    rep(i, N) {

        rep(j, M){

            if (S[i] == T[j]) {

                dp[i+1][j+1] += dp[i][j] + 1;

            }

            dp[i+1][j+1] += dp[i+1][j] + dp[i][j+1] - dp[i][j];

            if(dp[i+1][j+1] < 0){

                dp[i+1][j+1] += MOD;

            }

            dp[i+1][j+1] %= MOD;

        }

    }

    cout << dp[N][M] + 1 << endl;

}



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout << fixed << setprecision(15);

    Main();

}
