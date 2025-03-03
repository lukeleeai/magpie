#include "stdc++.h"



using namespace std;



#define int long long



#define rep(i,x) for(int i=0;i<x;++i)

#define all(a) begin(a),end(a)



const int inf = 3e17;



int dp[155][15][100];

int stone[155][15];

int X[155][15];



signed main()

{

    int n, m;

    

    while (cin >> n >> m, n) {

        rep(i, n+5) rep(j, 15) stone[i][j] = inf, X[i][j] = inf;

        rep(i, n+5) rep(j, 15) rep(k, 100) dp[i][j][k] = inf;



        rep(i, n) {

            int k; cin >> k;

            rep(j, k) {

                int x, d; cin >> x >> d;



                X[i][j] = x;



                stone[i][j] = d;

                if (i == 0) dp[0][j][0] = 0;

                if (i == 1) dp[1][j][1] = 0;

            }

        }



        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < 11; ++j) {

                if (stone[i][j] == inf) continue;



                for (int k = 0; k <= m; ++k) {

                    if (k < m) {

                        rep(l, 11) {

                            if (stone[i + 2][l] == inf) continue;



                            dp[i + 2][l][k + 1] = min(

                                    dp[i + 2][l][k + 1],

                                    dp[i][j][k] + (stone[i][j] + stone[i + 2][l]) * abs(X[i][j] - X[i + 2][l])

                                    );

                        }

                    }



                    rep(l, 11) {

                        if (stone[i + 1][l] == inf) continue;



                        dp[i + 1][l][k] = min(

                                dp[i + 1][l][k],

                                dp[i][j][k] + (stone[i][j] + stone[i + 1][l]) * abs(X[i][j] - X[i + 1][l])

                                );

                    }

                }

            }

        }



        int mi = inf;



        for (int i = 0; i < 11; ++i) {

            for (int j = 0; j <= m; ++j) {

                mi = min(mi, dp[n - 1][i][j]);

            }

        }



        for (int i = 0; i < 11; ++i) {

            for (int j = 0; j <= m - 1; ++j) {

                mi = min(mi, dp[n - 2][i][j]);

            }

        }



        cout << mi << endl;

    }

}