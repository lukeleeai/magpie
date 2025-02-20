#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define chmin(a, b) (a = min(a, b))

const int INF = 1e9 + 10;

int n;
int a[10010];
int dp[2][5010][3];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    fill_n(dp[0][0], 2 * 5010 * 3, INF);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        int s = i & 1;
        int t = s ^ 1;
        fill_n(dp[t][0], 5010 * 3, INF);
        for (int j = 0; j <= n / 2; j++) {
            chmin(dp[t][j + 1][0], dp[s][j][0] + a[i]);
            chmin(dp[t][j][0], dp[s][j][0] + a[i]);
            chmin(dp[t][j + 1][0], dp[s][j][1] + a[i]);
            chmin(dp[t][j][0], dp[s][j][2] + a[i]);
            chmin(dp[t][j + 1][1], dp[s][j][0]);
            chmin(dp[t][j + 1][1], dp[s][j][1]);
            chmin(dp[t][j][2], dp[s][j][0]);
            chmin(dp[t][j][2], dp[s][j][2]);
        }
    }
    cout << dp[n & 1][n / 2][0] << endl;
}
