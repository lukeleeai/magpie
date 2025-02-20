#include <iostream>

#include <algorithm>

using namespace std;



int dp[501][501];

bool field[501][501];



int main() {

    for(int N; cin >> N, N; ) {

        fill(dp[0], dp[501], 0);

        fill(field[0], field[501], 0);

        int W, H; cin >> W >> H;

        while(N--) {

            int X, Y; cin >> X >> Y;

            field[Y][X] = true;

        }

        for(int x = 1; x <= W; x++) {

            for(int y = 1; y <= H; y++) {

                dp[y][x] = dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1] + field[y][x];

            }

        }

        int S, T; cin >> S >> T;

        int res = 0;

        for(int x = S; x <= W; x++) {

            for(int y = T; y <= H; y++) {

                res = max(res, dp[y][x] - dp[y - T][x] - dp[y][x - S] + dp[y - T][x - S]);

            }

        }

        cout << res << endl;

    }

}