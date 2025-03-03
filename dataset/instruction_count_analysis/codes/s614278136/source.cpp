#include "stdc++.h"

using namespace std;



void solve() {

    string X, Y;

    cin >> X >> Y;

    vector<vector<int>> dp(X.size() + 1, vector<int>(Y.size() + 1));

    for (int i = 0; i < X.size(); ++i) {

        for(int j = 0; j < Y.size(); ++j) {

            if (X[i] == Y[j]) {

                dp[i + 1][j + 1] = dp[i][j] + 1;

            } else {

                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

            }

        }

    }

    cout << dp[X.size()][Y.size()] << endl;

}



int main() {

    int q;

    cin >> q;

    for (int i = 0; i < q; ++i) {

        solve();

    }

}
