#include "stdc++.h"



using namespace std;



const int INF = numeric_limits<int>::max();

const int MAXN = 3e5 + 1;

const int MOD = 1e9 + 7;

const double res = 1e-9;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



signed main() {

#if(DEBUG_LEVEL > 0)

    freopen("../input.txt", "r", stdin);

    freopen("../out.txt", "w", stdout);

#endif

    int n, x;

    cin >> n >> x;

    int now = 0, ans = 1;

    while(n--) {

        int k;

        cin >> k;

        now += k;

        ans += now <= x;

    }

    cout << ans;

    return 0;

}