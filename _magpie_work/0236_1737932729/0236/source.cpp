#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long n, m, mn;
    long long s[1266], ind, z;
    while (scanf("%lld", &n) && n) {
        m = (n + 1) * n / 2;
        ind = 0;
        mn = 1e100;
        for (int i = 0; i < m; i++) {
            scanf("%lld", &z);
            if (z > (1LL << 62)) while (1);
            if (z % 2 == 0)
                s[ind++] = z;
            else mn = min(mn, z);
        }
        sort(s, s + ind);
        if (ind != n) while (1);
        long long da = sqrt(s[0] * s[1] / mn) + 0.5;
        printf("%lld\n", da);
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%lld", s[i] / da);
        }
        printf("\n");
    }
}
