#include <iostream>

#include <algorithm>

using namespace std;

using int64 = int64_t;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#define print(x) cout << (x) << '\n'



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    

    int n, c; cin >> n >> c;

    int64 D[40][40] = {};

    int64 C[510][510] = {};



    rep(i, c){

        rep(j, c) cin >> D[i][j];

    }



    rep(i, n){

        rep(j, n) cin >> C[i][j];

    }



    int sum0[40] = {}, sum1[40] = {}, sum2[40] = {};



    for (int i = 1; i <= c; ++i){

        for (int j = 0; j < n; ++j){

            for (int k = 0; k < n; ++k){

                if ((j + k) % 3 == 0){

                    sum0[i] += D[C[j][k] - 1][i - 1];

                }

                else if ((j + k) % 3 == 1){

                    sum1[i] += D[C[j][k] - 1][i - 1];

                }

                else if ((j + k) % 3 == 2){

                    sum2[i] += D[C[j][k] - 1][i - 1];

                }

            }

        }

    }



    int ans = 1e9;



    for (int i = 1; i <= c; ++i){

        for (int j = 1; j <= c; ++j){

            for (int k = 1; k <= c; ++k){

                if (i != j && j != k && k != i){

                    ans = min(ans, sum0[i] + sum1[j] + sum2[k]);

                }

            }

        }

    }



    print(ans);

    

    return 0;

}
