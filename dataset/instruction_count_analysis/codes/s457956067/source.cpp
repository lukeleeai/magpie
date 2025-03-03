#include "stdc++.h"

using namespace std;



long long c[26];

long long s[365][26];



int main() {

    int D;

    cin >> D;

    for (int i = 0; i < 26; ++i) cin >> c[i];

    for (int i = 0; i < D; ++i) {

        for (int j = 0; j < 26; ++j) {

            cin >> s[i][j];

        }

    }



    vector<int> LatestProb(26, 0);

    long long score = 0;

    vector<int> res(D);



    for (int d = 0; d < D; ++d) {

        int cd = -1;

        long long cd_delta = -100000000000000LL;

        for (int j = 0; j < 26; ++j) {

            // もしj番目の問題を選んだ時のスコアの増減を計算

            long long delta = s[d][j];

            int latest_prev = LatestProb[j];

            LatestProb[j] = d + 1;

            for (int k = 0; k < 26; ++k) {

                delta -= c[k] * (d + 1 - LatestProb[k]);

            }

            if (cd_delta < delta) {

                cd = j;

                cd_delta = delta;

            }

            // 元に戻す

            LatestProb[j] = latest_prev;

        }

        res[d] = cd;

        LatestProb[cd] = d + 1;

        score += cd_delta;

    }



    for (int ans : res) {

        cout << ans + 1 << endl;

    }

    return 0;

}