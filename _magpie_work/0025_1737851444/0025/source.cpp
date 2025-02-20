#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n;
long long a[maxn], b[maxn];

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long cur = a[i] + ans;
        long long tar = (cur + b[i] - 1) / b[i] * b[i];
        ans += tar - cur;
    }
    printf("%lld\n", ans);
    return 0;
}
