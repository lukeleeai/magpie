#include "stdc++.h"

#define LL long long



const int oo = 0x3f3f3f3f;

const int H = 10 + 5;

const int W = 1e3 + 5;



int h, w, k, ans = oo;

char s[H][W];

int state, pre[H][W], cut[W];



int main() {

    scanf("%d %d %d", &h, &w, &k);

    for(int i = 1; i <= h; ++i) scanf("%s", s[i] + 1);

    for(int i = 1; i <= h; ++i)

        for(int j = 1; j <= w; ++j)

            pre[i][j] = pre[i][j - 1] + (s[i][j] - '0');

    for(int state = 0; state < 1 << h ; ++state) {

        // pos[i] = state & (1 << i - 1)

        int finish = 1, last = 0, now = 0, cur = 0;

        for(int j = 1; j <= w; ++j) { // 第 j 列右边切

            for(int i = 1; i <= h; ++i) {

                now += pre[i][j] - pre[i][last];

                if(i == h || state & (1 << i - 1)) { // 第 i 行下面切

                    if(now > k) cut[j - 1] = 1, last = j - 1;

                    now = 0;

                }

            }

        }

        last = now = 0;

        for(int j = 1; j <= w; ++j) if(cut[j]) {

            for(int i = 1; i <= h; ++i) {

                now += pre[i][j] - pre[i][last];

                if(i == h || state & (1 << i - 1)) { // 第 i 行下面切

                    if(now > k) finish = 0;

                    now = 0;

                }

            }

            last = j;

        }

        for(int i = 1; i <= w - 1; ++i) if(cut[i]) cur++, cut[i] = 0;

        if(finish)

          ans = std::min(ans, __builtin_popcountl(state) + cur);

    }

    printf("%d", ans);

    return 0;

}

/*

4 10 4

1110010010

1000101110

0011101001

1101000111



*/
