#include <stdio.h>

#include <algorithm>



inline int getint(void){

    int res = 0, c; while((c = getchar_unlocked() - '0') >= 0) res = 10 * res + c;

    return res;

}



char S[10];

inline void putint(int x){

    int idx = 0; do { S[idx++] = (x % 10) ^ '0'; x /= 10; } while(x);

    while(idx--) putchar_unlocked(S[idx]);

    putchar('\n');

}



int n;



constexpr int MAX_Q = 500'000;

int indices[MAX_Q];

int L[MAX_Q], R[MAX_Q], res[MAX_Q];



constexpr int MAX_N = 500'000;

int A[MAX_N];

int data[MAX_N + 1];

int LAST[MAX_N + 1];



inline void erase(int idx){ for(; idx <= n; idx += idx & -idx) --data[idx]; }

inline void add(int idx){ for(; idx <= n; idx += idx & -idx) ++data[idx]; }

inline int  sum(int idx){ int res = 0; for(; idx; idx -= idx & -idx) res += data[idx]; return res; }





int main(void){

    n = getint();

    const int q = getint();

    for(int i = 0; i < n; ++i) A[i] = getint();

    for(int i = 0; i < q; ++i) L[i] = getint() - 1, R[i] = getint();

    for(int i = 0; i < q; ++i) indices[i] = i;

    std::sort(indices, indices + q, [](const int x, const int y){

        if(R[x] != R[y]) return R[x] < R[y];

        return x < y;

    });

    for(int i = 1, cnt = 0, idx = 0; i <= n; ++i){

        const int color = A[i - 1];

        if(LAST[color]) erase(LAST[color]); else ++cnt;

        LAST[color] = i; add(i);

        while(idx < q and R[indices[idx]] == i){ 

            res[indices[idx]] = cnt - sum(L[indices[idx]]); ++idx; 

            

        }

    }



    for(int i = 0; i < q; ++i) putint(res[i]);



    return 0;

}