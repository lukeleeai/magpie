#include"stdc++.h"

using namespace std;

typedef long long ll;

#define F first

#define S second

#define pii pair<int, int>

#define eb emplace_back

#define all(v) v.begin(), v.end()

#define rep(i, n) for (int i = 0; i < (n); ++i)

#define rep3(i, l, n) for (int i = l; i < (n); ++i)

#define sz(v) (int)v.size()

#define inf (int)(1e9+7)

#define INF (ll)(1e18)

#define abs(x) (x >= 0 ? x : -(x))

#define ceil(a, b) a / b + !!(a % b)

template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }

template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }













int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    

    

    

    

    /*

     int n;

     cin >> n;

     vector<int> a(n);

     rep(i, n) cin >> a[i];

     */

    

    int table[100005] = {0};

    rep(i, 100005) table[i] = -1;

    table[0] = 1;

    

    rep(i, 6) {

        rep(j, 100000) {

            if (table[j] == -1) continue;

            if (j + 100 + i < 100005) table[j + 100 + i] = 1;

        }

    }

    

    int x;

    cin >> x;

    

    if (table[x] == 1) cout << 1 << endl;

    else cout << 0 << endl;

}
