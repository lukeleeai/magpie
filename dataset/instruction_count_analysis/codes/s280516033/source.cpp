#include "stdc++.h"



using namespace std;

typedef long long ll;



int main() {

    int H, W, K;

    const int mod = 1e9 + 7;

    cin >> H >> W >> K;



    vector<vector<ll>> c(3, vector<ll>(W));

    for (int i = 0; i < 1 << (W - 1); i++) {

        if (i & (i >> 1)) continue;

        for (int j = 0; j < W; j++) {

            if (i >> j & 1) {

                c[2][j]++;

            } else if (j >= 1 && i >> (j - 1) & 1) {

                c[0][j]++;

            } else {

                c[1][j]++;

            }

        }

    }



    vector<vector<ll>> dp(H + 1, vector<ll>(W));

    dp[0][0] = 1;

    for (int i = 1; i <= H; i++) {

        for (int j = 0; j < W; j++) {

            for (int k = 0; k < 3; k++) {

                if (j + k - 1 < 0 || j + k - 1 >= W) continue;

                dp[i][j] += c[k][j] * dp[i - 1][j + k - 1];

                dp[i][j] %= mod;

            }

        }

    }

    

    cout << dp[H][K - 1] << endl;

    return 0;

}