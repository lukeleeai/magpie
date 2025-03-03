#include "stdc++.h"



using namespace std;



int dp[1010][1010];



int main(void) {

    int q;

    string x, y;

    cin >> q;



    while (cin >> x >> y) {

        memset(dp, 0, sizeof dp);



        int xs = x.size(), ys = y.size();

        for (int i = 1; i <= xs; i++)

            for (int j = 1; j <= ys; j++) {

                if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;

                else dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));

            }

            

        cout << dp[xs][ys] << endl;

    }



    return 0;

}
