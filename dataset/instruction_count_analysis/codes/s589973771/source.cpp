#include "stdc++.h"

using namespace std;



const long long inf = (long long) 1e9 * 100 + 5;

const int maxn = 105, maxm = (int) 1e5 + 5;

long long dp[maxn][maxm] = {0};

bool vis[maxn][maxm];

int n, w;

int we[maxn];

long long v[maxn];



long long solve(int i, int weight) {

    if (i == n) return 0;

    if (vis[i][weight]) return dp[i][weight];

    long long ans = solve(i + 1, weight);

    if (weight + we[i] <= w) ans = max(ans, solve(i + 1, weight + we[i]) + v[i]);

    vis[i][weight] = true;

    return dp[i][weight] = ans;

}

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w;

    for (int i = 0; i < n; ++i) cin >> we[i] >> v[i];

    memset(vis, false, sizeof(vis));

    cout << solve(0, 0) << '\n';

    return 0;

}


