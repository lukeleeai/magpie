#include "stdc++.h"

#include <ext/pb_ds/detail/standard_policies.hpp>

#include <ext/pb_ds/assoc_container.hpp>



using namespace std;

using namespace __gnu_pbds;



template<typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



template<typename T>

using normal_queue = priority_queue<T, vector<T>, greater<T>>;



#define int long long



bool check(int x, int n, vector<int>& a) {

    int cnt = 0, nw = 0;

    ordered_set<pair<int, int>> c;

    c.insert({0, 0});

    for (int i = 0; i < n; ++i) {

        if (a[i] >= x) {

            nw++;

        } else {

            nw--;

        }

        cnt += c.order_of_key({nw, n + 10});

        c.insert({nw, i + 1});

    }

    return cnt >= (n * (n + 1) / 2 + 1) / 2;

}



void solve() {

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {

        cin >> a[i];

    }

    int l = -1, r = 1e9 + 10;

    while (r - l > 1) {

        //cout << l << " " << r << " >\n";

        int m = (l + r) / 2;

        if (check(m, n, a)) {

            l = m;

        } else {

            r = m;

        }

    }

    cout << l << "\n";

}



signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;

}


