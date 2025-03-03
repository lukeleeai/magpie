#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXD = 12;



struct Prob {

    int score, p, c;

} P[MAXD];



int main() {

    int D, G, ans = 0;

    scanf("%d %d", &D, &G);

    for (int i = 0; i < D; i++) {

        scanf("%d %d", &P[i].p, &P[i].c);

        P[i].score = 100 * (i + 1);

        ans += P[i].p;

    }



    for (int s = 0; s < 1 << D; s++) {

        int sum = 0, cnt = 0, restMax = -1;



        for (int i = 0; i < D; i++) {

            if (s & (1 << i)) {

                sum += P[i].score * P[i].p + P[i].c;

                cnt += P[i].p;

            } else {

                restMax = i;

            }

        }



        if (sum < G) {

            int need = (G + P[restMax].score - 1 - sum) / P[restMax].score;

            if (need > P[restMax].p) continue;

            cnt += need;

        }



        ans = min(ans, cnt);

    }



    printf("%d\n", ans);



    return 0;

}
