#include "stdc++.h"

using namespace std;

using Int = long long;

constexpr Int MOD = 1e9 + 7;

Int dp[2001][2001];

int main()

{

    int N, M; cin >> N >> M;

    vector<int> S(N), T(M);

    for (auto &s : S) cin >> s;

    for (auto &t : T) cin >> t;

    map<int, vector<int>> MT;

    for (int i = 0; i < M; i++) {

        MT[T[i]].push_back(i+1);

    }

    for (int i = 0; i <= 2000; i++) {

        dp[0][i] = dp[i][0] = 1;

    }

    for (int i = 1; i <= N; i++) {

        map<pair<int, int>, int> memo;

        for (int j = 1; j <= M; j++) {

            dp[i][j] = dp[i-1][j];

            auto &v = MT[S[i-1]];

            int k = upper_bound(begin(v), end(v), j) - begin(v);

            if (k != 0) {

                Int val = (memo[make_pair(S[i-1], k-1)] + dp[i-1][v[k-1]-1]) % MOD;

                memo[make_pair(S[i-1], k)] = val;

                (dp[i][j] += val) %= MOD;

            }

        }

    }

    cout << dp[N][M] << '\n';

    return 0;

}
