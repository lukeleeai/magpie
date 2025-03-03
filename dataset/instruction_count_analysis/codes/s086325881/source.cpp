#include <cstdio>

#include <array>



constexpr int inf = 1e9 + 334 + 810 + 1919;

constexpr int MAX_H = 1e4;

std::array<int, MAX_H + 1> DP;



int readInt(void){

    char c;

    do{c = getchar_unlocked();} while(c < '0');

    int res = 0;

    do{res = 10 * res + c - '0'; c = getchar_unlocked();} while(c >= '0');

    return res;

}



int main(void){

    int H, n; H = readInt(); n = readInt();

    for(int i = 0; i < H; ++i) DP[i] = inf; DP[H] = 0;

    for(int _ = 0; _ < n; ++_){

        int a, b; a = readInt(); b = readInt();

        int i;

        for(i = H; i >= a; --i) if(DP[i - a] > DP[i] + b) DP[i - a] = DP[i] + b;

        for(; i; --i) if(DP[0] > DP[i] + b) DP[0] = DP[i] + b;

    }

    printf("%d\n", DP[0]);

    return 0;

}