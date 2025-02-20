#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define int long long

const int inf = 3e18;
int N, M, K;
int A[20005];
int memo[20005];

signed main() {
    scanf("%lld %lld %lld", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    fill(memo, memo + N + 1, inf);
    memo[N] = 0;

    for (int i = N - 1; i >= 0; --i) {
        int mi = inf, ma = -inf; // Initialize min and max
        for (int j = 0; j < min(N - i, M); ++j) {
            mi = min(mi, A[i + j]); // Update min
            ma = max(ma, A[i + j]); // Update max
            memo[i] = min(memo[i], K + (ma - mi) * (j + 1) + memo[i + j + 1]);
        }
    }
    printf("%lld\n", memo[0]);
}
