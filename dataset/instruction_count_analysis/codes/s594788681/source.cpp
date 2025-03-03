#include <iostream>

#include <fstream>

#include <set>

#include <map>

#include <string>

#include <vector>

#include <queue>

#include <deque>

#include <stack>

#include <functional>

#include <algorithm>

#include <climits>

#include <cmath>

#include <iomanip>

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





int sum[100010];

pair<int, int> p[100010];



int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int H, W, D;

    cin >> H >> W >> D;

    int A[310][310];

    rep(i, H) {

        rep(j, W)  {

            cin >> A[i][j];

            p[A[i][j]] = {i, j};

        }

    }

    rep(i, D) {

        for(int j = i + 1; j <= H * W - D; j += D) {

            int x1 = p[j + D].first;

            int y1 = p[j + D].second;

            int x2 = p[j].first;

            int y2 = p[j].second;

            int add = abs(x1 - x2) + abs(y1 - y2);

            sum[j + D] = sum[j] + add;

        }

    }

    //rep(i, H * W + 1) cout << i << " " << sum[i] << endl;

    int Q; cin >> Q;

    while(Q--) {

        int L, R;

        cin >> L >> R;

        cout << sum[R] - sum[L] << endl;

    }

    





    return 0;

}
