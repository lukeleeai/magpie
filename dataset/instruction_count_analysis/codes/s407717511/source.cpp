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





int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int N; cin >> N;

    int A[100010];

    rep(i, N) cin >> A[i];

    vector<int> cnt(N);

    rep(i, N) cnt[i] = -1;

    rep(i, N) {

        auto itr = lower_bound(cnt.begin(), cnt.end(), A[i]);

        itr--;

        *itr = A[i];

        

        //rep(j, N) cout << j << " " << cnt[j] << endl;

    }

    int ans = 0;

    rep(i, N) if (cnt[i] >= 0) ans++;

    cout << ans << endl;



    return 0;

}
