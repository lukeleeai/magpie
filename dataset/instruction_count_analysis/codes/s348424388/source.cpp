#include <iostream>

#include <algorithm>

using namespace std;



inline void fastin(int &num) {

    int c;

    num = 0;

    c = getchar_unlocked();

    for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num<<3) + (num<<1) + c - 48;

}



inline void fastout(int n) {

    int N = n, rev, count = 0;

    rev = N;

    if (N == 0) { putchar_unlocked('0'); putchar_unlocked('\n'); return ;}

    while ((rev % 10) == 0) { ++count; rev /= 10;}

    rev = 0;

    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}

    while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}

    while (count--) putchar_unlocked('0');

}



int main(){    

    int n, c; fastin(n); fastin(c);

    int D[40][40];

    int C[510][510];



    for (int i = 0; i < c; ++i){

        for (int j = 0; j < c; ++j) fastin(D[i][j]);

    }



    for (int i = 0; i < n; ++i){

        for (int j = 0; j < n; ++j) fastin(C[i][j]);

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



    fastout(ans);

    

    return 0;

}
