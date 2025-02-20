#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 300;

int main() {
    int S, D, M;
    while (scanf("%d%d%d", &S, &D, &M) == 3) {
        vector<vector<int>> dp(S, vector<int>(MAX + 1, 0));
        for (int i = 0; i < S; ++i) {
            int K;
            scanf("%d", &K);
            while (K--) {
                int w, p;
                scanf("%d%d", &w, &p);
                for (int y = MAX; y >= p; --y) {
                    dp[i][y] = max(dp[i][y], dp[i][y - p] + w);
                }
            }
        }

        vector<int> ans(MAX + 1, 0);
        for (int i = 0; i < D; ++i) {
            int f;
            scanf("%d", &f);
            for (int j = MAX; j >= 0; --j) {
                for (int k = 0; k <= j; ++k) {
                    ans[j] = max(ans[j], ans[j - k] + dp[f][k]);
                }
            }
        }

        while (M > 0 && ans[M] == ans[M - 1]) M--;
        printf("%d %d\n", ans[M], M);
    }
    return 0;
}
