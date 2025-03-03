#include "stdc++.h"

using namespace std;



int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    int n, w;

    cin >> n >> w;

    vector<int> we(n), v(n);

    for (int i = 0; i < n; ++i) cin >> we[i] >> v[i];

    vector<long long> dp(w + 1, 0);

    for (int i = 0; i < n; ++i)

        for (int weight = w - we[i]; weight >= 0; --weight)

            dp[weight + we[i]] = max(dp[weight + we[i]], dp[weight] + v[i]);

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;

}


