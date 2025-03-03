#include "stdc++.h"



int main() {

    for(;;) {

        int n;

        std::cin >> n;

        if (n == 0) {

            break;

        }

        std::vector<int> xs(n);

        for(int i = 0; i < n; ++i) {

            std::cin >> xs[i];

        }

        int dp[310][310] = {{}};

        for(int w = 2; w <= n; ++w) {

            for(int l = 0; l <= n-w; ++l) {

                int r = l + w;

                // sep

                for(int k = l+1; k < r; ++k) {

                    dp[l][r] = std::max(dp[l][r], dp[l][k] + dp[k][r]);

                }

                // 2

                if (std::abs(xs[l] - xs[r-1]) <= 1 && dp[l+1][r-1] == r-l-2) {

                    dp[l][r] = std::max(dp[l][r], dp[l+1][r-1] + 2);

                }

            }

        }

        printf("%d\n", dp[0][n]);

    }

}


