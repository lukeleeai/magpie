#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")



#include <algorithm>

#include <iostream>

#include <vector>



using namespace std;



typedef long long ll;



const int MAX_N = 8;



int dp[1 << (MAX_N - 1)][MAX_N + 1];

int d[MAX_N + 1][MAX_N + 1];



int N, M;



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    cin >> N >> M;



    for (int i = 0; i < M; i++) {

        int a, b;

        cin >> a >> b;

        d[a][b] = 1;

        d[b][a] = 1;

    }



    for (int i = 2; i <= N; i++) {

        dp[0][i] = d[1][i];

    }

    dp[0][1] = 1;



    for (int i = 1; i < (1 << (N - 1)); i++) {

        for (int j = 2; j <= N; j++) {

            int smv = i & (~(1 << (j - 2)));

            dp[i][j] += dp[smv][1] * d[1][j];

            for (int k = 0; k < N - 1; k++) {

                if (((i >> k) & 1) && (i & (1 << (j - 2)))) {

                    dp[i][j] += dp[smv][k + 2] * d[k + 2][j];

                }

            }

        }

    }



    ll ans = 0;



    for (int j = 2; j <= N; j++) {

        ans += dp[(1 << (N - 1)) - 1][j];

    }



    cout << ans << "\n";



    return 0;

}
