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



signed main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int n; cin >> n;

    int a[100010];

    rep(i, n) cin >> a[i + 1];

    int ans[2] = {};

    rep(j, 2) {

        int sum[100010] = {};

        REP(i, 1, n) {

            sum[i] += sum[i - 1] + a[i];

            if (i % 2 == j && sum[i] >= 0) {

                ans[j] += sum[i] + 1;

                sum[i] -= sum[i] + 1;

            } 

            else if(i % 2 == (j + 1) % 2 && sum[i] <= 0) {

                ans[j] += 1 - sum[i];

                sum[i] += 1 - sum[i];

            }

        }

    }

    cout << min(ans[0], ans[1]) << endl;



    return 0;

}
