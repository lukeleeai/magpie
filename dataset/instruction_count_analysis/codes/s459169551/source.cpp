#include <stdio.h>



#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))



constexpr int N = 2e5;

char S[N+10], T[N+10];



int main(void){

    int H, W, n; scanf("%d%d%d", &H, &W, &n);

    int sx, sy; scanf("%d%d", &sx, &sy); sx--; sy--;

    scanf("%s%s", S, T);



    // (l, r) は ok

    int l = -1, r = W, u = -1, d = H;

    rREP(i, n){

        // 落とされないようにする

        switch(T[i]){

            case 'L':

                if(r != W) r++;

                break;

            case 'R':

                if(l != -1) l--;

                break;

            case 'U':

                if(d != H) d++;

                break;

            case 'D':

                if(u != -1) u--;

                break;

        }

        

        // 落とすようにする

        switch(S[i]){

            case 'L':

                l++;

                break;

            case 'R':

                r--;

                break;

            case 'U':

                u++;

                break;

            case 'D':

                d--;

                break;

        }

        // 空となるなる場合があるときはダメ

        if(r - l - 1 <= 0 or d - u - 1 <= 0) break;

    }

    puts((l < sy and sy < r and u < sx and sx < d) ? "YES" : "NO");

    return 0;

}