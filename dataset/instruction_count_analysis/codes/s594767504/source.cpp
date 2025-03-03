#include <stdio.h>

#include <array>



constexpr int N = 8;

constexpr int inf = 2e9;

std::array<int, N> A;



int main(void){

    int n, a, b, c; scanf("%d%d%d%d", &n, &a, &b, &c);

    for(int i = 0; i < n; ++i) scanf("%d", &A[i]);

    int N = (1 << n) << n;

    int res = inf;

    for(int i = 0; i < N; ++i){

        int val = i;

        int aa = 0, cna = 0,

            bb = 0, cnb = 0,

            cc = 0, cnc = 0;

        for(int j = 0; j < n; ++j){

            int d = val & 3; val >>= 2;

            switch(d){

                case 1: aa += A[j]; cna++; break;

                case 2: bb += A[j]; cnb++; break;

                case 3: cc += A[j]; cnc++; break;

            }

        }

        if(cna == 0 or cnb == 0 or cnc == 0) continue;

        int cost = (a > aa ? a - aa : aa - a) + (b > bb ? b - bb : bb - b) + (c > cc ? c - cc : cc - c);

        cost += 10 * (cna + cnb + cnc - 3);

        if(cost < res) res = cost;

    }

    printf("%d\n", res);

    return 0;

}