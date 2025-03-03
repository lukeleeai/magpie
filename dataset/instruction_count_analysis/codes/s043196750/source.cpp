#include <cstdint>

#include <cstdio>

using namespace std;

#define rep(i, n) for (register uint_fast32_t i = 0; i < (n); ++i)

inline char tc() {

    static char fl[100], *A = fl, *B = fl;

    return A == B && (B = (A = fl) + fread(fl, 1, 100, stdin), A == B) ? EOF

                                                                       : *A++;

}

inline uint_fast32_t read() {

    uint_fast32_t a = 0;

    static char c;

    c = tc();

    while (c & 16) a = a * 10 + c - 48, c = tc();

    return a;

}

uint_fast32_t h[100001], n, a, b, left, right;

int_fast64_t temp, cnt, mid;

double a_;

int main() {

    n = read(), a = read(), b = read();

    a -= b;

    a_             = 1.0 / a;

    rep(i, n) h[i] = read();

    left = 0, right = 1000000000;

    cnt = 0;

    while (right > left + 1) {

        mid = (right + left) >> 1;

        cnt = 0;

        rep(i, n) {

            temp = h[i] - b * mid + a - 1;

            if (temp > 0) cnt += temp * a_;

        }

        if (cnt <= mid)

            right = mid;

        else

            left = mid;

    }

    printf("%u\n", right);

}