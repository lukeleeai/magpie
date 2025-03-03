#include "bits/stdc++.h"

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000





int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    while(true) {

        int N, M;

        cin >> N >> M;

        if (N == 0 && M == 0) return 0;

        vector<int> a(N);

        rep(i, N) cin >> a[i];

        a.push_back(0);

        N++;

        vector<int> aa(N*N);

        rep(i, N) rep(j, N) aa[i*N + j] = a[i] + a[j];

        sort(aa.begin(), aa.end());



        int ans = 0;

        rep(i, N*N) {

            int tmp = aa[i];

            int aim = M - tmp;

            if(aim < 0) continue;

            tmp += *(upper_bound(aa.begin(), aa.end(), aim) - 1);

            if(tmp <= M ) ans = max(ans, tmp);

        }

        cout << ans << endl;

    }



    return 0;

}


