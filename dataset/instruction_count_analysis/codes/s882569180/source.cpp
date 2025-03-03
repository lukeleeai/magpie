// ?????¬???????????¬??????



#include <iostream>

#include <iomanip>

#include <cstdio>

#include <string>

#include <cstring>

#include <deque>

#include <list>

#include <queue>

#include <stack>

#include <vector>

#include <utility>

#include <algorithm>

#include <map>

#include <set>

#include <complex>

#include <cmath>

#include <limits>

#include <cfloat>

#include <climits>

#include <ctime>

#include <cassert>

#include <numeric>

#include <functional>

using namespace std;



#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)

#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)

#define int long long int



template<typename T> void chmax(T &a, T b) {a = max(a, b);}

template<typename T> void chmin(T &a, T b) {a = min(a, b);}

template<typename T> void chadd(T &a, T b) {a = a + b;}



typedef pair<int, int> pii;

typedef long long ll;



int dx[] = {0, 0, 1, -1};

int dy[] = {1, -1, 0, 0};

constexpr ll INF = 1001001001001001LL;

constexpr ll MOD = 1000000007LL;



// (to, cost)

vector<pii> G[20];

int dp[1 << 15][15];



void solve() {

    int V, E; cin >> V >> E;

    rep(i,0,E) {

        int s, t, d; cin >> s >> t >> d;

        G[s].push_back(pii(t, d));

    }



    rep(i,0,1<<V) rep(j,0,V) dp[i][j] = INF;

    dp[0][0] = 0;

    rep(bit,0,1<<V) rep(i,0,V) {

        for(auto x : G[i]) {

            if(bit >> x.first & 1) continue;

            int nbit = bit | (1 << x.first);

            chmin(dp[nbit][x.first], dp[bit][i] + x.second);

        }

    }

    int ans = (dp[(1<<V)-1][0] == INF ? -1 : dp[(1<<V)-1][0]);

    cout << ans << endl;

}



signed main() {

    solve();

    return 0;

}