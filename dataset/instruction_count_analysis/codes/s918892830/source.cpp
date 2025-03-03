#include "stdc++.h"

using namespace std;

#define rep(i, m, n) for (int i = m; i < n; ++i)



bool solve() {

    string S;

    int x, y;

    cin >> S >> x >> y;

    vector<vector<int>> C(2);

    int cnt = 0;

    rep(l, 0, S.size()) {

        int r = l;

        while(r < S.size() && S[r] == 'F') r++;

        C[(cnt++) % 2].push_back(r - l);

        l = r;

    }

    int N = C[0].size();

    int M = C[1].size();

    vector<vector<int>> dp(N + 1, vector<int>(16001));

    vector<vector<int>> ep(M + 1, vector<int>(16001));

    int g = 8000;

    dp[1][C[0][0] + g] = 1;

    rep(i, 1, N) rep(j, -8000, 8001) {

        if(dp[i][j + g] == 0) continue;

        dp[i + 1][j + C[0][i] + g] = 1;

        dp[i + 1][j - C[0][i] + g] = 1;

    }

    ep[0][g] = 1;

    rep(i, 0, M) rep(j, -8000, 8001) {

        if(ep[i][j + g] == 0) continue;

        ep[i + 1][j + C[1][i] + g] = 1;

        ep[i + 1][j - C[1][i] + g] = 1;

    }

    return dp[N][x + g] && ep[M][y + g];

}



int main() {

    cout << (solve() ? "Yes" : "No") << '\n';

    return 0;

}
