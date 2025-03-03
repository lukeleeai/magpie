#include "stdc++.h"



using namespace std;

const int maxn = 1e5 + 6;

using ll = long long;

ll n, a, b;

array<ll, maxn> health;

ll l, r;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    auto check = ([&](auto mid) -> bool {

        ll tot = 0;

        for (int i = 1; i <= n; ++i) {

            ll subDamage = mid * b;

            if (health[i] - subDamage > 0) {

                tot += ceil((double) (health[i] - subDamage) / (a - b)) + 0.1;

            }

        }

        return tot <= mid;

    });

    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i) cin >> health[i];

    l = 1, r = static_cast<ll>(1e9);

    while (l <= r) {

        ll mid = (l + r) >> 1;

        if (check(mid)) {

            r = mid - 1;

        } else {

            l = mid + 1;

        }

    }

    cout << l << "\n";

#ifndef ONLINE_JUDGE

    cout.flush();

#endif

}