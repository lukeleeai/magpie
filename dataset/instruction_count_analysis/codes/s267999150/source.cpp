#include "bits/stdc++.h"

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define rrep(i,n) for( int i = n; i >= 0; i-- )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define RREP(i,s,t) for( int i = s; i >= t; i-- )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000

#define int long long

map<int, pair<int, int>> mp;



signed main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int H, W, D;

    cin >> H >> W >> D;

    int A[310][310];

    rep(i, H) rep(j, W) cin >> A[i][j];

    rep(i, H) rep(j, W) {

        mp[A[i][j]] = make_pair(i, j);

    }

    vector<int> sum[100010];

    for(int k = 1; k <= D; k++) {

        int cost = 0;

        sum[k % D].push_back(cost);

        for(int i = k; i + D <= H * W; i += D) {

            cost += abs(mp[i].first - mp[i + D].first);

            cost += abs(mp[i].second - mp[i + D].second);

            sum[k % D].push_back(cost);

        }

    }

    int Q; cin >> Q;

    rep(i, Q) {

        int L, R; cin >> L >> R;

        int m = L % D;

        int step1 = L / D - (L % D == 0);

        int stepN = R / D - (L % D == 0);

        //cout << step1 << " " << stepN << endl;

        //cout << sum[m].size() << endl;

        //rep(j, sum[m].size()) cout << sum[m][j]<< " ";

        cout << sum[m][stepN] - sum[m][step1] << endl;

    }





    return 0;

}
