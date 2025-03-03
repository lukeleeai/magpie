#include <vector>

#include <stack>

#include <queue>

#include <list>

#include <bitset>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <algorithm>

#include <numeric>

#include <iostream>

#include <iomanip>

#include <string>

#include <chrono>

#include <random>

#include <cmath>

#include <cassert>

#include <climits>

#include <cstring>

#include <cstdlib>

#include <functional>

#include <sstream>



using namespace std;



class Solution {

public:

    int solve(int n, int K) {

        const long long MOD = 1000000007;



        int N = n * n * 2;

        vector<vector<long long>> dp(n, vector<long long>(N + N + 1, 0));

        dp[0][N] = 1;

        auto ndp = dp;

        for (int i = 1; i <= n; ++i) {

            for (auto& V : ndp) {

                fill(V.begin(), V.end(), 0);

            }

            for (int j = 0; j < i; ++j) {

                for (int k = 0; k <= N * 2; ++k) {

                    if (j > 0) {

                        int nj = j - 1;

                        int nk = k + i + i;

                        if (nk <= 2 * N) {

                            (ndp[nj][nk] += dp[j][k] * j % MOD * j % MOD) %= MOD;

                        }



                        nj = j;

                        nk = k;

                        (ndp[nj][nk] += dp[j][k] * 2 * j % MOD) %= MOD;

                    }



                    (ndp[j][k] += dp[j][k]) %= MOD;



                    {

                        int nj = j + 1;

                        int nk = k - 2 * i;

                        if (nj < n && nk >= 0) {

                            (ndp[nj][nk] += dp[j][k]) %= MOD;

                        }

                    }                    

                }

            }

            swap(ndp, dp);

        }



        return dp[0][N + K];

    }



    int test (int n, int k) {

        vector<int> P(n, 0);

        iota(P.begin(), P.end(), 1);



        int res = 0;

        do {

            int sum = 0;

            for (int i = 0; i < n; ++i) {

                sum += abs(P[i] - i - 1);

            }

            if (sum == k) {

                ++res;

                for (int i = 0; i < n; ++i) {

                    cout << (i + 1) << ":" << P[i] << " ";

                }

                cout << endl;

            }

        } while (next_permutation(P.begin(), P.end()));

        return res;

    }

};



int main(int argc, char** argv) {

    ios::sync_with_stdio(false);

    cin.tie(0);



    int n;

    cin >> n;

    int k;

    cin >> k;

    Solution sol;

    cout << sol.solve(n, k) << "\n";



    return 0;

}