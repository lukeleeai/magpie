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

    int n; cin >> n;

    int a[100010];

    for (int i = 0; i < n; i++) {

        cin >> a[i];

    }

    

    ll ans = INF2;

    for (int k = 0; k < 2; k++) {

        ll tmp = 0;

        ll sum = 0;

        for (int i = 0; i < n; i++) {

            sum += a[i];

            if ((k + i) % 2 == 0 && sum <= 0) {

                tmp += abs(1 - sum);

                sum = 1;

                

            } else if ((k + i) % 2 == 1 && sum >= 0) {

                tmp += abs(-1 - sum);

                sum = -1;

            }

            //cout << sum << " " << tmp << endl;

        }

        //cout << endl;

        ans = min(ans, tmp);

    }

    cout << ans << endl;



    return 0;

}
