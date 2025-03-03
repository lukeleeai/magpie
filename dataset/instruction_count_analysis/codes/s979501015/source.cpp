#include "stdc++.h"

using namespace std;



#define REP(i,n) for(ll i=0; i<(ll)(n); i++)

#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)

#define pb push_back

#define INF 1000000007LL

#define all(a) (a).begin(),(a).end()

#define chmin(a,b) a=min(a,b)

#define chmax(a,b) a=max(a,b)



typedef long long ll;

typedef pair<int,int> p;



int dy[4]={-1,1,0,0};

int dx[4]={0,0,1,-1};



int N, Z, W;

int a[2010];



int dp[2][2010];

int main(){

    ios::sync_with_stdio(false);

    cin >> N >> Z >> W;

    REP(i, N) cin >> a[i];

    function<int(int, bool, int, int)> score = [&](int used, int turn, int x, int y) {

        if (used == N) return abs(x - y);

        if (turn) {

            if (dp[turn][used] != -1) return dp[turn][used];

            int res = INF;

            FOR(i, used + 1, N+1) {

                res = min(res, score(i, turn^1, x, a[i-1]));

            }

            return dp[turn][used] = res;

        } else {

            if (dp[turn][used] != -1) return dp[turn][used];

            int res = 0;

            FOR(i, used + 1, N+1) {

                res = max(res, score(i, turn^1, a[i-1], y));

            }

            return dp[turn][used] = res;

        }

    };

    REP(i, 2010) {dp[0][i] = -1; dp[1][i] = -1;}

    cout << score(0, 0, Z, W) << endl;;

    

    return 0;

}


