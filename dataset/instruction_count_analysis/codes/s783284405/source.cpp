// 山登り法しか思いつかない

#include "stdc++.h"

using namespace std;



int D;

int res[365];  // 解答

long long c[26];

long long s[365][26];



long long evaluate() {

    static int LatestProb[26];

    long long score = 0;

    memset(LatestProb, -1, sizeof(LatestProb));

    for (int d = 0; d < D; ++d) {

        score += s[d][res[d]];

        LatestProb[res[d]] = d;

        for (int j = 0; j < 26; ++j) {

            if (LatestProb[j] == -1) continue;

            score -= c[j] * (d - LatestProb[j]);

        }

    }

    return score;

}



int main() {

    cin >> D;

    for (int i = 0; i < 26; ++i) {

        cin >> c[i];

    }

    for (int i = 0; i < D; ++i) {

        for (int j = 0; j < 26; ++j) {

            cin >> s[i][j];

        }

    }



    random_device rnd;                         // 非決定的な乱数生成期を生成

    mt19937 mt(rnd());                         // メルセンヌ・ツイスタの32bit版、引数は初期シード値

    uniform_int_distribution<> rand26(0, 25);  // [0, 25]範囲の一様乱数

    uniform_int_distribution<> rand365(0, 364);



    for (int i = 0; i < D; ++i) {

        res[i] = rand26(mt);

    }

    // 山登り法をして、解を大きくしていく。

    long long score = evaluate();

    int IterationNum = 5000;

    while (IterationNum--) {

        // 二つ変える

        int ch1 = rand365(mt);

        int ch2;

        while ((ch2 = rand365(mt)) == ch1)

            ;

        // どの問題にするか決める

        int ct1 = rand26(mt), ct2 = rand26(mt);

        // 変える前の情報を格納

        int prev1 = res[ch1], prev2 = res[ch2];

        // 変更

        res[ch1] = ct1, res[ch2] = ct2;

        // スコア計算

        long long nxt = evaluate();

        if (score < nxt) {

            score = nxt;

        } else {

            // 元に戻す。

            res[ch1] = prev1, res[ch2] = prev2;

        }

    }



    for (int i = 0; i < D; ++i) {

        cout << res[i] + 1 << endl;

    }

    //cout << "score: " << score << endl;

    return 0;

}